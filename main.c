#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Vector.h"

typedef struct{
    int x;
    int y;
}Vec2;

void PrintIntVector(vector(int) vec){
    printf("[");
    for(int i=0;i<vector_size(vec);i++){
        printf("%d",vec[i]);
        if(i<vector_size(vec)-1)printf(", ");
    }
    printf("]\n");
}

//ソート用の比較関数
int compareInt(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}

//ソート用の比較関数
int compareVec2(const void* a,const void* b){
    return ((Vec2*)a)->x - ((Vec2*)b)->x;
}

int main(){
    //動的配列の初期化
    vector(int) x = vector_init(int,5);
    for(int i = 0; i<vector_size(x);i++){
        x[i] = i;
    }
    PrintIntVector(x);
    // [0, 1, 2, 3, 4]

    //動的配列に値を追加
    vector_push_back(x,100);
    vector_insert(x,3,50);
    PrintIntVector(x);
    // [0, 1, 2, 50, 3, 4, 100]

    //ソート
    sort(x,compareInt);
    PrintIntVector(x);
    // [0, 1, 2, 3, 4, 50, 100]

    //反転
    revears(x);
    PrintIntVector(x);
    // [100, 50, 4, 3, 2, 1, 0]

    //一番後ろの値の削除
    vector_popback(x);
    PrintIntVector(x);

    //2番目の値の削除
    vector_erace(x,2);
    PrintIntVector(x);
    // [100, 50, 4, 3, 1, 0]

    //動的配列のメモリの解放
    vector_free(x);

    return 0;
}

