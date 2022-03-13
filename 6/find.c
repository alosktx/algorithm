#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "find.h"

//折半查找
int BinarySearch(FindData A[], int key, int len){
    int low,mid,high;
    low = 0;
    high = len - 1;
    while(low<=high){
        mid = (low+high)>>2;
        if(key==A[mid].key){
            return mid;
        }else if(key < A[mid].key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}