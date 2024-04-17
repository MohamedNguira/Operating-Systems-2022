#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <dirent.h>


int main(int argc, char *argv[]) {
    struct stat s;
    struct dirent *dp;
    DIR *dirp = opendir ( "./tmp/" ) ;
    while (( dp = readdir ( dirp ) ) != NULL ) {
        struct dirent *dp1;
        DIR *dirp1 = opendir ( "./tmp/" ) ;
        int count = 0;
        while((dp1 = readdir(dirp1)) != NULL){
            if(dp -> d_ino == dp1->d_ino){
                count++;
            }
        }
        dirp1 = opendir("./tmp/");
        if(count >= 2){
            printf("%s ---- ",dp -> d_name);
            while((dp1 = readdir(dirp1)) != NULL){
                if(dp -> d_ino == dp1->d_ino){
                    printf("%s",dp1->d_name);
                    if(--count){
                        printf(", ");
                    }
                }
            }
            printf("\n");
        }
    }
    closedir( dirp);
}
