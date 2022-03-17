#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define c_i(i) scanf("%d",&i);
#define s_q(q) scanf("%d",&q);
typedef struct lotto_record {
    int emp_id;
    char lotto_date[64];
    char lotto_time[64];
    int lotto_no;
    float lotto_receipt;
} lotto_record_t;
void write_id (int userid) {
    FILE* tmpfp=fopen("operator_id.bin","wb+");
    char theid[3];
    snprintf(theid,3,"%d",userid);
    fwrite(theid,sizeof(int),1,tmpfp);
    fclose(tmpfp);
}
void record (lotto_record_t record_t_i) {
    FILE* tempfp=fopen("records.bin","ab");
    fwrite(&record_t_i,sizeof(lotto_record_t),1,tempfp);
    fclose(tempfp);
}
int get_id (int userid) {
    char read_array[3];
    snprintf(read_array,3,"%d",userid);
    FILE* tmpfp=fopen("operator_id.bin","rb");
    fread(read_array,sizeof(int),1,tmpfp);
    fclose(tmpfp);
    return userid;
}
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
    int i,q;
    lotto_record_t record_t_i;
    int a[69],x,userid;
    time_t t=time(0);
    char szb[32],uff[32];
    strftime(szb,32,"%Y%m%d",localtime(&t));
    strftime(uff,32,"%H:%M:%S",localtime(&t));
    char s1[11];
    FILE *fp;
    int c = co();
    char name[10] = "lotto";
    namef(name,c);
    int lotto[7];
    snprintf(s1,sizeof(s1),"lotto%0*d",4,c);
    fp=fopen(s1,"w+");
    srand((unsigned) time(NULL));
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請輸入操作人員ID:");
    scanf("%d",&userid);
    write_id(userid);
    int id=get_id(userid);
    printf("\n請問您要買幾組樂透:");
    scanf("%d",&x);
    printf("\n已為您購買的 %d 組樂透組合輸出至 lotto[%0*d].txt",x,5,c);
    fprintf(fp,"======== lotto649 ========\n=======+ No.%0*d +=======\n",5,c);
    fprintf(fp,"=%.*s=\n",24,ctime(&t));
    record_t_i.emp_id=userid;
    record_t_i.lotto_no=c;
    snprintf(record_t_i.lotto_date,sizeof(record_t_i.lotto_date),"%s",szb);
    snprintf(record_t_i.lotto_time,sizeof(record_t_i.lotto_time),"%s",uff);
    record_t_i.lotto_receipt=x*50*1.1;
    record(record_t_i);
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
    fprintf(fp,"=======* Op.%05d ========\n",id);
    fprintf(fp,"======== csie@CGU ========\n");
    fclose(fp);

    return 0;
}
