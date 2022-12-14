#include <stdio.h>
#include "Vector.h"

#define max(a,b) ((a)>(b)?(a):(b))
//動的配列の中身を表示する関数
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

int main(){
    //動的配列の初期化
    vector(int) x = vector_init(int,0);
    for(int i = 0; i<vector_size(x);i++){
        x[i] = i;
    }
    PrintIntVector(x);
    // [0, 1, 2, 3, 4]

    //動的配列に値を追加
    for(int i=0;i<10;i++)vector_push_back(x,i*10);
    vector_insert(x,3,50);
    PrintIntVector(x);
    // [0, 1, 2, 50, 3, 4, 100]

    //ソート
    vector_sort(x,compareInt);
    PrintIntVector(x);
    // [0, 1, 2, 3, 4, 50, 100]

    //反転
    vector_revears(x);
    PrintIntVector(x);
    // [100, 50, 4, 3, 2, 1, 0]

    //一番後ろの値の削除
    vector_popback(x);
    PrintIntVector(x);
    // [100, 50, 4, 3, 2, 1]

    //2番目の値の削除
    vector_erace(x,2);
    PrintIntVector(x);
    // [100, 50, 3, 2, 1]

    //動的配列のメモリの解放
    vector_free(x);

    return 0;
}

