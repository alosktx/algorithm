#include<time.h>
#include <assert.h>
#include "node.h"
#include "nodelib.h"
int main(){
    //初始化链表,头指针必须设置为NULL
    Node * head=NULL;
    printf("first: %p\n",head);
    Node * currPtr;
    //依次插入10个随机整数数据
    srand(time(NULL));
    for(int i =0;i<10;i++){
        InsertOrder(&head,rand()%10 + 1);
    }
    PrintList(head,noNewline);
    printf("\n");
    //键盘输入一个值key
    int key;
    printf("Please enter the key:");
    scanf("%d",&key);

    //单链表中基于表目的查找
    if(Find(head,key)){
        printf("There is key int the list!\n");
    }else{
        printf("No key in the list!");
    }

    //统计值为key的结点的数目
    int count = 0;
    currPtr = head;
    while(currPtr!=NULL){
        if(currPtr->data == key)
            count++;
        currPtr = currPtr->next;
    }
    printf("The count of key is:%d\n",count);

    //删除值为key的结点
    Deletekey(&head,key);
    PrintList(head,noNewline);
    printf("\n");

    //删除单链表的头结点
    DeleteAt(&head);
    PrintList(head,noNewline);
    printf("\n");

    //删除整个单链表
    printf("Delete All the list!\n");
    ClearList(&head);
    printf("%p\n",&head);
    printf("last: %p\n",head);

    // assert(head == NULL);
    // PrintList(head,noNewline);
    // printf("f\n");

    return 0;
}