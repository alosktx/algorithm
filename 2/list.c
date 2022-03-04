#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elementtype;

struct linearList{
    elementtype *data;
    int MAXSIZE;//最大长度
    int last;//当前长度
};
typedef struct linearList LinearList;

void initList(LinearList *l, int maxsize){
    //MAXSIZE大小的判断
    if(maxsize <= 0){
        printf("MAXSIZE must be greater than 0!");
    }else{
        l->MAXSIZE = maxsize;
        l->last = 0;
        //elementtype*转化
        l->data = (elementtype*)malloc(sizeof(elementtype) * (l->MAXSIZE));
    }
}
void freeList(LinearList *l){
    free(l->data);
}
//bool 变量C语言未定义
bool listEmpty(LinearList * l){
    //l->last == 0 or l->last <= 0 同时可以判断自减错误的情况
    return (l->last <= 0) ? true : false;
}
bool listFull(LinearList * l){
    //l->last == l->MAXSIZE or l->last >= l->MAXSIZE 同时可以判断自加错误的情况
    return (l->last >= l->MAXSIZE) ? true : false;
}
int listLength(LinearList * l){
    return l->last;
}
elementtype getElem(LinearList * l, int i){
    //i>=l->last or i==l->last
    if(i<0||i>=l->last){
        printf("wrong num!");
    }else{
        return l->data[i];
    }
}
int locateElem(LinearList * l, elementtype sdata){
    for(int i = 0;i < l->last;i++){
        if(l->data[i] == sdata)
            return i;
    }
    return -1;
}
bool insertElem(LinearList * l, int i, elementtype idata){
    if(i<0||i>l->last||l->last==l->MAXSIZE){
        return false;
    }else{
        //序号问题
        for(int j = l->last-1; j >= i; j--){
            l->data[j+1] = l->data[j];
        }
        l->data[i]  = idata;
        l->last++;
        return true;
    }
}
bool deleteElem(LinearList *l, int i){
    //必须是i>=l->last 不能是 i>l->last
    if(i<0||i>=l->last||l->last==0){
        printf("[deleteElem] wrong num!\n");
        return false;
    }else{
        //序号问题，要注意删除的节点的序号是否正确
        for(int j = i; j<l->last-1; j++){
            l->data[j] = l->data[j+1];
        }
        l->last--;
        return true;
    }
}
void printList(LinearList *l){
    for(int i = 0; i<l->last; i++){
        printf("%d\t",l->data[i]);
    }
    printf("\n");
}
int main(){ 
    LinearList *l = (LinearList*)malloc(sizeof(LinearList));

    initList(l,5);
    printf("Length:%d\n",listLength(l));
    printList(l);

    insertElem(l,0,11);
    printf("Length:%d\n",listLength(l));
    printList(l);

    insertElem(l,0,22);
    printf("Length:%d\n",listLength(l));
    printList(l);

    insertElem(l,0,33);
    printf("Length:%d\n",listLength(l));
    printList(l);

    insertElem(l,0,44);
    printf("Length:%d\n",listLength(l));
    printList(l);

    insertElem(l,0,55);
    printf("Length:%d\n",listLength(l));
    printList(l);

    if(insertElem(l,0,66))
    {
        printf("insert success！\n");
        printList(l);
    }
    else{
        printf("insert failed!\n");
        printList(l);
    }

    if(listFull(l)){
        printf("List is full\n");
    }
    printf("Length:%d\n",listLength(l));
    printList(l);

    deleteElem(l,5);
    printf("Length:%d\n",listLength(l));
    printList(l);

    deleteElem(l,3);
    printf("Length:%d\n",listLength(l));
    printList(l);

    if(listEmpty(l)){
        printf("list is empty\n");
    }else{
        printf("list is not empty\n");
    }

    printf("the 55 is at %d\n",locateElem(l,55));
    printf("the 3rd is %d\n",getElem(l,2));

    freeList(l);

    return 0;
}