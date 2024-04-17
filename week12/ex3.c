

#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

/*On my pc this only path link worked
 * If this doesn't work for you try replacing the value below by "/dev/input/by-path/platform-i8042-serio-0-event-kbd"
 * */
const char *path = "/dev/input/by-path/pci-0000:06:00.3-usb-0:4:1.0-event-kbd";
int check[256];
bool checkShortcut(int n,int a[]){
    for(int i = 0;i<n;i++){
        if(!check[a[i]])return false;
    }
    int c = 0;
    for(int i = 0;i<256;i++)c += check[i];
    return c == n;
}
int shortcut1[] = {25,18},shortcut2[] = {25,30,46},customshortcut[] = {35,23};
int main(int argc, char *argv[]) {
    int fd;
    struct input_event event;
    fd = open(path, O_RDONLY);
    FILE* open = fopen("ex3.txt","a");
    printf("Press P + E to print 'I passed the exam'\nPress C + A + P to print 'Get some cappuccino!\nPress H + I to print 'See you in oral exam!\n");
    fprintf(open,"Press P + E to print 'I passed the exam'\nPress C + A + P to print 'Get some cappuccino!\nPress H + I to print 'See you in oral exam!\n");
    fclose(open);
    while(true){
        read(fd, &event, sizeof(struct input_event));
        if(event.code == 0)continue;
        FILE* open = fopen("ex3.txt","a");
        if(event.value == 1){
            check[event.code] = 1;
        }else if(event.value == 0){
            check[event.code] = 0;
        }
        if(checkShortcut(2,shortcut1)){
            printf("I passed the Exam!\n");
            fprintf(open,"I passed the Exam!\n");
        }
        if(checkShortcut(3,shortcut2)){
            printf("Get some cappuccino!\n");
            fprintf(open,"Get some cappuccino!\n");
        }
        if(checkShortcut(2,customshortcut)){
            printf("See you in oral exam!\n");
            fprintf(open,"See you in oral exam!\n");
        }
        fclose(open);
    }
}
