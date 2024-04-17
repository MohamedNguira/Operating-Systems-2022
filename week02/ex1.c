#include <stdio.h>
#include <limits.h>
#include <float.h>
#define PI 3.14159


int main(void)
{
    char str[10];
    int integer = INT_MAX;
    unsigned short int ushortinteger = USHRT_MAX;
    signed long int slonginteger = LONG_MAX;
    float floatnumber = FLT_MAX;
    double doublenumber = DBL_MAX;
    
    printf("int: Size: %lu , Max Value:%d\n",sizeof integer, integer);
    printf("unsigned short int: Size: %lu , Max Value:%u\n",sizeof ushortinteger,ushortinteger);
    printf("signed long int: Size: %lu , Max Value:%lu\n",sizeof slonginteger, slonginteger);
    printf("float: Size: %lu , Max Value:%g\n",sizeof floatnumber, floatnumber);
    printf("double: Size: %lu , Max Value:%g\n",sizeof doublenumber, doublenumber);

    
}
