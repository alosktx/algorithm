#include "mydefine.h"
#include<stdlib.h>
struct cnode{
    struct cnode *next;
    ElementType data;
};
typedef struct cnode CNode;
//初始化结点
void InitCNode(CNode *,ElementType);
//插入结点
void InsertCNAfter(CNode *,CNode *);
//删除本结点后继
CNode * DeleteCNAfter(CNode *);
//申请新结点
CNode * NewCNode(ElementType);
//释放结点
void FreeCNode(CNode *);
