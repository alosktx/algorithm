#include<stdlib.h>
#include<stdio.h>
#include "clnklist.h"
void InitClnkList(ClnkList * CL){
    //缺陷，头/尾结点插入了int型数据0，如果要装其他类型的ElementType，此处需要手动修改  
    CNode * headCNode = NewCNode(-1);
    InitCNode(headCNode,-1);
    //初始化时 或者说是空表状态下 preVptr和currPtr设成一样
    CL->rear = CL->currPtr =CL->prevPtr = headCNode;
    // CL->prevPtr = NULL;
    CL->size = 0;
    CL->position = -1;
}

bool IsCLEmpty(ClnkList * CL){
    return (bool)(CL->size == 0);
}

int NextCLCNode(ClnkList * CL){
    if(IsCLEmpty(CL)){
        printf("clnklist.c [NextCLNode] The ClnkList is empty!\n");
        return -1; 
    }else if(CL->currPtr->next==CL->rear){
        printf("clnklist.c [DeleteCLAfter] The currPtr has not after!\n");
        return -1; 
    }
    CL->prevPtr=CL->currPtr;
    CL->currPtr=CL->currPtr->next;
    CL->position++;
    return CL->position;
}

int SetCLPosition(ClnkList * CL,int pos){
    if(IsCLEmpty(CL)){
        printf("clnklist.c [SetCLPosition] The ClnkList is empty!\n");
        return -1;
    }
    if(pos<0||pos>CL->size-1){
        printf("clnklist.c [SetCLPosition] Wrong pos number: %d\n",pos);
        return -1;
    }

    CL->currPtr = CL->rear->next;
    CL->prevPtr = CL->rear;
    CL->position = 0;

    for(int i=0;i<pos;i++){
        CL->prevPtr=CL->currPtr;
        CL->currPtr=CL->currPtr->next;
        CL->position++;
    }
    return CL->position;
}

void InsertCLAt(ClnkList * CL, ElementType item){
    CNode * newCNode;
    newCNode = NewCNode(item);
    InsertCNAfter(CL->prevPtr,newCNode);
    if(IsCLEmpty(CL)){
        CL->position = 0;
    }
    CL->size++;
    CL->currPtr=newCNode;
}

void InsertCLAfter(ClnkList * CL,ElementType item){
    CNode * newCNode = NewCNode(item);
    InsertCNAfter(CL->currPtr,newCNode);
    CL->prevPtr=CL->currPtr;
    CL->currPtr=newCNode;
    CL->position++;
    CL->size++;
}

void DeleteCLAt(ClnkList * CL){
    CNode * oldCNode;
    if(CL->currPtr == CL->rear){
        printf("clnklist.c [DeleteCLAt] The ClnkList is empty!\n");
        return ;
    }
    oldCNode = DeleteCNAfter(CL->prevPtr);
    CL->currPtr = oldCNode->next;
    if(1 == CL->size-- ) CL->position =-1;
    FreeCNode(oldCNode);
}

void DeleteCLAfter(ClnkList * CL){
    CNode * oldCNode;
    oldCNode = DeleteCNAfter(CL->currPtr);
    if(oldCNode == CL->rear){
        CL->currPtr->next = oldCNode;
        printf("clnklist.c [DeleteCLAfter] The currPtr has not after!\n");
        return;
    }else if(!oldCNode){
        printf("clnklist.c [DeleteCLAfter] The ClnkList is empty!\n");
        return ;
    }
    CL->size--;
    FreeCNode(oldCNode);
    return;
}

ElementType GetCLData(ClnkList * CL){
    if(IsCLEmpty(CL)){
        printf("clnklist.c [GetCLData] The ClnkList is empty！\n");
        exit(1);
    }
    return CL->currPtr->data;
}

void SetCLData(ClnkList * CL,ElementType item){
    if(IsCLEmpty(CL)){
        printf("clnklist.c [SetCLData] The ClnkList is empty！\n");
        exit(1);
    }
    CL->currPtr->data = item;
}

void ClearCL(ClnkList * CL){
    CNode * currCNptr = CL->rear->next;
    CNode * nextCNptr;
    while(currCNptr!=CL->rear){
        nextCNptr = currCNptr->next;
        FreeCNode(currCNptr);
        currCNptr = nextCNptr;
    }
    free(currCNptr);
    CL->rear=CL->prevPtr=CL->currPtr=NULL;
    CL->size = 0;
    CL->position = -1;
}