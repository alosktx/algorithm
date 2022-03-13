#include"mydefine.h"
typedef struct{
    ElementType key;
}FindData;

//顺序查找
int SeqSearch(FindData A[], int key, int n);

//折半查找
int BinarySearch(FindData A[], int key, int n);

//分块查找