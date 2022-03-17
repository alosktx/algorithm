#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include"maxheap.h"
#define LENGTH 20
void AssertSort(int * FS, int len){
    for(int i =0;i<len-1;i++){
        assert(FS[i]<=FS[i+1]);
    }
    printf("PASS!\n");
}

void initialA(int * A, int len){
    srand(time(NULL));
    for(int i = 0;i<len;i++){
        A[i] = rand()%LENGTH+1;
    }
}

void printA(int * A, int len){
    for(int i =0;i<len;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int a[LENGTH];

    initialA(a,LENGTH);

    printA(a,LENGTH);

    Heapsort(a,LENGTH);

    printA(a,LENGTH);

    AssertSort(a,LENGTH);

    printf("\n\nTest InitMaxHeap() and InsertMaxHeap() *************************\n");
    MaxHeap * xheap = (MaxHeap*)malloc(sizeof(MaxHeap));

    InitMaxHeap(xheap,LENGTH);
    PrintHeap(xheap);
    AssertHeap(xheap);
    
    for(int i =0; i<LENGTH; i++){
        InsertMaxHeap(xheap,rand()%LENGTH+1);
        PrintHeap(xheap);
        AssertHeap(xheap);
    }

    return 0;
}
