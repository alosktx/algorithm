#pragma once
#include "node.h"
#include "stdbool.h"
// enum boolean {FALSE,TRUE};
// typedef enum boolean Bool;
struct linkedList{
    //指向表头的指针
    Node * front;
    //指向表尾的指针
    Node * rear;
    //指向当前结点前驱的指针
    Node * prevPtr;
    //当前结点指针
    Node * currPtr;
    //表中结点数
    int size;
    //表中当前结点的位置计数
    int position;
};
typedef struct linkedList LinkedList;
//初始化单链表
void InitLinkedList(LinkedList *);
//判断表是否为空
bool IsEmpty(LinkedList *);
//求当前结点后继, 将其设置为当前结点
int NextINode(LinkedList *);
//重定位当前结点
int SetPosition(LinkedList *,int pos);
//在当前结点处插入结点
void InsertAt(LinkedList *,ElementType item);
//在当前结点后插入结点
void InsertIAfter(LinkedList *,ElementType item);
//删除当前结点
void DeleteAt(LinkedList *);
//删除当前结点后继
void DeleteIAfter(LinkedList *);
//访问数据
ElementType GetData(LinkedList *);
//修改数据
void SetData(LinkedList *,ElementType item);
//清空链表
void Clear(LinkedList *);