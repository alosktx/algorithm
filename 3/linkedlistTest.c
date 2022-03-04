#include<time.h>
#include<assert.h>
#include "node.h"
#include "linkedlist.h"
int main(int argc, char const *argv[])
{
    //链表声明及初始化*********************************
    LinkedList *L=(LinkedList*)malloc(sizeof(LinkedList));
    InitLinkedList(L);

    //随机插入10个整数*********************************
    srand(time(NULL));
    for(int i = 0;i<10;i++){
        InsertIAfter(L,rand()%10+1);
    }

    PrintList(L);

    //键盘输入一个值key*********************************
    printf("Enter a key:");
    int key;
    scanf("%d",&key);

    //遍历整个链表*********************************
    int k = 0;
    int count = 0;
    while(k<L->size){
        SetPosition(L,k++);
        if(key == GetData(L))
            count++;
    }
    printf("The Count of %d in the list is: %d \n",key,count);

    //判断表是否为空*********************************
    if(IsEmpty(L)){
        printf("The List is empty!\n");
    }

    //求当前结点后继, 将其设置为当前结点*********************************
    SetPosition(L,5);
    assert(6 == NextINode(L));

    //在当前结点处插入结点*********************************
    //表中
    InsertAt(L,12);
    printf("insert midd: ");
    PrintList(L);

    //表头
    SetPosition(L,0);
    InsertAt(L,11);
    printf("insert head: ");
    PrintList(L);

    //表尾
    SetPosition(L,L->size-1);
    //在当前结点后插入
    InsertIAfter(L,13);
    printf("insert afte: ");
    PrintList(L);

    //删除当前结点*********************************
    //表头
    SetPosition(L,0);
    DeleteAt(L);
    printf("delete head: ");
    PrintList(L);

    //表中
    SetPosition(L,6);
    DeleteAt(L);
    printf("delete midd: ");
    PrintList(L);

    //表尾
    SetPosition(L,L->size-1);
    DeleteAt(L);
    printf("delete afte: ");
    PrintList(L);

    //删除当前结点后继*********************************
    //头结点后
    SetPosition(L,0);
    DeleteIAfter(L);
    printf("delete scon: ");
    PrintList(L);

    //尾结点
    SetPosition(L,L->size-2);
    DeleteIAfter(L);
    printf("delete afte: ");
    PrintList(L);

    //尾结点后
    // SetPosition(L,L->size-1);
    // DeleteIAfter(L);
    // printf("delete wrong: ");
    // PrintList(L);

    //修改数据*********************************
    //修改头
    SetPosition(L,0);
    SetData(L,11);
    printf("Alter  head: ");
    PrintList(L);

    //修改中
    SetPosition(L,3);
    SetData(L,12);
    printf("Alter  midd: ");
    PrintList(L);

    //修改尾
    SetPosition(L,L->size - 1);
    SetData(L,13);
    printf("Alter  afte: ");
    PrintList(L);

    //清空链表*********************************
    Clear(L);
    if(IsEmpty(L)){
        printf("The List is empty!\n");
    }

    free(L);

    return 0;
}
