#include <stdio.h>
#include <string.h>


int count(char str[],char c){
    int occurs = 0;
    for(int i = 0;i<strlen(str);i++){
        if(str[i] == c)occurs++;
    }
    return occurs;
}
void countAll(char str[]){
    char output[5000];
    memset(output,'\0',5000);
    for(int i = 0;i<strlen(str);i++){
        if(str[i] >= 'A' && str[i] <= 'Z')str[i] += 'a' - 'A';
        int occurs = count(str,str[i]);
        sprintf(output + strlen(output),"%c:%d, ",str[i],occurs);
    }
    int n = strlen(output);
    output[n-2] = '\0';
    printf("%s",output);
}
int main(void)
{
    char input[256];
    scanf("%s",input);
    countAll(input);
}
