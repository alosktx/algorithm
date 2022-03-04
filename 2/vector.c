#include<stdio.h>
#include<stdlib.h>

enum boolean {FALSE, TRUE};
typedef enum boolean Bool;
typedef int ElementType;

struct vector
{
    ElementType *elements;
    int ArraySize;
    int VectorLength;
};
typedef struct vector Vector;

void GetArray(Vector * V)                    /*申请向量的存储空间*/
{
    V->elements=(ElementType*)malloc(sizeof(ElementType)*V->ArraySize);
    if(V->elements == NULL)
    {
        printf("elements allowed error!");
    }
}

void InitVector(Vector * V,int sz)           /*初始化一空间向量*/
{
    //sz<=0 or sz<0
    if(sz<=0){
        printf("[InitVector] wrong number!\n");
    }else{
        V->ArraySize = sz;
        V->VectorLength = 0;
        GetArray(V);
    }
}

ElementType GetNode(Vector * V,int i){      /*取向量的第i个项目*/
    //>= or >
    if(i<0||i>=V->VectorLength){
        printf("[GetNode] wrong number\n");
        return -13;
    }else{
        return V->elements[i];
    }
}   

void FreeVector(Vector * V){                  /*释放向量存储空间*/
    free(V->elements);
}

int Find(Vector * V,ElementType element){             /*在向量中查找*/
    for(int i = 0;i<V->VectorLength;i++){
        if(element == V->elements[i]){
            return i;
        }
    }
    return -1;
}

Bool Insert(Vector *V,ElementType element,int i){      /*向量的插入*/
    if(V->ArraySize == V->VectorLength){
        printf("The Vector is full!");
        return FALSE;
    }
    if(i<0||i>V->VectorLength){
        printf("[Insert] wrong number!\n");
        return FALSE;
    }
    for(int j = V->VectorLength-1;j>=i;j--){
        V->elements[j+1] = V->elements[j];
    }
    V->elements[i]=element;
    V->VectorLength++;
    return TRUE;
}

Bool Remove(Vector *V,int i){                /*删除向量的第i个表目*/
    if(V->VectorLength == 0){
        printf("The Vector is empty!");
        return FALSE;
    }
    if(i<0||i>=V->VectorLength){
        printf("[Remove] wrong number!\n");
        return FALSE;
    }
    for(int j=i;j<V->VectorLength-1;j++){
        V->elements[j]=V->elements[j+1];
    }
    V->VectorLength--;
    return TRUE;
}

void PrintVector(Vector * V){
    for(int i = 0;i<V->VectorLength;i++){
        printf("%d\t",V->elements[i]);
    }
    printf("\n");
}

Vector * Union(Vector *Va, Vector *Vb){ /*并运算*/
    Vector *Vc = (Vector*)malloc(sizeof(Vector));
    int m = Va->VectorLength;
    int n = Vb->VectorLength;
    InitVector(Vc,m+n);
    ElementType x;
    int i = 0;
    int j = 0;
    while(j<m){
        //一般不直接使用 Va->elements[j]来取值，破坏了封装
        x = GetNode(Va,j);
        Insert(Vc,x,j);
        j++;
    }
    while(i<n){
        x = GetNode(Vb,i);
        if(-1 == Find(Va,x)){
            Insert(Vc,x,j);
            j++;
        }
        i++;
    }
    //不要忘记返回
    return Vc;
}

Vector * Intersection(Vector *Va, Vector *Vb){ /*交运算*/
    Vector *Vc = (Vector*)malloc(sizeof(Vector));
    int m = Va->VectorLength;
    int n = Vb->VectorLength;
    int length = (m>n)?n:m;
    InitVector(Vc,length);
    ElementType x;
    int i = 0;
    int j = 0;
    while(i<m){
        x = GetNode(Va,i);
        if(-1!=Find(Vb,x)){
            Insert(Vc,x,j);
            j++;
        }
        i++;
    }
    //不要忘记返回
    return Vc;
}

void Josephus(Vector * P,int n,int s,int m){ /*约瑟夫问题*/
    for(int i = 0;i<n;i++){
        Insert(P,i+1,i);
    }
    PrintVector(P);
    int next;
    for(int j = n;j>=1;j--){
        s = (s+m-1)%j;
        if(s == 0){
            s = j;
        }
        printf("s:%d\t rnode:%d \n",s,GetNode(P,s-1));
        Insert(P,GetNode(P,s-1),n);
        PrintVector(P);
        Remove(P,s-1);
        PrintVector(P);
    }
}

int main(){
    Vector *P = (Vector*)malloc(sizeof(Vector));
    InitVector(P,10);
    Josephus(P,5,1,2);
    PrintVector(P);
    return 0;
}