#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

struct Thread;
struct Thread{
    pthread_t id;
    int i;
    char message[256];
};
typedef struct Thread Thread;
void *threadroutine(void *p){
    Thread t = *(Thread *)p;
    printf("%s",t.message);
    printf("Thread %d id: %lu\n",t.i,t.id);
    printf("Thread %d exits\n",t.i);
}
int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);
    Thread threads[n];
    for(int i = 0;i<n;i++){
        Thread t = {.i = i};
        sprintf(t.message,"Hello from thread %d\n",i);
        threads[i] = t;
        pthread_create(&threads[i].id, NULL, threadroutine, &threads[i]);
        printf("Thread %d is created\n",i);
        pthread_join(threads[i].id,NULL);

    }
}
