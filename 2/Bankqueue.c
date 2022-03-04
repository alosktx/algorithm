#include"Bankqueue.h"

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
        exit(0);
    }else{
        DataType newEvent;
        
        int mintime = P->pqList[0].time;
        int index = 0;
        newEvent = P->pqList[0];

        for(int i = 1;i<P->count;i++){
            if(mintime>P->pqList[i].time){

                mintime = P->pqList[i].time;
                index = i;
                newEvent = P->pqList[i];
            }
        }

        P->pqList[index] = P->pqList[P->count-1];
        P->count--;
        //有返回参数的最好提前把返回参数写好，以免忘记
        return newEvent;
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
        printf("time: %d etype: %s\tcustomerID: %d\ttellerID: %d\twaittime: %d\tservicetime: %d\n",P->pqList[i].time, (P->pqList[i].etype == 0)? "arrival":"departure", P->pqList[i].customerID, P->pqList[i].tellerID, P->pqList[i].waittime, P->pqList[i].servicetime);
    }
    printf("\n");
}

