#include "linkedqueue.h"

//初始化一个链队列
void InitLinkedQueue(LinkedQueue * LQ){
    LQ->queue = (LinkedList*)malloc(sizeof(LinkedList));
    InitLinkedList(LQ->queue);
}
//队列中插入一个新数据元素,时间复杂度为O(n) 
void LQIn(LinkedQueue *LQ,ElementType item){
    SetPosition(LQ->queue,(LQ->queue)->size-1);
    InsertIAfter(LQ->queue,item);
}
//队列中删除一个数据元素
ElementType LQOut(LinkedQueue *LQ){
    if(!LQ->queue->size){
        printf("[LQOut] The queue is empty!\n");
        exit(1);
    }
    SetPosition(LQ->queue,0);
    ElementType item = GetData(LQ->queue);
    DeleteAt(LQ->queue);
    return item;
}
//取队列头部元素
ElementType LQFront(LinkedQueue * LQ){
    if(!LQ->queue->size){
        printf("[LQOut] The queue is empty!\n");
        exit(1);
    }
    SetPosition(LQ->queue,0);
    return GetData(LQ->queue);;
}
//清除队列中的元素
void ClearLQ(LinkedQueue * LQ){
    Clear(LQ->queue);
}
//判队列是否为空
bool IsEmptyLQ(LinkedQueue * LQ){
    return (bool)(LQ->queue->size == 0);
}