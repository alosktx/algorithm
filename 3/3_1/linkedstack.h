#include "linkedlist.h"
struct linkedStack{
    LinkedList * stack;
};
typedef struct linkedStack LinkedStack;

//初始化函数
void InitLinkedStack(LinkedStack *);
//入栈
void Push(LinkedStack *, ElementType);
//出栈
ElementType Pop(LinkedStack *);
//取栈顶的元素
ElementType Top(LinkedStack *);