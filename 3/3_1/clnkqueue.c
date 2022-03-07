#include<stdio.h>
#include<stdlib.h>
#include "clnkqueue.h"
//入队，新结点加入到链表尾部
void CLQ_In(ClnkQueue ** CLQ, ElementType item){
    //申请空间
    ClnkQueue *node = (ClnkQueue*)malloc(sizeof(ClnkQueue));
    node->data = item;
    //队列为空的情况,既然有专门判空的函数，就直接使用该函数，不要自己另写，防止写错，也方便修改
    if(CLQ_IsEmpty(*CLQ)){
        printf("[CLQ_In] Start to insert\n");
        node->next = node;
    }else{
    //非空的情况    
        //插入尾结点
        node->next = (*CLQ)->next;
        (*CLQ)->next = node;
    }
    *CLQ = node;
}
//出队
ElementType CLQ_Out(ClnkQueue ** CLQ){
    //非空
    if(!CLQ_IsEmpty(*CLQ)){
        ElementType item = (*CLQ)->next->data;
        //只有一个结点的情况
        // if((*CLQ)->next == (*CLQ)){
        //     free(*CLQ);
        //     *CLQ = NULL;
        // }else{
        //     ClnkQueue * frontNode = (*CLQ)->next;
        //     *CLQ = frontNode->next;
        //     free(frontNode);
        // }

        ClnkQueue * frontNode = (*CLQ)->next;
        //只有一个结点的情况
        if(frontNode == (*CLQ)){
            *CLQ = NULL;
        }else{
            (*CLQ)->next = frontNode->next;
        }
        free(frontNode);
        return item;
    }else{
        printf("[CLQ_Out] The ClnkQueue is empty!\n");
        exit(1);
    }
}
//队头元素
ElementType CLQ_Front(ClnkQueue * CLQ){
    //非空
    if(!CLQ_IsEmpty(CLQ)){
        return CLQ->next->data;
    }else{
        printf("[CLQ_Front] The ClnkQueue is empty!\n");
        exit(1);
    }
}
//打印队列
void CLQ_Print(ClnkQueue * CLQ){
    //非空
    if(!CLQ_IsEmpty(CLQ)){
        //打印一圈，注意循环终止条件
        ClnkQueue *nextNode = CLQ->next;
        // printf("%d ",nextNode->data);
        // nextNode = nextNode->next;
        // while(nextNode!=CLQ->next){
        //     printf("%d ",nextNode->data);
        //     nextNode = nextNode->next;
        // }
        do{
            printf("%d ",nextNode->data);
            nextNode=nextNode->next;
        }while(nextNode!=CLQ->next);
        
        printf("\n");
    }else{
        printf("[CLQ_Print] The ClnkQueue is empty!\n");
        return;
    }
}
//判空
Bool CLQ_IsEmpty(ClnkQueue * CLQ){
    return (Bool)(CLQ == NULL);
}
//清除 多余，可以了解一下在函数中调用指针的要点
void CLQ_Free(ClnkQueue * CLQ){
    printf("[CLQ_Free1]\t\t%p\n",CLQ);
    printf("&[CLQ_Free1]\t\t%p\n",&CLQ);
  
    CLQ_MakeEmpty(&CLQ);
    printf("[CLQ_Free2]\t\t%p\n",CLQ);
    printf("&[CLQ_Free2]\t\t%p\n",&CLQ);

}
//设空
void CLQ_MakeEmpty(ClnkQueue ** CLQ){
    printf("[MakeEmpty1]\t\t%p \n",*CLQ);
    printf("&[MakeEmpty1]\t\t%p \n",CLQ);

    //为空的情况
    if(CLQ_IsEmpty(*CLQ)) return;

    ClnkQueue * nextNode = (*CLQ)->next;
    ClnkQueue * nextNode2;
    do{
        nextNode2 = nextNode->next;
        free(nextNode);
        nextNode = nextNode2;
    }while(nextNode!=(*CLQ));
    free(*CLQ);
    *(CLQ) = NULL;
    printf("[MakeEmpty2]\t\t%p \n",*CLQ);
    printf("&[MakeEmpty2]\t\t%p \n",CLQ);

}
