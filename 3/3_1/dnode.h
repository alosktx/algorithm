#include "mydefine.h"
struct dNode{
    struct dNode * prev;
    struct dNode * next;
    ElementType data;
};
typedef struct dNode DNode;
//初始化
void InitDNode(DNode *,ElementType);
//在当前结点前插入结点
void InsertDNBefore(DNode *,DNode *);
//在当前结点后插入结点
void InsertDNAfter(DNode *,DNode *);
//删除当前当前结点
DNode * DeleteDNAt(DNode *);
//申请空间
DNode * NewDNode(ElementType);
//释放空间
void FreeDNode(DNode *);