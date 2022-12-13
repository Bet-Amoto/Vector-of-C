#include "Vector.h"
//値の入れ替え
static void swap(void* a,void* b,size_t siz){
    void* TmpAddr = malloc(siz);
    memcpy(TmpAddr,a,siz);
    memcpy(a,b,siz);
    memcpy(b,TmpAddr,siz);
    free(TmpAddr);
}
//動的配列の初期化
vector(void) _vector_init(size_t type,size_t size){
    vector(void) TmpVector = malloc(type*size + sizeof(size_t)*3);
    ((size_t*)TmpVector)[0] = type;
    ((size_t*)TmpVector)[1] = size;
    ((size_t*)TmpVector)[2] = size;
    return (void*)&(((size_t*)TmpVector)[3]);
    
}

//動的配列を関数に従ってソートする
void vector_sort(vector(void) vec,int (*comp)(const void*,const void*)){
    qsort(vec,vector_size(vec),vector_type(vec),comp);
}

//動的配列の中身の順番をひっくり返す
void vector_revears(void* vec){
    size_t n = vector_type(vec);
    for(int i=0;i<vector_size(vec)/2;i++){
        swap(((char*)vec)+i*n,((char*)vec)+(vector_size(vec)-i-1)*n,n);
    }
}

