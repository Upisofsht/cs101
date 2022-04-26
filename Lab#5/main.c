#include <stdio.h>
#include <stdlib.h>

int* get_int_array (int n) {
    return (int*)calloc(n,sizeof(int));
}
void set_value (int* p, int v) {
    *p = v;
}
void print_array (int* p, int n) {
    printf("[");
    for (int i=0; i<n; i++) {
        if(i==(n-1)) {
            printf("%d]\n",*p+i);
        } else {
            printf("%d, ",*p+i);
        }
    }
}
typedef struct array_list{
    int n;
    int* ip;
    int* (*func_get)(int);
    void (*func_set)(int*, int);
    void (*func_print)(int*,int);
} array_list_t;

int main () {
    int n = 10;
    int* ip = get_int_array(n);
    
    for (int i=0; i<n; i++) {
        set_value(ip+i, i+1);
    }
    printf("No.1 -------------------\n");
    print_array(ip, n);
    array_list_t a;
    a.n=20;
    a.func_get=get_int_array;
    a.func_set=set_value;
    a.func_print=print_array;
    a.ip=a.func_get(a.n);
    for (int i=0; i<a.n; i++) {
        a.func_set(a.ip+i,i+1);
    }
    printf("No.2 -------------------\n");
    a.func_print(a.ip,a.n);
    
    //printf("No.3 -------------------\n");
    return 0;
}
