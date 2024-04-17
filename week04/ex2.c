#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <math.h>
#include "time.h"

int u[120],v[120];
FILE *file;
int main(){
    srand(time(NULL));
    file = fopen("temp.txt","w+");

    for(int i = 0;i<120;i++){
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }
    int n;
    scanf("%d",&n);
    int computationsPerNode = 120/n;
    pid_t processes[n];
    pid_t main = getpid();
    int currentNode = 0;
    for(int j = 0;j<n;j++){
        if(getpid() == main){
            processes[j] = fork();
            currentNode = j;
        }
    }
    while(wait(NULL) > 0);
    if(main == getpid()){
        int res[120];
        fclose(file);
        file = fopen("temp.txt","r");
        for(int i = 0;i<120;i++){
            int x , y;
            fscanf(file,"%d",&x);
            fscanf(file,"%d",&y);
            res[x] = y;
        }
        for(int i = 0;i<120;i++){
            printf("%d\n",res[i]);
        }
        fclose(file);
        return EXIT_SUCCESS;
    }
    int begin = computationsPerNode * currentNode;
    int end = computationsPerNode * (currentNode + 1);
    while(begin < end){
        fprintf(file,"%d %d\n",begin,u[begin] * v[begin]);
        begin++;
    }


    return EXIT_SUCCESS;
}
