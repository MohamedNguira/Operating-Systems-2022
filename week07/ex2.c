#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int main(int argc, char *argv[]){
    int n;
    scanf("%d",&n);
    int *array = malloc(n * sizeof(int));
    for(int i = 0;i<n;i++){
        array[i] = i;
    }
    for(int i = 0;i<n;i++){
        printf("%d ",array[i]);
    }
    free(array);
}
