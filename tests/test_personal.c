#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define ALLOC_SIZE 48

struct list { /* format for the header, loosely based on K&R's Header struct from page 187 */
    struct list *prev; /* last block */
    struct list *next; /* next block */
    size_t remaining; /* remaining space left from the last memory request */
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

int main(int argc, char *argv[]){
    void *A = calloc(1, 1008);
    void *B = malloc(16);
    void *C = malloc(16);
    void *D = malloc(2032);
    free(A);
    void *E = calloc(1, 2048);
    free(B);
    void *F = malloc(1008);
    void *G = calloc(1, 112);
    void *H = calloc(1, 2048);
    free(D);
    free(H);
    void *I = malloc(1008);
    free(G);
    void *J = malloc(16);
    void *K = calloc(1, 2048);
    void *L = malloc(2048);
    void *M = malloc(112);
    free(M);
    void *N = calloc(1, 2032);
    void *O = calloc(1, 16);
    void *P = malloc(112);
    void *Q = calloc(1, 2032);
    void *R = calloc(1, 1008);
    void *S = malloc(2048);
    void *T = calloc(1, 240);
    void *U = calloc(1, 496);
    free(T);
    void *V = calloc(1, 112);
    void *W = malloc(240);
    void *X = malloc(16);
    void *Y = calloc(1, 16);
    void *Z = calloc(1, 16);
    free(V);
    free(X);
    void *AA = malloc(2032);
    void *AB = calloc(1, 48);
    free(W);
    void *AC = malloc(48);
    void *AD = calloc(1, 2048);
    free(AC);
    void *AE = malloc(496);
    free(Y);
    void *AF = calloc(1, 48);
    void *AG = malloc(496);
    void *AH = calloc(1, 112);
    void *AI = calloc(1, 496);
    void *AJ = calloc(1, 1008);
    void *AK = malloc(1008);
    void *AL = malloc(2032);
    void *AM = malloc(16);
    void *AN = malloc(2032);
    void *AO = malloc(496);
    void *AP = calloc(1, 112);
    void *AQ = malloc(240);
    void *AR = malloc(112);
    void *AS = malloc(2032);
    void *AT = malloc(16);
    void *AU = malloc(496);
    void *AV = malloc(240);
    free(AN);
    void *AW = calloc(1, 2032);
    void *AX = calloc(1, 2032);
    void *AY = malloc(2032);
    free(AD);
    void *AZ = calloc(1, 496);
    void *BA = calloc(1, 496);
    void *BB = calloc(1, 16);
    void *BC = malloc(1008);
    free(AZ);
    void *BD = calloc(1, 112);
    void *BE = calloc(1, 2048);
    void *BF = calloc(1, 496);
    void *BG = malloc(2032);
    void *BH = calloc(1, 16);
    void *BI = calloc(1, 1008);
    free(BI);
    void *BJ = calloc(1, 1008);
    void *BK = calloc(1, 48);
    void *BL = calloc(1, 1008);
    void *BM = calloc(1, 2048);
    free(BF);
    void *BN = calloc(1, 496);
    void *BO = malloc(16);
    void *BP = malloc(2048);
    void *BQ = calloc(1, 2048);
    free(AY);
    void *BR = malloc(2048);
    void *BS = calloc(1, 240);
    void *BT = malloc(240);
    free(BS);
    void *BU = calloc(1, 240);
    free(BG);
    void *BV = malloc(2048);
    void *BW = malloc(496);
    void *BX = malloc(2048);
    void *BY = malloc(496);
    void *BZ = calloc(1, 240);
    void *CA = calloc(1, 496);
    free(CA);
    void *CB = calloc(1, 48);
    void *CC = calloc(1, 2032);
    void *CD = calloc(1, 112);
    void *CE = malloc(48);
    void *CF = calloc(1, 48);
    void *CG = malloc(112);
    void *CH = calloc(1, 48);
    void *CI = calloc(1, 496);
    void *CJ = calloc(1, 48);
    void *CK = malloc(48);
    void *CL = malloc(48);
    free(BX);
    void *CM = malloc(112);
    void *CN = calloc(1, 16);
    void *CO = calloc(1, 16);
    void *CP = calloc(1, 16);
    void *CQ = calloc(1, 112);
    free(BZ);
    void *CR = calloc(1, 496);
    free(CQ);
    void *CS = malloc(16);
    free(CS);
    void *CT = calloc(1, 16);
    void *CU = malloc(16);
    void *CV = calloc(1, 496);
    free(CC);
    free(CR);
    void *CW = calloc(1, 112);
    void *CX = malloc(1008);
    free(CV);
    void *CY = malloc(16);
    free(CY);
    void *CZ = calloc(1, 240);
    void *DA = malloc(496);
    void *DB = calloc(1, 496);
    void *DC = malloc(16);
    free(CL);
    void *DD = malloc(2048);
    void *DE = calloc(1, 240);
    void *DF = malloc(48);
    void *DG = calloc(1, 240);
    void *DH = calloc(1, 240);
    free(DA);
    void *DI = calloc(1, 1008);
    free(DC);
    free(DD);
    void *DJ = calloc(1, 496);
    free(DB);
    free(CW);
    free(DI);
    void *DK = calloc(1, 1008);
    free(DK);
    free(CU);
    free(DF);
    void *DL = malloc(2048);
    free(CK);
    free(CP);
    void *DM = malloc(1008);
    void *DN = calloc(1, 1008);
    void *DO = calloc(1, 48);
    free(DM);
    void *DP = malloc(1008);
    free(DP);
    void *DR = malloc(496);
    free(DO);
    void *DS = malloc(112);
    free(DS);
    void *DT = calloc(1, 496);
    void *DU = malloc(1008);
    void *DV = calloc(1, 2032);
    void *DW = calloc(1, 2048);
    void *DX = calloc(1, 1008);
    void *DY = malloc(48);
    void *DZ = calloc(1, 112);
    free(DH);
    void *EA = calloc(1, 496);
    free(EA);
    free(DW);
    void *EB = malloc(2048);
    void *EC = calloc(1, 1008);
    void *ED = malloc(240);
    free(DT);
    void *EE = calloc(1, 2048);
    free(EC);
    void *EF = calloc(1, 48);
    void *EG = malloc(496);
    void *EH = calloc(1, 2032);
    void *EI = malloc(496);
    void *EJ = malloc(496);
    void *EK = calloc(1, 496);
    void *EL = calloc(1, 240);
    void *EM = calloc(1, 496);
    free(EI);
    free(EJ);
    void *EN = malloc(112);
    void *EO = calloc(1, 2032);
    void *EP = malloc(496);
    void *EQ = malloc(240);
    void *ER = calloc(1, 112);
    void *ES = calloc(1, 240);
    void *ET = malloc(112);
    void *EU = malloc(1008);
    free(EU);
    void *EV = malloc(1008);
    free(EO);
    free(EH);
    void *EW = malloc(48);
    void *EX = malloc(16);
    void *EY = calloc(1, 240);
    void *EZ = calloc(1, 240);
    void *FA = malloc(496);
    void *FB = calloc(1, 16);
    void *FC = malloc(2048);
    void *FD = malloc(1008);
    free(FB);
    void *FE = malloc(2048);
    void *FF = calloc(1, 2048);
    void *FG = calloc(1, 1008);
    void *FH = malloc(16);
    void *FI = malloc(16);
    void *FJ = calloc(1, 2032);
    void *FK = malloc(2032);
    void *FL = calloc(1, 112);
    free(FA);
    void *FM = calloc(1, 112);
    void *FN = calloc(1, 2048);
    free(EP);
    void *FO = malloc(112);
    void *FP = calloc(1, 496);
    void *FQ = calloc(1, 1008);
    void *FR = malloc(496);
    free(FH);
    void *FS = malloc(1008);
    void *FT = malloc(48);
    free(FF);
    void *FU = malloc(1008);
    void *FV = malloc(16);
    free(FI);
    void *FW = calloc(1, 48);
    void *FX = calloc(1, 2048);
    void *FY = malloc(1008);
    void *FZ = malloc(2048);
    void *GA = calloc(1, 496);
    void *GB = malloc(2048);
    void *GC = calloc(1, 2032);
    free(FV);
    void *GD = calloc(1, 240);
    void *GE = malloc(2032);
    free(GC);
    void *GF = calloc(1, 1008);
    void *GG = malloc(240);
    void *GH = malloc(112);
    void *GI = calloc(1, 2032);
    free(C);
    void *GJ = malloc(112);
    void *GK = malloc(112);
    void *GL = malloc(1008);
    void *GM = malloc(240);
    void *GN = calloc(1, 16);
    free(GM);
    free(GB);
    free(GN);
    void *GO = calloc(1, 48);
    free(GJ);
    void *GP = calloc(1, 16);
    void *GQ = malloc(112);
    void *GR = calloc(1, 240);
    void *GS = calloc(1, 16);
    free(GL);
    void *GT = malloc(1008);
    void *GU = malloc(48);
    void *GV = malloc(2048);
    free(FZ);
    free(GT);
    void *GW = calloc(1, 112);
    free(GV);
    void *GX = malloc(112);
    void *GY = calloc(1, 16);
    void *GZ = calloc(1, 48);
    void *HA = malloc(240);
    void *HB = calloc(1, 48);
    void *HC = calloc(1, 112);
    free(HA);
    void *HD = malloc(1008);
    free(HD);
    void *HE = malloc(2048);
    free(GG);
    void *HF = calloc(1, 240);
    free(GY);
    free(GI);
    free(FR);
    void *HG = malloc(112);
    void *HH = calloc(1, 240);
    free(GS);
    void *HI = calloc(1, 16);
    void *HJ = malloc(48);
    free(GE);
    void *HK = malloc(112);
    void *HL = calloc(1, 2048);
    free(HK);
    void *HM = malloc(16);
    free(HL);
    free(HJ);
    void *HN = calloc(1, 2048);
    void *HO = malloc(240);
    free(HM);
    void *HP = calloc(1, 1008);
    free(HP);
    void *HQ = malloc(112);
    free(HB);
    void *HR = calloc(1, 240);
    free(HQ);
    free(HN);
    void *HS = malloc(1008);
    free(HG);
    void *HT = malloc(496);
    free(HE);
    void *HU = malloc(2032);
    free(HR);
    void *HV = calloc(1, 112);
    void *HW = malloc(2048);
    free(HT);
    void *HX = malloc(16);
    free(HV);
    void *HY = calloc(1, 112);
    void *HZ = malloc(112);
    void *IA = calloc(1, 48);
    free(HY);
    void *IB = calloc(1, 2032);
    free(HW);
    void *IC = calloc(1, 2048);
    free(HS);
    free(HZ);
    void *ID = calloc(1, 1008);
    void *IE = calloc(1, 48);
    free(IA);
    void *IF = malloc(112);
    free(ID);
    void *IG = malloc(2032);
    free(IC);
    free(ID);
    free(FC);
    void *IH = malloc(112);
    void *II = malloc(1008);
    free(IE);
    free(II);
    void *IJ = malloc(48);
    void *IK = calloc(1, 48);
    void *IL = calloc(1, 240);
    free(U);
    void *IM = calloc(1, 2032);
    free(IL);
    free(E);
    void *IN = calloc(1, 112);
    free(AI);
    void *IO = calloc(1, 240);
    void *IP = calloc(1, 112);
    free(IM);
    void *IQ = malloc(16);
    free(AG);
    void *IR = calloc(1, 2048);
    free(CX);
    free(IN);
    free(BJ);
    free(IK);
    void *IS = malloc(48);
    void *IT = calloc(1, 2032);
    void *IU = calloc(1, 496);
    void *IV = calloc(1, 2048); 

    void *p1 = malloc(6000);
    p1 = realloc(p1, 4000);
    void *p3 = calloc(1500, 1);
    void *p4 = calloc(32, 32);
    void *p5 = malloc(299);
    void *p6 = malloc(5000);
    p6 = realloc(p6, 400);
    p6 = realloc(p6, 5000);
    free(p1);
    free(p3);
    free(p4);
    free(p5);
    free(p6);
    p1 = malloc(300);
    p1 = realloc(p1, 500);
    free(p1);

    for(int i = 0; i != 128; i++){
        void *p1metad = calloc(4, 900) - (sizeof(void) * 8);
        p1metad = p1metad;
    }
    
    p1 = malloc(234);
    p1 = realloc(p1, 600);
    p1 = realloc(p1, 23678);
    p1 = realloc(p1, 9123);
    free(p1);
    
    for(int i = 0; i != 128; i++){
        p3 = calloc(2, 300);
        p3 = realloc(p3, 2000);
        free(p3);
        void *p2 = malloc(5000);
        p2 = realloc(p2, 0);
        p3 = calloc(2, 4567);
        p3 = malloc(50000);
        free(p3);
        p3 = calloc(i, 5000);
        free(p3);
    }

    p4 = malloc(37);
    p5 = malloc(552);
    p4 = malloc(1024);
    free(p4);
    free(p5);
    p4 = malloc(5);
    free(p4);
    p4 = malloc(120);
    p4 = malloc(12);
    p4 = malloc(776);
    p4 = malloc(112);
    p4 = malloc(1336);
    p4 = malloc(216);
    p4 = malloc(432);
    p4 = malloc(104);
    p4 = malloc(88);
    p4 = malloc(120);
    p4 = malloc(168);
    p4 = malloc(104);
    p4 = malloc(80);
    p4 = malloc(192);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4 = malloc(12);
    p4=p4;

    p4 = calloc(1, 1024);
    free(p4);
    p4 = calloc(1, 1024);
    p4 = realloc(p4, 2048);
    p5 = malloc(2048);
    p5 = malloc(49);
    free(p5);


    return 0;
}
