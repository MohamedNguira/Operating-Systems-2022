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
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int fd;
    char buf[1024];

    fd = open("/tmp/ex1", O_RDONLY);
    while(1){
        read(fd, buf, 1024);
        printf("%s",buf);
        sleep(1);
    }
    close(fd);
}
