#include<stdio.h>
#include<stdlib.h>
#include "cnode.h"
//初始化结点
void InitCNode(CNode * CN,ElementType item){
    CN->next = CN;
    CN->data = item;
}

//插入结点 在CN后插入ptr
void InsertCNAfter(CNode * CN, CNode * ptr){
    ptr->next = CN->next;
    CN->next = ptr;
}

//删除本结点后继
CNode * DeleteCNAfter(CNode * CN){
    CNode * tmpPtr;
    if(CN->next == CN)
        return NULL;
    tmpPtr = CN->next;
    CN->next = tmpPtr->next;
    return tmpPtr;
}

//申请新结点
CNode * NewCNode(ElementType item){
    CNode * newCNode = (CNode*)malloc(sizeof(CNode));
    newCNode->data = item;
    if(newCNode == NULL){
        printf("cnode.c [NewCNode] Allow memory failure\n");
        exit(1);
    }
    newCNode->next = NULL;
    return newCNode;
}

//释放结点
void FreeCNode(CNode * CN){
    if(!CN){
        printf("cnode.c [FreeCNode] Invalid node pointer\n");
        return;
    }
    free(CN);
}