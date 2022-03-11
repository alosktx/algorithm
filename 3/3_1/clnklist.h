#pragma once
#include<stdbool.h>
#include "cnode.h"
struct clnkList{
    CNode * rear;
    CNode * prevPtr;
    CNode * currPtr;
    int size;
    int position;
};
typedef struct clnkList ClnkList;

void InitClnkList(ClnkList *);
bool IsCLEmpty(ClnkList *);
int NextCLCNode(ClnkList *);
int SetCLPosition(ClnkList *,int);
void InsertCLAt(ClnkList *, ElementType);
void InsertCLAfter(ClnkList *,ElementType);
void DeleteCLAt(ClnkList *);
void DeleteCLAfter(ClnkList *);
ElementType GetCLData(ClnkList *);
void SetCLData(ClnkList *,ElementType);
void ClearCL(ClnkList *);