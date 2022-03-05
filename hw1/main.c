#include <stdio.h>
#include <stdlib,h>
#include <time.h>

int main() {
    int x=0;i=0;s=0;
    time_t t;
    printf("歡迎光臨長庚樂透彩購買機台\n請問你要買幾組樂透彩:");
    scanf("%d",&x);
    printf("%d\n已為您購買的%d組樂透組合輸出至 lotto.txt",x,x);
    time(&t);
    FILE* fp;
    fp=fopen("lotto.txt","w+");
    fprintf(fp,"======== lotto649 =========\n");
    fprintf(fp,"=%s=",ctime(&t));
    srand((unsigned) time(NULL));
    for (i=1;i<=5;i++) {
        fprintf(fp,"[%d]:",i);
        if (i>x) {
            fprintf(fp," -- -- -- -- -- -- --\n");
        } else {
            for (int j=0;j<6;j++) {
                s=rand()%69+1;
                if (s<10) {
                fprintf(fp," %d%d",0,s);
                } else {
                    fprintf(fp," %d",s);
                }
        }
        fprintf(fp," %d%d\n",0,rand()%9+1);
        }
    }
    fprintf(fp,"======== csie@CGU =========\n");

    return 0;
}