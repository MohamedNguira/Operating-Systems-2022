#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <math.h>
#include "time.h"


int main(int n,char *args[]){
    n = atoi(args[1]);
    for(int i = 0;i<n;i++){
        fork();
        sleep(5);
    }
    return EXIT_SUCCESS;
}
