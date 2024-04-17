#include <stdio.h>
#include <string.h>


void convert(long long x, short int s,short int t){
    long long xbase10 = 0;
    char xstr[50];
    sprintf(xstr,"%lld",x);

    for(int i =0;i<(int)strlen(xstr);i++){
        xbase10 *= s;
        xbase10 += (int)(xstr[i] - '0');
    }

    char xbaseT[50];
    memset(xbaseT,'\0',50);
    int index = 0;
    while(xbase10){
        xbaseT[index] = (char)(xbase10 % t) + '0';
        xbase10 /= t;
        index++;
    }
    printf("The converted number is: ");

    for(int i = (int)strlen(xbaseT)-1;i>=0;i--){
        printf("%c",xbaseT[i]);
    }
}
int main(void)
{   printf("Enter the number x, the base s and the base t:\n");
    long long x;
    short int s,t;
    scanf("%lld %hd %hd",&x,&s,&t);
    convert(x,s,t);
}
