#include <string.h>
#include <stdio.h>
#include <unistd.h>

struct list { /* format for the header, loosely based on K&R's Header struct from page 187 */
    struct list *prev; /* last block */
    struct list *next; /* next block */
    size_t size; /* size of the block */
};

struct table { /* free list table */
    struct list *five;
    struct list *six;
    struct list *seven;
    struct list *eight;
    struct list *nine;
    struct list *ten;
    struct list *eleven;
    struct list *twelve;
};

static struct table *freetable = NULL;

static int sizeoftable = sizeof(struct table);

#define CHUNK_SIZE (1<<12)

extern void *bulk_alloc(size_t size);

extern void bulk_free(void *ptr, size_t size);

static inline __attribute__((unused)) int block_index(size_t x) {
    if (x <= 8) {
        return 5;
    } else {
        return 32 - __builtin_clz((unsigned int)x + 7);
    }
}

static size_t adjust(size_t size){
    int pow = block_index(size);
    int adjusted = 1<<pow;
    return adjusted;
}

static struct list* findList(size_t size){ /* Finds and returns what pool a pointer belongs to given size */
    if (size == 5){
        return freetable -> five;
    }
    else if (size == 6){
        return freetable -> six;
    }
    else if (size == 7){
        return freetable -> seven;
    }
    else if (size == 8){
        return freetable -> eight;
    }
    else if (size == 9){
        return freetable -> nine;
    }
    else if (size == 10){
        return freetable -> ten;
    }
    else if (size == 11){
        return freetable -> eleven;
    }
    else if (size == 12){
        return freetable -> twelve;
    }
    return NULL;
}

static void expand(size_t adjusted, struct list *freelist){
    int loopCount = (CHUNK_SIZE)/(adjusted);
    int index = block_index(adjusted - 8);
    struct list *pointer = sbrk(CHUNK_SIZE), *original, *old;
    
    for (int i = 0; i != loopCount; i++){
        if(adjusted == 4096){
            if (freelist == NULL){
                freelist = pointer;
            }
            
            freelist -> next = sbrk(4096);
            freelist -> next -> next = NULL;

            freelist -> prev = NULL;
            freelist -> next -> prev = freelist;
            
            freelist -> size = 0;
            freelist -> next -> size = 0;

            break;
        }
        
        if (freelist == NULL){
            freelist = pointer;
            original = freelist;

            freelist -> prev = NULL;
            freelist -> size = 0;
            
            old = freelist;
            
            pointer = (void *)pointer + adjusted;
        }

        else {
            freelist -> next = pointer;
            freelist = freelist -> next;
            freelist = pointer;

            freelist -> prev = old;
            freelist -> size = 0;

            old = freelist;
            
            pointer = (void *)pointer + adjusted;
        }
    }

    if (index == 5){
        freelist = original;
        freetable -> five = freelist;
    }
    else if (index == 6){
        freelist = original;
        freetable -> six = freelist;
    }
    else if (index == 7){
        freelist = original;
        freetable -> seven = freelist;
    }
    else if (index == 8){
        freelist = original;
        freetable -> eight = freelist;
    }
    else if (index == 9){
        freelist = original;
        freetable -> nine = freelist;
    }
    else if (index == 10){
        freelist = original;
        freetable -> ten = freelist;
    }
    else if (index == 11){
        freelist = original;
        freetable -> eleven = freelist;
    }
    else if (index == 12){
        freetable -> twelve = freelist;
    }
}

static void update(size_t size, struct list *updatedList){ /* Updates the head of the free list pool */
    if (size == 5){
        freetable -> five = updatedList;
    }
    else if (size == 6){
        freetable -> six = updatedList;
    }
    else if (size == 7){
        freetable -> seven = updatedList;
    }
    else if (size == 8){
        freetable -> eight = updatedList;
    }
    else if (size == 9){
        freetable -> nine = updatedList;
    }
    else if (size == 10){
        freetable -> ten = updatedList;
    }
    else if (size == 11){
        freetable -> eleven = updatedList;
    }
    else if (size == 12){
        freetable -> twelve = updatedList;
    }
}

void *malloc(size_t size) {
    fprintf(stderr, "%s%zd%s\n", "malloc(", size, ");");
    int index = block_index(size);
    int headspace = size + 8; /* size of the block plus 8 for metadata */
    size_t adjusted = adjust(size); /* Adjusted block size */
    struct list *returnlist; /* return this */
    
    if (size == 0){ /* Clarity check, see man 3 malloc */
        return NULL;
    }

    if (freetable == NULL){
        freetable = sbrk(sizeoftable);
    }

    if (size <= 4088){ /* NOT using a bulk allocation */
        struct list *thelist = NULL;
        if (thelist != NULL && thelist -> next != NULL){ /* Space available, ready to allocate */
            returnlist = thelist;

            thelist = thelist -> next;
            thelist -> prev = NULL;

            update(index, thelist);
            
            returnlist -> size = headspace;
            returnlist -> next = NULL; /* returnlist shouldn't be associated with the free table */

            return returnlist + 8;
        }

        else { /* Not enough space available */
            expand(adjusted, thelist);

            thelist = findList(index);

            returnlist = thelist;

            thelist = thelist -> next;
            thelist -> prev = NULL;

            update(index, thelist);
                
            returnlist -> size = headspace;
            returnlist -> next = NULL;

            return returnlist + 8;
        }
    }

    else { /* Using a bulk allocation */
        returnlist = bulk_alloc(headspace);
        returnlist -> size = headspace;
        return returnlist + 8;
    }

    return NULL;
}

