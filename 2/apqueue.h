#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MaxPQSize 10
enum boolean {FALSE,TRUE};
typedef enum boolean Bool;
typedef int DataType;
struct pQueue{
    int count;
    DataType pqList[MaxPQSize];
};
typedef struct pQueue PQueue;

void InitPQueue(PQueue * P);
void PQInsert(PQueue * P, DataType item);
DataType PQDelete(PQueue * P);
Bool PQEmpty(PQueue * P);
Bool PQFull(PQueue * P);
void PrintPQueue(PQueue * P);