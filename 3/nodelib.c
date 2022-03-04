#include"nodelib.h"
//打印链表
void PrintList(Node * head, enum appendNewline addn1){
    Node * currPtr = head;
    while(currPtr !=NULL){
        if(addn1 == addNewLine){
            printf("%d\n",currPtr->data);
        }else{
            printf("%d ",currPtr->data);
        }
        currPtr=currPtr->next;
    }
}

//单链表中基于表目的查找
int Find(Node * head, ElementType item){
    Node * currPtr = head;
    while(currPtr!=NULL){
        if(item == currPtr->data){
            return 1;
        }
        currPtr = currPtr->next;
    }
    return 0;
}

//在单链表的头部插入一个新的单链表结点
void InsertFront(Node ** head, ElementType item){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = *head;
    *head = newNode;
}
//删除单链表的头结点
void DeleteAt(Node ** head){
    Node * deleteHeadNode = *head;
    if(*head!=NULL){
        *head = (*head)->next;
        free(deleteHeadNode);
    }else{
        printf("The head node is NULL!");
    }
}
//删除单链表中值为key的结点
void Deletekey(Node ** head,ElementType key){
    Node * currPtr = *head;
    Node * prePtr = NULL;
    if(currPtr == NULL)
        return;
    while(currPtr!=NULL && currPtr->data!=key){
        prePtr  = currPtr;
        currPtr = currPtr->next;
    }
    //退出循环的情况是currPtr->data == key ，即找到了key
    if(currPtr!=NULL){
        //找到为key值的是第一个结点的情况
        if(prePtr == NULL){
            //直接移动头指针
            *head = (*head)->next;
        }else{
            DeleteAfter(prePtr);
        }
        free(currPtr);
    }
}
//在有序单链表中插入新结点(按值从小到大的顺序进行插入)
void InsertOrder(Node ** head,ElementType item){
    Node * currPtr = *head;
    Node * prevPtr = NULL;
    Node * newNode;

    while(currPtr!=NULL){
        if(item<currPtr->data)
            break;
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }
    //要插入到头结点
    if(prevPtr == NULL){
        InsertFront(head,item);
    }else{
        //此处也可使用 GetNode(item,currPtr);
        newNode = GetNode(item,NULL);
        InertAfter(prevPtr,newNode);
    }
}
//删除整个单链表
void ClearList(Node ** head){
    Node * currPtr = *head;
    Node * nextPtr = currPtr->next;
    while(currPtr!=NULL){
        nextPtr = currPtr->next;
        free(currPtr);
        currPtr = nextPtr;
    }
    head = NULL;
}

