#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <sys/stat.h>
#include "time.h"
#include <fcntl.h>
#include <sys/types.h>

int main(int n,char *args[]){
    int subs = atoi(args[1]);
    int fd;
    mkfifo("/tmp/ex1", 0666);
    fd = open("/tmp/ex1", O_WRONLY);

    while(1){
        char msg[1024];
        fgets(msg, 1024, stdin);
        for(int i = 0;i<subs;i++)write(fd, msg, 1024);
        sleep(1);
    }
    close(fd);
}
