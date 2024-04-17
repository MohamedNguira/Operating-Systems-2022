#include <stdio.h>
#include <stdlib.h>
#include "math.h"
typedef struct{

    float x,y;

} Point;

float distance(Point A, Point B){
    float result;
    float xd = A.x - B.x, yd = A.y - B.y;
    result = sqrtf(xd * xd + yd * yd);
    return result;
}

float area(Point A, Point B, Point C){
    float result;
    result = 0.5f * abs(A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - C.y * A.x);
    return result;
}

int main(void){
    Point A = {2.5f,6},B = {1,2.2f}, C = {10,6};
    float f = distance(A, B);
    printf("A -- B distance is %f\n", f);
    float a = area(A, B, C);
    printf("Area of triangle ABC is %f\n", a);
    return EXIT_SUCCESS;
}