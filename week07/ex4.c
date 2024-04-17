#include <stdlib.h>
#include <string.h>

void *myrealloc(void * ptr, size_t oldsize,size_t size){
    if(ptr == NULL)return malloc(size);
    if(size == 0){
        free(ptr);
        return malloc(0);
    }
    void *temp = malloc(size);
    memcpy(temp,ptr,size<oldsize?size:oldsize);
    free(ptr);
    return temp;
}
