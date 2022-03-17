//大根堆
struct maxHeap{
    int heapsize,Maxsize;
    int * heap;
};
typedef struct maxHeap MaxHeap;
//求堆中元素个数
int SizeInMaxHeap(MaxHeap * xheap);
//返回大根堆顶的元素
int MaxInMaxHeap(MaxHeap * xheap);
//初始化大根堆
void InitMaxHeap(MaxHeap * xheap, int MaxHeapSize);
//在堆中插入一个新元素
void InsertMaxHeap(MaxHeap * xheap, int insertHeapData);
//删除堆顶的元素
void DeleteMaxHeap(MaxHeap * xheap, int * tempHeapTopData);
//构建大根堆
void MakeHeap(MaxHeap * xheap, int a[], int size, int Arraysize);
//堆排序
void Heapsort(int a[],int n);
//打印当前堆
void PrintHeap(MaxHeap * xheap);
//测试堆中元素是否符合要求
void AssertHeap(MaxHeap * xheap);