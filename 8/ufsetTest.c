#include<stdio.h>
#include<stdlib.h>
#include"ufset.h"
#define LENGTH 9
int main(int argc, char const *argv[])
{
    UFSet * S = (UFSet*)malloc(sizeof(UFSet));
    CreatUFSet(S,LENGTH);

    UnionUFSet(S,0,1);
    UnionUFSet(S,2,5);
    UnionUFSet(S,1,7);
    UnionUFSet(S,5,7);
    UnionUFSet(S,3,4);
    UnionUFSet(S,4,6);
    UnionUFSet(S,6,8);

    for(int i = 0;i<LENGTH;i++){
        printf("%d->root:%d\n",i,FindUFSet(S,i));
    }

    return 0;
}

