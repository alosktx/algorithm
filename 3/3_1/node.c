#include"node.h"

//对结点进行N初始化处理，并指向一个结点ptr
void InitNode(Node *N,ElementType item ,Node *ptr){
    N->data = item;
    N->next = ptr;
}
//在当前结点N后，插入结点p
void InertAfter(Node *N,Node *p){
    p->next = N->next;
    N->next = p;
}
//删除当前结点的一个后继结点
Node* DeleteAfter(Node *N){
    Node * ptr = N->next;
    //判断当前结点是否没有后继结点
    if(ptr == NULL)//没有
        return NULL;
    N->next = ptr->next;
    return ptr;
}
//创建指向一个结点nextPtr,且数据为item的单链表的结点
Node* GetNode(ElementType item, Node *nextPtr){
    Node * newNode;
    newNode = (Node*)malloc(sizeof(Node));
    //判断申请空间是否成功
    if(newNode == NULL){
        printf("Allow memory failure\n");
        //exit(1)到底是什么意思?
        exit(1);
    }
    InitNode(newNode,item,nextPtr);
    return newNode;
}
void FreeNode(Node * N){
    if(!N){
        printf("Invalid node pointer\n");
        //?
        return;
    }
    free(N);
}
