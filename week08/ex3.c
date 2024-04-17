#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
/**
 * I chose my program to allocated 1 GB of memory in each iteration because I have a lot of RAM
 *
 */
int main(){
    char *p[10];
    for(int i = 0;i<10;i++){
        p[i] = malloc(1000000000);
        memset(p[i],0,1000000000);
        sleep(1);
    }
    for(int i = 0;i<10;i++)free(p[i]);
    return 0;
}
/**
* Exercise 3:
 * Throughout the execution of the program, the process ex2 allocated more and more memory which rises the value of 'virt' and 'res' fields in
 * "top" command. By the end of the execution, 'res' value reaches 10g and 'virt" value reaches around 10000000.
*/
