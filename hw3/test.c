#include <stdio.h>
#include <stdlib.h>

int main () {
    char fileName[64]="hanoi.c";
    char line[1024];
    int i=0;
    FILE* rfp=fopen(fileName,"r");
    FILE* wfp=fopen("hw3.pdf","w+");
    while(fgets (line,sizeof(line),rfp)!=NULL) {
        printf("%s",line);
        fputs(line,wfp);
    }
    fclose(rfp);
    fclose(wfp);
    return 0;
}