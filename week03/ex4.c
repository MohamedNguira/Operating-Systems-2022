#include <stdio.h>
#include <stdlib.h>

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    *(int*)a = (*(int*)a + *(int*)b);
    return a;
}

void* addDouble(const void* a, const void* b){
    *(double*)a = *(double*)a + *(double*)b;
    return a;
}

void* mulInt(const void* a, const void* b){
    *(int*)a = (*(int*)a * *(int*)b);
    return a;
}

void* mulDouble(const void* a, const void* b){

    *(double*)a = *(double*)a * *(double*)b;
    return a;
}

void* meanInt(const void* a, const void* b){
    *(int*)a = (*(int*)a + *(int*)b);
    return a;
}

void* meanDouble(const void* a, const void* b){
    *(double*)a = *(double*)a + *(double*)b;
    return a;
}

void* aggregate(void* base, size_t size, int n, void* initial_value ,void* (*opr)(const void*, const void*)){

    void* output;

    if (size==sizeof(int)){
        // base is a pointer to an integer
        output = (int*)base;
        for(int i = 0;i<n;i++){
            opr(output,((int*)initial_value) + i);
        }
        if(opr == meanInt)*(int *)output /= n;
    }else{ // base is a pointer to a double
        output = (double*)base;
        for(int i = 0;i<n;i++){
            opr(output,((double*)initial_value) + i);
        }
        if(opr == meanDouble)*(double *)output /= n;
    }

    return output;
}




int main(){

    int ints[] = {2,9,-8,3,7};
    double doubles[] ={-3.02,5.36,7.96,8.01,-0.002};
    //<WRITE YOUR CODE HERE>;


    // Addition
    int base1 = 0;
    double base2 = 0;

    int* result1a = aggregate(&base1,sizeof (int), 5,ints, addInt);
    printf("%d\n", *result1a);
    double* result2a = aggregate(&base2,sizeof (double), 5,doubles, addDouble);

    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2a);


    // Multiplication
    base1 = 1;
    int* result1m = aggregate(&base1,sizeof (int), 5,ints, mulInt);

    //<WRITE YOUR CODE HERE>;

    printf("%d\n", *result1m);
    base2 = 1;
    double* result2m  = aggregate(&base2,sizeof (double), 5,doubles, mulDouble);

    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2m);



    // Mean
    base1 = 0;
    int* result1mean =  aggregate(&base1,sizeof (int), 5,ints, meanInt);

    //<WRITE YOUR CODE HERE>;

    printf("%d\n", *result1mean);
    base2 = 0;
    double* result2mean  = aggregate(&base2,sizeof (double), 5,doubles, meanDouble);

    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2mean);


    // free the pointers
    //Nothing to free since I didn't allocate any memory from the heap
    //<WRITE YOUR CODE HERE>;


    return EXIT_SUCCESS;
}
