#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <math.h>
#include "time.h"


int main(int n,char *args[]){

    pid_t child = fork();
    if(child == 0)while(1){
            char cmd[300];
            fgets(cmd, 100, stdin);
            system(cmd);
            if(strcmp(cmd,"exit\n") == 0)return EXIT_SUCCESS;
        }
    wait(NULL);
}
