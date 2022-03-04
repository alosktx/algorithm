#include<stdlib.h>
#include<stdio.h>
//这两个一定不要写反了，FALSE在前表示枚举值为0,TRUE在后面表示枚举值为1，不然后面遇到问题很难发现
enum boolean {FALSE,TRUE};

typedef enum boolean Bool;
typedef int Elementype;

struct queue{
    int rear, front;
    Elementype *elements;
    int MaxSize;
};
typedef struct queue Queue;

void InitQueue(Queue * Q,int sz){
    Q->MaxSize = sz;
    Q->elements = (Elementype*)malloc(sizeof(Elementype)*Q->MaxSize);
    Q->rear = Q->front = 0;
}

void FreeQueue(Queue * Q){
    free(Q->elements);
}

void MakeEmpty(Queue * Q){
    Q->front = Q->rear = 0;
}

Bool IsEmpty(Queue * Q){
    return (Bool)(Q->front == Q->rear);
}

Bool IsFull(Queue *Q){
    // return (Q->front == (Q->rear+1)%(Q->MaxSize)) ? TRUE : FALSE;
    //最好使用下面这种写法，返回的比较的真假，真则为1,假则为0,再转换成TRUE，FALSE，即使TRUE和FALSE在枚举时顺序写反了，后续判断操作时影响
    return (Bool)(Q->front == (Q->rear+1)%(Q->MaxSize));

}

int Length(Queue *Q){
    return (Q->rear - Q->front + Q->MaxSize)% (Q->MaxSize);
}

Bool EnQueue(Queue * Q,Elementype element){
    if(IsFull(Q)){
        printf("[EnQueue] The Queue is Full\n");
        return FALSE;
    }else{
        Q->elements[Q->rear] = element;
        Q->rear = (Q->rear+1)%(Q->MaxSize);
        return TRUE;
    }
}

Elementype DeQueue(Queue * Q){
    if(IsEmpty(Q)){
        printf("[Dequeue] The Queue is empty\n");
        return -11;
    }else{
        Elementype temp = Q->elements[Q->front];
        Q->front = (Q->front+1)%(Q->MaxSize);
        return temp;
    }
}

Elementype GetFront(Queue * Q){
    if(IsEmpty(Q)){
        printf("[Dequeue] The Queue is empty\n");
        return -11;
    }else{
        Elementype temp = Q->elements[Q->front];
        return temp;
    }
}
int main(int argc, char const *argv[])
{
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    InitQueue(Q,10);

    for (int i = 0; i < 10; i++){
        EnQueue(Q,i+1);
        printf("length1:%d\n",Length(Q));
    }

    printf("\n\n\n");

    for (int i = 0; i<10; i++){
        printf("GetFront: %d\n",GetFront(Q));
        printf("length2:%d\n",Length(Q));
        DeQueue(Q);
    }

    printf("\n\n\n");

    for (int i = 0; i < 10; i++){
        EnQueue(Q,i+1);
        printf("length:%d\n",Length(Q));
    }

    printf("\n\n\n");

    MakeEmpty(Q);
    printf("length3:%d\n",Length(Q));

    FreeQueue(Q);

    return 0;
}

