#pragma once
#include<stdlib.h>
#include<stdio.h>
typedef int ElementType;
struct node{
    struct node *next;
    ElementType data;
};
typedef struct node Node;
//对结点进行初始化处理，并指向一个结点
void InitNode(Node *,ElementType ,Node *);
//在当前结点后插入元素
void InertAfter(Node *,Node*);
//删除当前结点的后继结点
Node* DeleteAfter(Node *);
//创建指向一个结点的单链表的结点
Node* GetNode(ElementType, Node *);
//释放一个单链表的结点
void FreeNode(Node *);


