#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct process{
    unsigned long long arrival,burst,nexttime,remainingburst;
    int id;
} ;
typedef struct process process;


int n,q;
process *processes;
int *finished;

int comp (const void * elem1, const void * elem2)
{
    unsigned long long f = ((process*)elem1) ->arrival;
    unsigned long long s = ((process*)elem2) ->arrival;
    if (f > s) return  1;
    if (f < s) return -1;
    f = ((process*)elem1) ->burst;
    s = ((process*)elem2) ->burst;
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int getNextProcess(){
    unsigned long long minimum = LLONG_MAX;
    int index = -1;
    for(int i = 0;i<n;i++){
        if(finished[i])continue;
        if(processes[i].nexttime < minimum){
            minimum = processes[i].nexttime;
            index = i;
        }else if(processes[i].nexttime == minimum && processes[i].remainingburst < processes[index].remainingburst){
            index = i;
        }

    }
    return index;
}
int main(int argc, char *argv[]){
    printf("Write down the number of processes and the quantum:\n");
    scanf("%d %d",&n,&q);
    processes = malloc(n * sizeof (process));
    finished = malloc(n * sizeof(int));
    memset(finished,0,n * sizeof(int));
    for(int i = 0;i<n;i++){
        printf("Write down the arrival time and burst time for process %d:\n",i);
        scanf("%llu %llu",&processes[i].arrival,&processes[i].burst);
        processes[i].nexttime = processes[i].arrival;
        processes[i].remainingburst = processes[i].burst;
        processes[i].id = i;
    }
    unsigned long long time = 0;
    unsigned long long totalwaitingtime = 0,totalturnaroundtime = 0;
    qsort (processes, sizeof(processes)/sizeof(*processes), sizeof(*processes), comp);
    int count = 0;
    while(count < n){
        int i = getNextProcess();
        if(processes[i].remainingburst <= q){
            unsigned long long newtime = time + processes[i].remainingburst;
            finished[i] = 1;
            printf("Process %d:\n",processes[i].id);
            printf("Completion Time: %llu\n",newtime);
            printf("Turnaround time: %llu\n",newtime - processes[i].arrival);
            totalturnaroundtime += newtime - processes[i].arrival;
            printf("Waiting Time: %llu\n",newtime - processes[i].arrival - processes[i].burst);
            totalwaitingtime += newtime - processes[i].arrival - processes[i].burst;
            printf("===============\n");
            time = newtime;
            count++;
        }else{
            unsigned long long newtime = time + q;
            processes[i].remainingburst -= q;
            processes[i].nexttime = newtime;
            time = newtime;
        }

    }
    printf("Average Turnaround time: %f\n",(double)totalturnaroundtime/n);
    printf("Average waiting time: %f",(double)totalwaitingtime/n);
    
    free(processes);
    free(finished);
}
