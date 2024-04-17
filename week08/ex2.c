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
 * Exercise 2:
* Throughout the execution of the program, the value of the free memory in "vmstat" is decreasing. There is also an iteration with a very high 'si' value.
 * Meanwhile, 'so' value is constantly 0
*/

