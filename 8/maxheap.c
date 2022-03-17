#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "maxheap.h"
//求堆中元素个数
int SizeInMaxHeap(MaxHeap * xheap){
    return xheap->heapsize;
}
//返回大根堆顶的元素
int MaxInMaxHeap(MaxHeap * xheap){
    if(xheap->heapsize == 0){
        printf("[]underflow\n");
        exit(1);
    }
    return xheap->heap[0];
}
//初始化大根堆
void InitMaxHeap(MaxHeap * xheap, int MaxHeapSize){
    xheap->Maxsize = MaxHeapSize;
    xheap->heap = (int*)malloc(sizeof(int)*xheap->Maxsize);
    xheap->heapsize = 0;
}
//在堆中插入一个新元素
void InsertMaxHeap(MaxHeap * xheap, int insertHeapData){
    if(xheap->heapsize == xheap->Maxsize){
        printf("maxheap.c [Insert] Overflow\n");
        exit(1);
    }
    //新堆中最后一个元素（最右边叶子结点的元素）的下标
    int i = xheap->heapsize++;
    //从下向上处理，直到堆顶为止
    while( i!=0 && insertHeapData > xheap->heap[(i-1)/2] ){
        //父结点元素下移
        xheap->heap[i] = xheap->heap[(i-1)/2];
        //下标上移，向上处理
        i = (i-1)/2;
    }
    xheap->heap[i] = insertHeapData;
}
//删除堆顶的元素,保存到变量tempHeapTopData中
void DeleteMaxHeap(MaxHeap * xheap, int * tempHeapTopData){
    //当前堆中最后一个元素（最右边叶子结点的元素）
    int lastHeapData;
    //当前处理的父结点的下标，初始化为堆顶
    int fatherPos = 0;
    //当前处理的子结点的下标，初始化为堆顶的左子结点
    int childPos = 1;

    if(xheap->heapsize == 0){
        printf("maxheap.c [DeleteMaxHeap] underflow\n");
        exit(1);
    }else{
        *tempHeapTopData = xheap->heap[0];
        lastHeapData = xheap->heap[--(xheap->heapsize)];
        while(childPos < xheap->heapsize ){
            if( (childPos+1) < xheap->heapsize && xheap->heap[childPos] < xheap->heap[childPos+1] )
                childPos++;
            if( lastHeapData >= xheap->heap[childPos] )
                break;
            //元素上移
            xheap->heap[fatherPos] = xheap->heap[childPos];
            fatherPos = childPos;
            childPos = childPos*2 + 1;
        }
        xheap->heap[fatherPos] = lastHeapData;
    }
}

/*构建大根堆, 因为本大根堆的树是从0下标开始算起的，所以如果一个父结点的下标为i，则其左子结点的下标为 2*i+1 ，其右子结点的坐标为 2*i+2 ;
如果一个子结点的下标为 ic，则其父结点的下标为 (ic-1)/2 (不管这个子结点是父结点的左子结点还是右子结点)

参数传递时要保证 Arraysize >= size
*/
void MakeHeap(MaxHeap * xheap, int a[], int size, int Arraysize){
    //重新构建
    free(xheap->heap);
    //重新给堆中存取数据的数组分配空间
    xheap->heap = (int*)malloc(sizeof(int)*Arraysize);
    //数组复制
    memcpy(xheap->heap,a,sizeof(int)*size);
    xheap->heapsize = size;
    xheap->Maxsize = Arraysize;

    //用于保存当前处理的父结点变量 的数据
    int tempHeapFatherData;
    //当前处理的子结点的下标
    int childPos;

    //从当前堆中最右边叶子结点的父结点开始处理，一直向上处理直到根结点(下标为0)
    for(int fatherPos = (xheap->heapsize - 2)/2; fatherPos>=0; fatherPos--){
        tempHeapFatherData = xheap->heap[fatherPos];
        //左子结点
        childPos = 2*fatherPos+1;
        //从上向下循环处理，直到为childPos 表示外结点
        while(childPos < xheap->heapsize){
            //从左右子结点中选出更大的结点的下标
            if( (childPos+1) < xheap->heapsize && xheap->heap[childPos] < xheap->heap[childPos+1] ){
                childPos++;
            }
            //父结点的值 >= 子结点的值
            if( tempHeapFatherData >= xheap->heap[childPos]){
                break;
            }
            //子结点的值上移至父结点
            xheap->heap[(childPos-1)/2] = xheap->heap[childPos];
            //向下处理
            childPos = childPos*2+1;
        }
        xheap->heap[(childPos-1)/2] = tempHeapFatherData;
    }
}   
//堆排序
void Heapsort(int a[],int n){
    MaxHeap * xheap = (MaxHeap*)malloc(sizeof(MaxHeap));
    int heapTopData;

    MakeHeap(xheap,a,n,n);
    printf("After MakeHeap:\n");
    PrintHeap(xheap);
    AssertHeap(xheap);

    printf("Start to Delete heap top for sort\n");
    for(int i = n-1; i>=0; i--){
        DeleteMaxHeap(xheap, &heapTopData);
        PrintHeap(xheap);
        AssertHeap(xheap);
        a[i] = heapTopData;
    }
}

//打印当前堆
void PrintHeap(MaxHeap * xheap){
    for(int i = 0;i<xheap->heapsize;i++)
        printf("%d ",xheap->heap[i]);
    printf("\n");
}

//测试堆中元素是否符合要求
void AssertHeap(MaxHeap * xheap){
    for(int i = (xheap->heapsize-2)/2; i>=1; i--){
        assert( xheap->heap[i] <= xheap->heap[(i-1)/2] );
    }
    printf("HEAP PASS!\n");
}