#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct process{
    unsigned long long arrival,burst;
    int id;
} ;
typedef struct process process;

int comp (const void * elem1, const void * elem2)
{
    unsigned long long f = ((process*)elem1) ->arrival;
    unsigned long long s = ((process*)elem2) ->arrival;
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int main(int argc, char *argv[]){
    int n;
    printf("Write down the number of processes:\n");
    scanf("%d",&n);
    process processes[n];
    for(int i = 0;i<n;i++){
        printf("Write down the arrival time and burst time for process %d:\n",i);
        scanf("%llu %llu",&processes[i].arrival,&processes[i].burst);
        processes[i].id = i;
    }
    qsort (processes, sizeof(processes)/sizeof(*processes), sizeof(*processes), comp);
    unsigned long long time = 0;
    unsigned long long totalwaitingtime = 0,totalturnaroundtime = 0;
    for(int i = 0;i<n;i++){
        if(time < processes[i].arrival)time = processes[i].arrival;
        unsigned long long newtime = time + processes[i].burst;
        printf("Process %d:\n",processes[i].id);
        printf("Completion Time: %llu\n",newtime);
        printf("Turnaround time: %llu\n",newtime - processes[i].arrival);
        totalturnaroundtime += newtime - processes[i].arrival;
        printf("Waiting Time: %llu\n",time - processes[i].arrival);
        printf("===============\n");
        totalwaitingtime += time - processes[i].arrival;
        time = newtime;
    }
    printf("Average Turnaround time: %f\n",(double)totalturnaroundtime/n);
    printf("Average waiting time: %f",(double)totalwaitingtime/n);
}