

#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

/*On my pc this only path link worked
 * If this doesn't work for you try replacing the value below by "/dev/input/by-path/platform-i8042-serio-0-event-kbd"
 * */
const char *path = "/dev/input/by-path/pci-0000:06:00.3-usb-0:4:1.0-event-kbd";

int main(int argc, char *argv[]) {
    int fd;
    struct input_event event;
    fd = open(path, O_RDONLY);

    while(true){
        read(fd, &event, sizeof(struct input_event));
        if(event.code == 0)continue;
        FILE* open = fopen("ex2.txt","a");
        if(event.value == 1){
            printf("PRESSED 0x%04x (%d)\n",event.code,event.code);
            fprintf(open,"PRESSED 0x%04x (%d)\n",event.code,event.code);
        }else if(event.value == 0){
            printf("RELEASED 0x%04x (%d)\n",event.code,event.code);
            fprintf(open,"RELEASED 0x%04x (%d)\n",event.code,event.code);
        }
        fclose(open);
    }
}
