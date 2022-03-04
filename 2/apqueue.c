#include"apqueue.h"

void InitPQueue(PQueue * P){
    P->count = 0;
}

void PQInsert(PQueue * P, DataType item){
    //PQFull(P) 而不是 PQFull 忘记了P 
    if(!PQFull(P)){
        P->pqList[(P->count)++] = item;
    }else{
        printf("[PQInsert] the PQueue is full\n");
    }
}

DataType PQDelete(PQueue * P){
    if(PQEmpty(P)){
        printf("[PQDelete] the PQueue is empty\n");
        return -1;
    }else{
        DataType min = P->pqList[0];
        int index = 0;
        for(int i = 1;i<P->count;i++){
            if(min>P->pqList[i]){
                min = P->pqList[i];
                index = i;
            }
        }
        P->pqList[index] = P->pqList[P->count-1];
        P->count--;
        //又返回参数的最好提前把返回参数写好，以免忘记
        return min;
    }
}

Bool PQEmpty(PQueue * P){
    return (Bool)(P->count == 0);
}

Bool PQFull(PQueue * P){
    return (Bool)(P->count == MaxPQSize);
}

void PrintPQueue(PQueue * P){
    for(int i =0;i<P->count;i++){
        printf("%d\t",P->pqList[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    PQueue *P = (PQueue*)malloc(sizeof(PQueue));
    InitPQueue(P);
    PrintPQueue(P);
    for(int i = 0;i<5;i++){
        PQInsert(P,i+1);
        PrintPQueue(P);
        PQInsert(P,10-i);
        PrintPQueue(P);
    }

    PQInsert(P,11);
    PrintPQueue(P);
    
    for(int i =0;i<11;i++){
        printf("PQDelete: %d\n",PQDelete(P));
        PrintPQueue(P);
    }

    return 0;
}


