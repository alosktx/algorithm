#pragma once
#include<stdio.h>
#include<stdlib.h>
#include "mydefine.h"

struct forSort{
    ElementType key;
};
typedef struct forSort ForSort;

struct moreSort{
    //假设排序码有3位
    ElementType key[DWIDTH];     
    struct moreSort * next;
};
typedef struct moreSort MoreSort;

void InitForSort(ForSort * FS, ElementType a);

void Printsort(ForSort * FS, int len);

//直接插入排序
void DirectInsertionSort(ForSort A[], int len);

//折半插入排序
void BinaryInsertionSort(ForSort A[], int len);

//shell插入排序
void ShellInsertionSort(ForSort A[], int len, int s);

//直接选择排序
void DirectSelectSort(ForSort A[], int len);

//树形排序

//冒泡交换排序
void BubbleSwapSort(ForSort A[], int len);

//快速交换排序
void QuickSwapSort(ForSort A[], int low, int hign);

void PrintMoreSort(MoreSort * MS);

//基数分配排序
//组成排序码基数的下界Clow， 上界Chigh，排序码的最大长度d
void RadixAssignmentSort(MoreSort * MS, int clow, int chigh, int d);

//归并排序
//二路归并排序
void MergeSort(ForSort A[],int len);
//一趟两组归并
void OnePassMerge(ForSort Dst[], ForSort Src[], int sublen, int len);
//两组归并
void TwoWayMerge(ForSort Dst[], ForSort Src[], int s ,int e1, int e2);
