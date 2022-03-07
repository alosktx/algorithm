#include "linkedlist.h"
struct linkedQueue{
    LinkedList * queue;
};
typedef struct linkedQueue LinkedQueue;

//初始化一个链队列
void InitLinkedQueue(LinkedQueue *);
//队列中插入一个新数据元素
void LQIn(LinkedQueue *,ElementType);
//队列中删除一个数据元素
ElementType LQOut(LinkedQueue *);
//取队列头部元素
ElementType LQFront(LinkedQueue *);
//清除队列中的元素
void ClearLQ(LinkedQueue *);
//判队列是否为空
bool IsEmptyLQ(LinkedQueue *);