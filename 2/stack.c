#include <stdio.h>
#include <stdlib.h>

enum boolean {FALSE, TRUE};
typedef enum boolean Bool;
typedef int ElementType;

struct stack{
    int top;
    ElementType *elements;
    int MaxSize;
};
typedef struct stack Stack;

void InitStack(Stack * S,int sz){ /*创建栈空间，生成一个空栈*/
    S->MaxSize = sz;
    S->elements = (ElementType*)malloc(sizeof(ElementType)*S->MaxSize);
    S->top = -1;
}

Bool IsEmpty(Stack * S){
    return (Bool)(S->top == -1);
}

Bool IsFull(Stack * S){
    return (S->top == S->MaxSize-1) ? TRUE : FALSE;
}

void FreeStack(Stack * S){
    free(S->elements);
}

Bool Push(Stack * S, ElementType element){
    if(!IsFull(S)){
        S->elements[++(S->top)] = element;
        return TRUE;
    }else{
        printf("[Push] The stack is full!\n");
        return FALSE;
    }
}

ElementType Pop(Stack * S){
    if(!IsEmpty(S)){
        return S->elements[(S->top)--];
    }else{
        printf("[Pop] The stack is empty!\n");
        return NULL;
    }
}

ElementType GetTop(Stack * S){
    if(!IsEmpty(S)){
        return S->elements[S->top];
    }else{
        printf("[GetTop] The stack is empty!\n");
        return NULL;
    }
}

void MakeEmpty(Stack * S){
    S->top=-1;
} 



//后缀表达式求值
void EvaluatePostfix(void){
    Stack*spnd = (Stack*)malloc(sizeof(Stack));
    char buf[80];//限定表达式最长位79个字符
    //buf or &buf
    printf("Please enter postfix expression\n");
    //%s or %c
    scanf("%s",buf);
    InitStack(spnd,80);
    int i = 0;
    ElementType temp1;
    ElementType temp2;
    while(buf[i]!='\0'){
        switch(buf[i]){
            case '+':
                temp1 = Pop(spnd);
                temp2 = Pop(spnd);
                Push(spnd,temp2+temp1);
                printf("%d+%d=%d\n",temp2,temp1,temp2+temp1);
                break;
            case '-':
                temp1 = Pop(spnd);
                temp2 = Pop(spnd);
                //temp2 和 temp1 顺序一定不要弄反了
                Push(spnd,temp2-temp1);
                printf("%d-%d=%d\n",temp2,temp1,temp2-temp1);
                break;
            case '*':
                temp1 = Pop(spnd);
                temp2 = Pop(spnd);
                Push(spnd,temp2*temp1);
                printf("%d*%d=%d\n",temp2,temp1,temp2*temp1);
                break;
            case '/':
                temp1 = Pop(spnd);
                temp2 = Pop(spnd);
                Push(spnd,temp2/temp1);
                printf("%d/%d=%d\n",temp2,temp1,temp2/temp1);
                break;
            default:
                //字符转换成数值
                Push(spnd,(int)(buf[i]-48));
                printf("%d\n",(int)(buf[i]-48));
                break;
        }
        i++;
    }
    printf("value:%d\n",Pop(spnd));
    FreeStack(spnd);
}

int main(int argc, char const *argv[])
{
    // {
    //     Stack * S = (Stack*)malloc(sizeof(Stack));
    //     InitStack(S,10);
    //     for(int i = 0 ;i<11;i++){
    //         Push(S,i+1);
    //     }

    //     for(int i = 0 ;i<11;i++){
    //         printf("%d\n",GetTop(S));
    //         Pop(S);
    //     }

    //     FreeStack(S);
    //     free(S);
    // }

    {
        EvaluatePostfix();
    }
    return 0;
}
