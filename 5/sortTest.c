#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include"mydefine.h"
#include"sort.h"

void AssertSort(ForSort * FS, int len){
    for(int i =0;i<len-1;i++){
        assert(FS[i].key<=FS[i+1].key);
    }
    printf("PASS!\n");
}

void AssertMoreSort(MoreSort * MS){
    MoreSort * p;
    for(p = MS;p->next!=NULL;p = p->next){
        ElementType pre = p->key[2]*100+p->key[1]*10+p->key[0];
        ElementType aft = p->next->key[2]*100+p->next->key[1]*10+p->next->key[0];
        // printf("%d <= %d\n",pre,aft);
        assert(pre <= aft);
    }
    printf("PASS!\n");
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    ForSort *FS = (ForSort*)malloc(sizeof(ForSort)*LENGTH);
    
    printf("\n DirectInsertionSort()\n\n");
    for(int i= 0;i<LENGTH;i++){
        InitForSort(FS+i,rand()%LENGTH+1);
    }
    Printsort(FS,LENGTH);
    DirectInsertionSort(FS,LENGTH);
    Printsort(FS,LENGTH);
    AssertSort(FS,LENGTH);

    printf("\n BinaryInsertionSort()\n\n");
    for(int i= 0;i<LENGTH;i++){
        InitForSort(FS+i,rand()%LENGTH+1);
    }
    Printsort(FS,LENGTH);
    BinaryInsertionSort(FS,LENGTH);
    Printsort(FS,LENGTH);
    AssertSort(FS,LENGTH);

    printf("\n ShellInsertionSort()\n\n");
    for(int i= 0;i<LENGTH;i++){
        InitForSort(FS+i,rand()%LENGTH+1);
    }
    Printsort(FS,LENGTH);
    ShellInsertionSort(FS,LENGTH,LENGTH/2);
    Printsort(FS,LENGTH);
    AssertSort(FS,LENGTH);

    printf("\n DirectSelectSort()\n\n");
    for(int i= 0;i<LENGTH;i++){
        InitForSort(FS+i,rand()%LENGTH+1);
    }
    Printsort(FS,LENGTH);
    DirectSelectSort(FS,LENGTH);
    Printsort(FS,LENGTH);
    AssertSort(FS,LENGTH);

    printf("\n BubbleSwapSort()\n\n");
    for(int i= 0;i<LENGTH;i++){
        InitForSort(FS+i,rand()%LENGTH+1);
    }
    Printsort(FS,LENGTH);
    BubbleSwapSort(FS,LENGTH);
    Printsort(FS,LENGTH);
    AssertSort(FS,LENGTH);

    printf("\n QuickSwapSort()\n\n");
    for(int i= 0;i<LENGTH;i++){
        InitForSort(FS+i,rand()%LENGTH+1);
    }
    Printsort(FS,LENGTH);
    QuickSwapSort(FS,0,LENGTH-1);
    Printsort(FS,LENGTH);
    AssertSort(FS,LENGTH);

    printf("\n RadixAssignmentSort()\n\n");

    MoreSort * MS = (MoreSort*)malloc(sizeof(MoreSort)*LENGTH);
    //先进行连接
    for(int i = 0;i<LENGTH -1;i++){
        (MS+i)->next = (MS+i+1);
    }
    (MS+LENGTH-1)->next = NULL;
    MoreSort * p;
    //随机化数据
    int i = DWIDTH;
    while(i--){
        for(p = MS;p!=NULL;p=p->next){
            p->key[i] = rand()%10;   
        }
    }
    //打印
    PrintMoreSort(MS);
    RadixAssignmentSort(MS,0,9,DWIDTH);
    AssertMoreSort(MS);

    p=NULL;
    free(MS);


    printf("\n MergeSort()\n\n");
    for(int i= 0;i<LENGTH;i++){
        InitForSort(FS+i,rand()%LENGTH+1);
    }
    Printsort(FS,LENGTH);
    MergeSort(FS,LENGTH);
    Printsort(FS,LENGTH);
    AssertSort(FS,LENGTH);

    return 0;
}
