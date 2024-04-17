#include <stdio.h>
#include <malloc.h>
int foo(int age){
    return 2022 - age;
}
int main () {
    const int x = 10;
    const int *q = &x;
    const int const *p = malloc(5 * sizeof(int));
    for(int i = 0;i<5;i++){
        int *temp = p + i;
        *(temp) = x;
    }
    for(int i = 0;i<5;i++){
        printf("%p\n",p+i);
    }
    for(int i = 0;i<5;i++){
        int *temp = p + i;
        scanf("%d",temp);
    }
    for(int i = 0;i<5;i++){
        int *temp = p + i;
        *temp = foo(*temp);
    }
    free(p);
    return 0;
}