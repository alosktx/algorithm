#include "linkedlist.h"

void InitLinkedList(LinkedList *L){
    L->front = L->rear = L->prevPtr = L->currPtr = NULL;
    L->size = 0;
    L->position = -1;
}

Bool IsEmpty(LinkedList *L){
    return (Bool)(L->size == 0);
}

int NextINode(LinkedList *L){
    //当前结点位置存在
    if(L->position>=0 && L->position < L->size){
        L->prevPtr = L->currPtr;
        L->currPtr = L->currPtr->next;
        L->position++;
    }else{//否则统一设置成表尾位置
        L->position = L->size;
    }
    return L->position;
}
//重置链表当前结点位置，即将当前结点位置计算position, 设置成pos 
int SetPosition(LinkedList *L,int pos){
    //空表
    if(IsEmpty(L)){
        printf("[SetPosition] The LinkedList is empty!\n");
        return -1;
    }
    //超出范围
    if(pos<0 || pos > L->size-1){
        printf("[SetPosition] Wrong pos number!");
        return -1;
    }
    L->currPtr = L->front;
    L->prevPtr = NULL;
    L->position = 0;

    for(int i = 0; i<pos; i++){
        L->prevPtr = L->currPtr;
        L->currPtr = L->currPtr->next;
        L->position++;
    }
    //此时返回的L->position 与 pos 相等，可用于验证？
    return L->position;
}

void InsertAt(LinkedList *L,ElementType item){
    Node * newnode;
    //空表
    if(IsEmpty(L)){
        //此处也可用 GetNode(item, NULL)
        newnode = GetNode(item, L->front);
        L->front=L->rear= newnode;
        L->prevPtr = NULL;// L->prevPtr 本来就是NULL，这句可以不要
        L->position = 0;
    }
    //表头，没有前驱
    else if(!L->prevPtr){
        //此处也可用 GetNode(item, L->currPtr)
        newnode = GetNode(item, L->front);
        L->front = newnode;
    }
    //表中,表尾位置
    else{
        newnode = GetNode(item, L->currPtr);
        InertAfter(L->prevPtr,newnode);
    }
    L->size++;
    //新插入的结点为当前结点
    L->currPtr = newnode;

}

void InsertIAfter(LinkedList *L,ElementType item){
    Node *newNode;

    //1.使用InsertAt来实现,但是相对于重头实现，可重用代码太少，固不用
    // if(L->currPtr == L->rear){
    //     newNode = GetNode(item, NULL);
    //     InertAfter(L->currPtr,newNode);
    //     //此处也可使用 L->prevPtr = L->rear;
    //     L->prevPtr = L->currPtr;
    //     L->rear = newNode;
    //     L->position = L->size;
    //     L->size++;
    //     L->currPtr = newNode;
    // }else{

    // }
    //2.重头实现
    //空表
    if(IsEmpty(L)){
        newNode = GetNode(item,L->front);
        L->front = L->rear = newNode;
        L->position = 0;
    }
    //表尾
    else if(L->currPtr == L->rear){
        newNode = GetNode(item, NULL);
        InertAfter(L->currPtr,newNode);
        //此处也可使用 L->prevPtr = L->rear;
        L->prevPtr = L->currPtr;
        L->rear = newNode;
        L->position = L->size;
    }
    //表头，表中位置
    else{
        newNode = GetNode(item,L->currPtr->next);
        InertAfter(L->currPtr,newNode);
        L->prevPtr = L->currPtr;
        L->position++;
    }
    L->size++;
    // L->prevPtr = L->currPtr; 这句代码不能放在这里，因为这对于空表的情况是不适用的
    L->currPtr = newNode;
}

void DeleteAt(LinkedList *L){
    Node * oldnode;
    //表为空或已到表尾之后的情况，L->current = NULL
    if(!L->currPtr){
        printf("[DeleteAt] The current position is invalid!\n");
        exit(1);
    }
    //表头
    if(!L->prevPtr){
        oldnode = L->currPtr;
        L->front = L->front->next;
    }
    else{
        //表中 表尾
        oldnode = DeleteAfter(L->prevPtr);    
        //表尾要改尾指针
        if(oldnode == L->rear){
            L->rear = L->prevPtr;
        }
    }

    L->currPtr = oldnode->next;
    L->size--;
    FreeNode(oldnode);
}

void DeleteIAfter(LinkedList *L){
    Node * oldnode;
    if(!L->currPtr){
        printf("[DeleteIAfter] The current position is invalid!(The LinkedList is empty)\n");
        exit(1);
    }
    if(L->currPtr == L->rear){
        printf("[DeleteIAfter] The succeed position is invalid!\n");
        exit(1);
    }
    oldnode = DeleteAfter(L->currPtr);
    if(oldnode == L->rear){
        L->rear = L->currPtr;
    }
    L->size--;
    FreeNode(oldnode);
}

ElementType GetData(LinkedList *L){
    //若表为空，或当前结点到达表尾之后
    if(IsEmpty(L) || !L->currPtr){
        printf("[GetData] The current node is not exist!\n");
        exit(1);
    }
    return L->currPtr->data;
}

void SetData(LinkedList *L,ElementType item){
    //若表为空，或当前结点到达表尾之后
    if(IsEmpty(L) || !L->currPtr){
        printf("[SetData] The current node is not exist!\n");
        exit(1);
    }
    L->currPtr->data = item;
}

void Clear(LinkedList *L){
    Node * currnode = L->front;
    Node * nextnode;
    while(currnode){
        nextnode = currnode->next;
        FreeNode(currnode);
        currnode = nextnode;        
    }
    L->front = L->rear = L->prevPtr = L->currPtr = NULL;
    L->size = 0;
    L->position = -1;
}

//打印链表
void PrintList(LinkedList * L){
    int i = 0;
    while(i < L->size){
        SetPosition(L, i++);
        printf("%d ",GetData(L));
    }
    printf("\n");
}