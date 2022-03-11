#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linkedqueue.h"

void PrintLQ(LinkedQueue * LQ){
    if(IsEmptyLQ(LQ))
        printf("[LinkedQueue] the LQ is empty\n");
    int i = 0;
    while(i < LQ->queue->size){
        SetPosition(LQ->queue, i++);
        printf("%d ",GetData(LQ->queue));
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    LinkedQueue * lq = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    InitLinkedQueue(lq);
    for(int i=0;i<10;i++){
        LQIn(lq,i+1);
        PrintLQ(lq);
    }
    printf("delete!\n");
    for(int i=0;i<10;i++){
        printf("[LQFront] The LQFont is %d\n",LQFront(lq));
        assert(LQFront(lq) == LQOut(lq));
        PrintLQ(lq);
    }

    for(int i=0;i<10;i++){
        LQIn(lq,i+1);
    }
    ClearLQ(lq);
    PrintLQ(lq);



    return 0;
}
