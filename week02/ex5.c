#include <stdio.h>
#include <string.h>

long long tribonacci(int n){
    long long a = 0,b = 1, c =1;
    for(int i = 0;i<n;i++){
        int temp = c;
        c = a + b + c;
        a = b;
        b = temp;
    }
    return a;
}

int main(void)
{
    long long result1 = tribonacci(4);
    long long result2 = tribonacci(36);
    printf("Tribonacci of 4 is %lld\n",result1);
    printf("Tribonacci of 36 is %lld\n",result2);

}
