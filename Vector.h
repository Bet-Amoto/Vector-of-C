#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//動的配列の宣言
#define vector(T) T*

//動的配列の初期化
#define vector_init(T,size) (T*)_vector_init(sizeof(T),size)

//動的配列に保存された情報を見る
#define vector_capacity(vec) ((const size_t*)((void*)(vec)))[-1]
#define vector_size(vec) ((const size_t*)((void*)(vec)))[-2]
#define vector_type(vec) ((const size_t*)((void*)(vec)))[-3]

//特定の場所に参照する
#define vector_at(vec,pos) vec[(pos)]
#define vector_back(vec) vector_at((vec),vector_size(vec)-1)
#define vector_flont(vec) vector_at((vec),0)
#define vector_begin(vec) &vector_at(vec,0)
#define vector_end(vec) &vector_at(vec,vector_size(vec)-1)


//動的配列が空かどうか見る
#define vector_enpty(vec) (vector_size(vec) == 0)

//特定の要素を消去する
#define vector_erace(vec,pos) do{for(int i=pos;i<vector_size(vec)-1;i++)vector_at(vec,i)=vector_at(vec,i+1);((size_t*)vec)[-2]-=1;}while (0)

//最後の要素を消去する
#define vector_popback(vec) vector_erace(vec,vector_size(vec)-1)

//特定の場所に要素を追加する
#define vector_insert(vec,pos,val) do{vector_push_back(vec,vector_back(vec));for(int i=vector_size(vec)-1;i>=pos;i--)vec[i]=vec[i-1];vec[pos]=val;}while(0)

//配列の末尾に要素を追加する
#define vector_push_back(vec,val) do{                                                                   \
    if(vector_capacity(vec) <= vector_size(vec)){                                                       \
        void* TmpVector = (void*)&((size_t*)vec)[-3];                                                   \
        void* NewAddr = realloc(TmpVector,(vector_size(vec)+1)*vector_type(vec) + sizeof(size_t)*3);    \
        assert(NewAddr!=NULL);                                                                          \
        if(TmpVector != NewAddr){TmpVector = NewAddr; vec=(void*)&(((size_t*)TmpVector)[3]);}           \
        ((size_t*)TmpVector)[2] += 1;                                                                   \
    }                                                                                                   \
    vector_at(vec,vector_size(vec)) = val;                                                              \
    ((size_t*)vec)[-2] +=1 ;                                                                            \
}while(0)

//CAPASITYの大きさを変える
#define vector_reserve(vec,siz)                                                                         \
    do{                                                                                                 \
        void* TmpVector=(void*)&((size_t*)vec)[-3];                                                     \
        void* NewAddr=realloc(TmpVector,siz*vector_type(vec)+sizeof(size_t)*3);                         \
        assert(NewAddr!=NULL);                                                                          \
        if(TmpVector != NewAddr){TmpVector = NewAddr; vec=(void*)&(((size_t*)TmpVector)[3]);}           \
        ((size_t*)TmpVector)[2] = siz;                                                                  \
        ((size_t*)TmpVector)[1] = min(vector_size(vec),vector_capacity(vec));                           \
    }while(0)

//配列の大きさを変える
#define vector_resize(vec,siz)do{if(siz>vector_capacity(vec))vector_reserve(vec,siz);((size_t*)vec)[-2] =siz;}while(0)

//メモリを開放する
#define vector_free(vec) do{void* TmpVector = (void*)&((size_t*)vec)[-3];free(TmpVector);vec=NULL;}while(0)

vector(void) _vector_init(size_t type,size_t size);

//ソートする
void vector_sort(vector(void) vec,int (*comp)(const void*,const void*));

//逆順にする
void vector_revears(vector(void) vec);
