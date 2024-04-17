#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
/**
 * I modified the program to allocate 1 GB of memory each second to see a clearer result
 *
 */
int main(){
    char *p[10];
    for(int i = 0;i<10;i++){
        p[i] = malloc(1000000000);
        memset(p[i],0,1000000000);
        struct rusage usage;
        getrusage(RUSAGE_SELF,&usage);
        printf("Memory Usage: %ldKB\n",usage.ru_maxrss);
        sleep(1);
    }
    for(int i = 0;i<10;i++)free(p[i]);
    return 0;
}
