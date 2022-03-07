#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include "clnkqueue.h"
int main(int argc, char const *argv[])
{
    //初始化循环链表,尾指针设为空
    ClnkQueue *CLQ = NULL;
    printf("%p\n",CLQ);
    CLQ_Print(CLQ);

    //随机插入10个数据
    srand(time(NULL));
    for(int i = 0;i<10;i++){
        CLQ_In(&CLQ,rand()%10+1);
        CLQ_Print(CLQ);
    }

    //测试队头元素和出队
    for(int i = 0;i<10;i++){
        printf("Front:%d\n",CLQ_Front(CLQ));
        //基于assert 从左往右 的顺序计算
        assert(CLQ_Front(CLQ) == CLQ_Out(&CLQ));
        CLQ_Print(CLQ);
    }

    //测试free
    for(int i = 0;i<10;i++){
        CLQ_In(&CLQ,rand()%10+1);
    }
    CLQ_Print(CLQ);
    printf("[before]\t\t%p\n",CLQ);
    printf("&[before]\t\t%p\n",&CLQ);
    CLQ_MakeEmpty(&CLQ);//传CLQ地址
    // CLQ_Free(CLQ);//传值
    printf("[after] \t\t%p\n",CLQ);
    printf("&[after]\t\t%p\n",&CLQ);

    // CLQ_Print(CLQ);

    return 0;
}