void *calloc(size_t nmemb, size_t size) {
    /* fprintf(stderr, "%s%zd%s%zd%s\n", "calloc(", nmemb, ", ", size, ");"); */
    size_t multiply = nmemb * size;
    
    if (multiply == 0){ /* Clarity check, see man 3 malloc */
        return NULL;
    }
    
    struct list *ptr = malloc(multiply);
    memset(ptr, 0, multiply);
    return ptr;
}

void free(void *ptr) {
    if (ptr == NULL){ /* Clarity check, see man 3 malloc */
        fprintf(stderr, "%s\n", "free(NULL ptr);");
        return;
    }
    
    struct list *pointer = (struct list*)ptr; /* converts to type struct list */
    pointer = pointer - 8;
    
    size_t size = (pointer -> size) - 8; /* want size without heading */
    size_t adjusted = adjust(size);
    int index = block_index(size);

    if (size <= 0){ /* this isn't a valid pointer */
        fprintf(stderr, "%s", "How did you get here?");
        return;
    }

    fprintf(stderr, "%s%zd%s\n", "free(*", size, ");");

    struct list *stoneFree;

    if (adjusted <= 4096){ /* Doesn't use bulk allocations */
        if (index == 5){
            stoneFree = freetable -> five;
            freetable -> five = pointer;
            freetable -> five -> next = stoneFree;
            freetable -> five -> prev = NULL;
            freetable -> five -> size = 0;
        }
        else if (index == 6){
            stoneFree = freetable -> six;
            freetable -> six = pointer;
            freetable -> six -> next = stoneFree;
            freetable -> six -> prev = NULL;
            freetable -> six -> size = 0;
        }
        else if (index == 7){
            stoneFree = freetable -> seven;
            freetable -> seven = pointer;
            freetable -> seven -> next = stoneFree;
            freetable -> seven -> prev = NULL;
            freetable -> seven -> size = 0;
        }
        else if (index == 8){
            stoneFree = freetable -> eight;
            freetable -> eight = pointer;
            freetable -> eight -> next = stoneFree;
            freetable -> eight -> prev = NULL;
            freetable -> eight -> size = 0;
        }
        else if (index == 9){
            stoneFree = freetable -> nine;
            freetable -> nine = pointer;
            freetable -> nine -> next = stoneFree;
            freetable -> nine -> prev = NULL;
            freetable -> nine -> size = 0;
        }
        else if (index == 10){
            stoneFree = freetable -> ten;
            freetable -> ten = pointer;
            freetable -> ten -> next = stoneFree;
            freetable -> ten -> prev = NULL;
            freetable -> ten -> size = 0;
        }
        else if (index == 11){
            stoneFree = freetable -> eleven;
            freetable -> eleven = pointer;
            freetable -> eleven -> next = stoneFree;
            freetable -> eleven -> prev = NULL;
            freetable -> eleven -> size = 0;
        }
        else if (index == 12){
            stoneFree = freetable -> twelve;
            freetable -> twelve = pointer;
            freetable -> twelve -> next = stoneFree;
            freetable -> twelve -> prev = NULL;
            freetable -> twelve -> size = 0;
        }
    }

    else { /* Uses bulk allocations */
        bulk_free(pointer, size + 8);
    }

    return;
}

void *realloc(void *ptr, size_t size) {
    struct list *returnlist; /* return this */
    
    if (ptr == NULL){ /* First clarity check, see man 3 malloc */
        fprintf(stderr, "%s%zd%s\n", "malloc(", size, ");");
        returnlist = malloc(size);
        return returnlist;
    }

    if (size == 0 && ptr != NULL){ /* Second clarity check, see man 3 malloc */
        fprintf(stderr, "%s\n", "realloc(size 0);");
        free(ptr);
        return NULL;
    }

    struct list *pointer = (struct list*)ptr; /* converts to type struct list */
    pointer = pointer - 8;

    size_t originalsize = (pointer -> size) - 8; /* want size without heading */
    size_t adjusted = adjust(originalsize);
    size_t newadjusted = adjust(size);
    size_t headspace = size + 8;

    fprintf(stderr, "%s%zd%s%zd%s\n", "realloc(*", originalsize, ", ", size, ");");

    if (originalsize >= size){ /* making pointer SMALLER */
        pointer -> size = headspace;
        return pointer + 8;
    }

    else { /* making pointer LARGER */
        if (originalsize <= 4088 && size <= 4088){ /* doesn't use bulk allocations */
            if (newadjusted == adjusted){ /* current block can accomodate reallocation */
                pointer -> size = headspace;
                return pointer + 8;
            }
            else { /* current block cannot accomodate reallocation */
                struct list *newpointer = malloc(size);
                pointer = pointer + 8;

                memcpy(newpointer, pointer, originalsize);

                free(ptr);
                return newpointer;
            }
        }

        else { /* involves bulk allocations */
            struct list *newpointer = malloc(size);

            memcpy(newpointer, pointer, originalsize);

            free(ptr);
            
            return newpointer + 8;
        }
    }
    
    return NULL;
}
