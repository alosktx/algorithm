#include "linkedstack.h"
//初始化函数
void InitLinkedStack(LinkedStack * LS){
    LS->stack = (LinkedList*)malloc(sizeof(LinkedList));
    InitLinkedList(LS->stack);
}

//入栈
void Push(LinkedStack * LS, ElementType item){
    //当前位置一直为0 作栈顶使用
    InsertAt(LS->stack,item);
}

//出栈
ElementType Pop(LinkedStack * LS){
    //空栈
    if(!LS->stack->size){
        printf("[Pop] The stack is empty!\n");
        exit(0);
    }
    
    //当前位置一直为0 作栈顶使用
    ElementType item = GetData(LS->stack);
    DeleteAt(LS->stack);
    return item;
}

//取栈顶的元素
ElementType Top(LinkedStack * LS){
    if(!LS->stack->size){
        printf("[Top] The stack is empty!\n");
        exit(0);
    }
    return GetData(LS->stack);
}