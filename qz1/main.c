#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compare(int a[]) {
    for (int i=1;i<=6;i++) {
        for (int j=0;j<5;j++) {
            if (a[j]>a[j+1]) {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
}
int co() {
    int n;
    FILE *fp;
    if ((fp = fopen("count.bin","rb+")) == NULL) {
        n = 0;
        fp = fopen("count.bin","wb");
        fwrite(&n,sizeof(int),1,fp);
        fclose(fp);
    }
    fp = fopen("count.bin","rb+");
    fread(&n,sizeof(int),1,fp);
    fclose(fp);

    n = n + 1;
    fp = fopen("count.bin","wb+");
    fwrite(&n,sizeof(int),1,fp);
    return n;
}

void namef(char name[],int c) {
    for (int i = 8; i >= 5; i--,c /= 10) {
        name[i] = (c%10+'0');
    }
}

int main() {
    int a[69],x;
    time_t t;
    time(&t);
    char s1[11];
    FILE *fp;
    int c = co();
    char name[10] = "lotto";
    namef(name,c);
    int lotto[7];
    snprintf(s1,sizeof(s1),"lotto%0*d",4,c);
    fp=fopen(s1,"w+");
    srand((unsigned) time(NULL));
    printf("歡迎光臨長庚樂透彩購買機台\n請問你要買幾組樂透彩:");
    scanf("%d",&x);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto[%0*d].txt",x,5,c);
    fprintf(fp,"======== lotto649 ========\n=======+ No.%0*d +=======\n",5,c);
    fprintf(fp,"=%.*s=\n",24,ctime(&t));
    for (int j=1; j<=5; j++) {
        for (int i=0; i<69; i++) {
            a[i]=i+1;
        }
        for (int i=0; i<69; i++) {
            int r = rand()%69,tmp=a[i];
            a[i] = a[r];
            a[r] = tmp;
        }
        compare(a);
        if (j>x) {
            fprintf(fp,"[%d]: ",j);
            fprintf(fp,"-- -- -- -- -- -- --\n");
        } else {
            fprintf(fp,"[%d]: ",j);
            for (int i=0; i<6; i++) {
                fprintf(fp,"%0*d ",2,a[i]);
            }
            for (int i=6; i<69; i++) {
                if (a[i]<10) {
                    fprintf(fp,"%0*d\n",2,a[i]);
                    break;
                }
            }
        }
    }
    fprintf(fp,"======== csie@CGU ========\n");
    fclose(fp);

    return 0;
}