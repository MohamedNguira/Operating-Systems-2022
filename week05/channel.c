#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    pipe(fd);
    pid_t subscriber = fork();

    if (subscriber != 0) {
        while(1) {
            char msg[200];
            fgets(msg, 200, stdin);
            write(fd[1], msg, strlen(msg) + 1);
        }

    } else {
        while(1) {
            char msg[200];
            read(fd[0], msg, sizeof(msg));
            printf("%s", msg);
        }
    }
}
