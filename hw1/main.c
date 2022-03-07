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

int main() {
    int a[69],x;
    time_t t;
    FILE *fp;
    fp=fopen("lotto.txt","w+");
    srand((unsigned) time(NULL));
    printf("歡迎光臨長庚樂透彩購買機台\n請問你要買幾組樂透彩:");
    scanf("%d",&x);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt",x);
    time(&t);
    time(NULL);
    fprintf(fp,"======== lotto649 ========\n=%.*s=\n",24,ctime(&t));
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