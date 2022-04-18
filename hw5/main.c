#include<stdio.h>

typedef struct my_mm {
    int cu[10];
    int* cup[10];
    int co;
}my_mm_t;

my_mm_t mms;
int g_mem[10];

void mms_detect() {
    for(int i=0;i<10;i++) {
        if(g_mem[i]!=0) mms.cu[i]=1;
        else mms.cu[i]=0;
        printf("%d",mms.cu[i]);
    }    
}

int* my_calloc(int n,int size) {
    mms.co++;
    int np=0;
    for(int i=0;i<10;i++) {
        if(g_mem[i]==0) np++;
        else np=0;
        if(np>=n*size) {
            for(int j=i-np+1;j<i+1;j++){
                g_mem[j] = mms.co;
            }            
            mms_detect();
            printf("\n");
            return &g_mem[i];
        }
    }
    mms_detect();
    printf("<-Out of space\n");
    return NULL;
}

int* findAddress(int* n,int num){
    int i = 0;
    while(*n!=num) {
        n++;
        i++;
        if(i > 10) return 0;
    }
    return n;
}

void my_free(int* p) {                
    int count = 0;
    while(findAddress(g_mem,*p)&&count<10) {
        int *n = findAddress(g_mem,*p);
        *n = 0;
        count++;
    }
    mms_detect();
    printf("\n");
}
    
int main() {
    int* p1 = my_calloc(1,1);
    int* p2 = my_calloc(1,2);
    int* p3 = my_calloc(1,3);
    int* p4 = my_calloc(1,4);    
    my_free(p1);
    my_free(p4);
    int* p5 = my_calloc(1,5);
    int* p6 = my_calloc(1,1);
}
