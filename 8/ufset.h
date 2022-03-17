#define MaxSize 100
//并查集
typedef struct ufset{
    int Parent[MaxSize];
    int size;
}UFSet;

//初始化并查集
void CreatUFSet(UFSet * S, int n);
//查找元素i所属的并察集的子集
int FindUFSet(UFSet * S, int i);
//合并运算
void UnionUFSet(UFSet * S,int i,int j);