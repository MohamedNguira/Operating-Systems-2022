#include <stdio.h>
#include <dirent.h>
int main(){
    struct dirent *d;
    DIR *dr = opendir(".");
    if(dr == NULL){
        printf("ERROR");
        return 0;
    }
    while((d = readdir(dr)) != NULL){
        printf("%s\n", d -> d_name);
    }
    closedir(dr);
    return 0;
}