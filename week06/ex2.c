#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct process{
    unsigned long long arrival,burst;
    int id;
} ;
typedef struct process process;


int n;
process *processes;
int *finished;
int getMinimumBeforeTime(unsigned long long time){
    int index = -1;
    unsigned long long mini = -1;
    for(int i = 0;i<n;i++){
        if(finished[i])continue;
        if(processes[i].arrival > time)continue;
        if(mini == -1){
            mini = processes[i].burst;
            index = i;
        }
        else{
            if(mini > processes[i].burst){
                index = i;
                mini = processes[i].burst;
            }
        }
    }
    return index;
}
int getNextProcess(){
    unsigned long long minimum = LLONG_MAX;
    int index = -1;
    for(int i = 0;i<n;i++){
        if(finished[i])continue;
        if(processes[i].arrival < minimum){
            minimum = processes[i].arrival;
            index = i;
        }
    }
    return index;
}
int main(int argc, char *argv[]){
    printf("Write down the number of processes:\n");
    scanf("%d",&n);
    processes = malloc(2*n * sizeof (process));
    finished = malloc(n * sizeof(int));
    memset(finished,0,n * sizeof(int));
    for(int i = 0;i<n;i++){
        printf("Write down the arrival time and burst time for process %d:\n",i);
        scanf("%llu %llu",&processes[i].arrival,&processes[i].burst);
        processes[i].id = i;
    }
    unsigned long long time = 0;
    unsigned long long totalwaitingtime = 0,totalturnaroundtime = 0;
    int count = 0;
    while(count < n){
        int i = getMinimumBeforeTime(time);
        if(i == -1){
            time = processes[getNextProcess()].arrival;
            i = getMinimumBeforeTime(time);
        }
        unsigned long long newtime = time + processes[i].burst;
        printf("Process %d:\n",processes[i].id);
        printf("Completion Time: %llu\n",newtime);
        printf("Turnaround time: %llu\n",newtime - processes[i].arrival);
        totalturnaroundtime += newtime - processes[i].arrival;
        printf("Waiting Time: %llu\n",time - processes[i].arrival);
        printf("===============\n");
        totalwaitingtime += time - processes[i].arrival;
        time = newtime;
        finished[i] = 1;
        count++;
    }
    
    printf("Average Turnaround time: %f\n",(double)totalturnaroundtime/n);
    printf("Average waiting time: %f",(double)totalwaitingtime/n);
    
    free(processes);
    free(finished);
}
