typedef int ElementType;
enum boolean {FALSE,TRUE};
typedef enum boolean Bool;
struct CLQNode{
    ElementType data;
    struct CLQNode * next;
};
typedef struct CLQNode ClnkQueue;
//循环队列,只用尾结点指针
//入队
void CLQ_In(ClnkQueue **,ElementType);
//出队
ElementType CLQ_Out(ClnkQueue **);
//队头元素
ElementType CLQ_Front(ClnkQueue *);
//打印队列
void CLQ_Print(ClnkQueue *);
//判空
Bool CLQ_IsEmpty(ClnkQueue *);
//清除
void CLQ_Free(ClnkQueue *);
//设空
void CLQ_MakeEmpty(ClnkQueue **);




