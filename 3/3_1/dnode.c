#include<stdio.h>
#include<stdlib.h>
#include "dnode.h"
#include "mydefine.h"

//初始化
void InitDNode(DNode * DN,ElementType item){
    DN->data = item;
    DN->next = DN;
    DN->prev = DN;
}

//在当前结点前插入结点
void InsertDNBefore(DNode * DN,DNode * ptr){
    ptr->next = DN;
    ptr->prev = DN->prev;
    DN->prev->next = ptr;
    DN->prev = ptr;
}

//在当前结点后插入结点
void InsertDNAfter(DNode * DN,DNode * ptr){
    ptr->next = DN->next;
    ptr->prev = DN;
    DN->next->prev = ptr;
    DN->next = ptr;
}

//删除当前当前结点
DNode * DeleteDNAt(DNode * DN){
    if(DN->next == DN)//只有一个结点
        return NULL;
    DN->next->prev = DN->prev;
    DN->prev->next = DN->next;
    return DN;
}

//申请空间
DNode * NewDNode(ElementType item){
    DNode * newDNode = (DNode*)malloc(sizeof(DNode));
    newDNode->data = item;
    newDNode->next=newDNode->prev=NULL;
    return newDNode;
}

//释放空间
void FreeDNode(DNode * DN){
    if(DN){
        printf("dnode.c [FreeDNode] Invalid node pointer\n");
        return;
    }
    free(DN);
}