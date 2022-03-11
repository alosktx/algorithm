#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include"linkedstack.h"
int main(int argc, char const *argv[])
{
    LinkedStack * LS = (LinkedStack*)malloc(sizeof(LinkedStack));
    InitLinkedStack(LS);
    for(int i = 0;i<10;i++)
        Push(LS,i+1);
    for(int i = 0;i<10;i++){
        printf("Top: %d\n",Top(LS));
        assert(Top(LS) == Pop(LS));
    }
    return 0;
}
