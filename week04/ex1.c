#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
int main(void)
{
    clock_t maintime = clock();

    pid_t main = getpid();
    pid_t child1 = fork();
    clock_t child1time = clock();
    pid_t child2;
    if(main == getpid())child2 = fork();
    clock_t child2time = clock();
    if(getpid() == main){
        printf("(Main Process): ID: %d, Parent ID: %d, Execution Time: %f ms\n\n",getpid(),getppid(),(float)(clock()-maintime) * 1000 / CLOCKS_PER_SEC);
    }else if(child1 == 0){
        printf("(Child 1): ID: %d, Parent ID: %d, Execution Time: %f ms\n\n",getpid(),getppid(),(float)(clock() - child1time) * 1000 / CLOCKS_PER_SEC);
    }else{
        printf("(Child 2): ID: %d, Parent ID: %d, Execution Time: %f ms\n\n",getpid(),getppid(),(float)(clock() - child2time) * 1000 / CLOCKS_PER_SEC);
    }
    return EXIT_SUCCESS;
}
