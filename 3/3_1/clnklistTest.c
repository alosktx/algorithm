#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"clnklist.h"

void PrintClnkList(ClnkList * CL){
    CNode * currCNptr = CL->rear;
    do{
        printf("%d ",currCNptr->data);
        currCNptr = currCNptr->next;
    }while(currCNptr!=CL->rear);
    printf("\n");
}

void infClnkList(ClnkList * CL){
    printf("position: %d\t",CL->position);

    printf("prevPtr: %d\t",CL->prevPtr->data);
    printf("prevNext: %d\t",CL->prevPtr->next->data);

    printf("currPtr: %d\t",CL->currPtr->data);
    printf("currNext: %d\t",CL->currPtr->next->data);

    printf("rear: %d\t",CL->rear->data);
    printf("rearNext: %d\t",CL->rear->next->data);

    printf("size: %d\n",CL->size);
}

int main(int argc, char const *argv[])
{
    ClnkList * CL = (ClnkList*)malloc(sizeof(ClnkList));

    printf("\n\nInitClnkList()>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    InitClnkList(CL);
    PrintClnkList(CL);
    infClnkList(CL);

    printf("\n\nInsertCLAt()>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    for(int i=0;i<10;i++){
        InsertCLAt(CL,i);
        PrintClnkList(CL);
        infClnkList(CL);
    }
    
    printf("\n\nDeleteCLAt()>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    for(int i=0;i<10;i++){
        DeleteCLAt(CL);
        PrintClnkList(CL);
        infClnkList(CL);
    }

    printf("\n\nInsertCLAfter()>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    for(int i=0;i<10;i++){
        InsertCLAfter(CL,i);
        PrintClnkList(CL);
        infClnkList(CL);
    }

    printf("\n\nSetCLPosition()>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    for(int i=0;i<10;i++){
        assert(i == SetCLPosition(CL,i));
        PrintClnkList(CL);
        infClnkList(CL);
    }
    SetCLPosition(CL,-1);
    SetCLPosition(CL,10);

    printf("\n\nNextCLCNode()>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    assert(0 == SetCLPosition(CL,0));
    for(int i=0;i<9;i++){
        assert(i+1 ==NextCLCNode(CL));
        PrintClnkList(CL);
        infClnkList(CL);
    }
    assert(-1 ==NextCLCNode(CL));
    PrintClnkList(CL);
    infClnkList(CL);


    printf("\n\nDeleteCLAfter()>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    SetCLPosition(CL,9);
    DeleteCLAfter(CL);
    PrintClnkList(CL);
    infClnkList(CL);

    SetCLPosition(CL,0);
    for(int i=0;i<10;i++){
        DeleteCLAfter(CL);
        PrintClnkList(CL);
        infClnkList(CL);
    }

    printf("\n\nDeleteCLAt() 删除一个结点>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    PrintClnkList(CL);
    infClnkList(CL);
    DeleteCLAt(CL);
    PrintClnkList(CL);
    infClnkList(CL);

    printf("\n\nIsCLEmpty()>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    if(IsCLEmpty(CL)){
        PrintClnkList(CL);
    }

    printf("\n\nEmpty delete>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    DeleteCLAt(CL);
    PrintClnkList(CL);
    infClnkList(CL);
    DeleteCLAfter(CL);
    PrintClnkList(CL);
    infClnkList(CL);

    printf("\n\nClearCL()>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    ClearCL(CL);
    // PrintClnkList(CL);
    return 0;
}
