#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int rbits[1000];
int inmainmemory[1000];
int read[1001];
int main(int argc, char *argv[]) {
    int m = atoi(argv[1]);
    FILE *f = fopen(argv[2],"r");
    if(f == NULL){
        printf("File does not exist\nPlease specify the file name in the bash command or name your file input.txt\n");
        return 0;
    }
    int n = 0,operations = 0;
    int x;
    int miss = 0;
    while(fscanf(f,"%d",&x)>0){
        operations++;
        if(!read[x])n++;
        read[x] = 1;
        for(int i = 0;i<1000;i++){
            rbits[i] >>=1;
        }
        rbits[x] += 1 << 7;
        if(inmainmemory[x]){
            continue;
        }
        miss++;
        if(m>=n){
            inmainmemory[x] = 1;
            continue;
        }
        int mini = 1 << 8;int pageidx = -1;
        for(int i = 0;i<1000;i++){
            if(inmainmemory[i] && rbits[i] < mini){
                mini = rbits[i];
                pageidx = i;
            }
        }
        inmainmemory[pageidx] = 0;
        inmainmemory[x] = 1;
    }

    printf("Hit / Miss Rate: %f\n", (double)(operations - miss) / miss);

}
