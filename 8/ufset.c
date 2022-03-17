#include<stdio.h>
#include"ufset.h"
//初始化并查集
void CreatUFSet(UFSet * S, int n){
    S->size = n;
    for(int i = 0;i<S->size;i++){
        S->Parent[i] = -1;
    }
    printf("Create success!\n");
    for(int i = 0;i<S->size;i++){
        printf("%d ",S->Parent[i]);
    }
    printf("\n");
}
//查找元素i所属的并察集的子集
int FindUFSet(UFSet * S, int i){
    //S->Parent[i] >=0 说明i属于S->Prant[i] 所表示的并查集，循环查找，直到S->Parent[i] = -1，说明此时的i即为根结点；
    for(;S->Parent[i]>=0;i=S->Parent[i]);
    return i;
}
//合并运算
void UnionUFSet(UFSet * S,int i,int j){
    S->Parent[i] = j;
}