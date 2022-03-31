#include <stdio.h>
int my_strlen(char* s) {
    int n=0;
    while (*s++) n++;
    return n;
}
int main()
{
    char s[]="IU is a girl!";
    printf("len = %d\n" , my_strlen(s));

    return 0;
}
