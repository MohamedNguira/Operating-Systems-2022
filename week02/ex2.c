#include <stdio.h>



int main(void)
{   
    printf("Enter the string to get reverse:\n");
    char str[256];
    int i = 0;
    do{
        //Read the string character by character
        str[i] = getchar();
        i++;
    }
    //stop when the user writes a dot or pressed enter
    while(str[i-1] != '.' && str[i-1] != '\n');
    str[i] = '\0';
    i--;
    //Prints the reverse
    while(--i != -1)printf("%c",str[i]);
}
