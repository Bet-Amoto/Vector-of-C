#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Vector.h"


void PrintIntVector(vector(char) vec){
    printf("[");
    for(int i=0;i<vector_size(vec);i++){
        printf("%d",vec[i]);
        if(i<vector_size(vec)-1)printf(", ");
    }
    printf("]\n");
}

int compareInt(const void* a,const void* b){
    return *(char*)a - *(char*)b;
}

int main(){
    vector(char) x = vector_init(char,5);
    for(int i = 0; i<vector_size(x);i++){
        x[i] = i;
    }
    PrintIntVector(x);
    vector_push_back(x,100);
    vector_insert(x,3,50);
    PrintIntVector(x);
    sort(x,compareInt);
    PrintIntVector(x);
    revears(x);
    PrintIntVector(x);
    vector_erace(x,4);
    PrintIntVector(x);
    vector_free(x);

    return 0;
}