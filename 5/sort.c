#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<memory.h>
#include<string.h>
#include "mydefine.h"
#include "sort.h"

void InitForSort(ForSort * FS, ElementType a){
    FS->key = a;
}

void Printsort(ForSort * FS, int len){
    for(int i = 0; i<len; i++){
        printf("%d ",FS[i].key);
    }
    printf("\n");
}

void PrintMergeSort(ForSort * FS, int len, int sublen){
    int j = 0;
    printf("[");
    for(int i = 0;i<len;i++){
        printf(" %d ",FS[i].key);
        if(++j == sublen){
            printf("] ");
            j = 0;
            if(i!=LENGTH-1){
                printf("[");
            }
        }
    }
    if(len%sublen!=0){
        printf("]");
    }
    printf("\n");
}

//直接插入排序
void DirectInsertionSort(ForSort A[],int len){
    ForSort temp;
    int j;
    for(int i = 1;i<len;i++){
        j = i-1;
        temp = A[i];
        while(j>=0 && temp.key < A[j].key){
            A[j+1] = A[j];
            j--;
            // Printsort(A,len);
        }
        A[j+1] = temp;
        Printsort(A,len);
    }
}

//折半插入排序 二分法
void BinaryInsertionSort(ForSort A[],int len){
    ForSort temp;
    int l,r,m;
    for(int i = 1;i<len;i++){
        l = 0;
        r = i-1;
        temp = A[i];
        while(l<=r){
            m = (l+r)/2;
            if(temp.key < A[m].key)
                r = m-1;//前半部分查找
            else
                l = m+1;//后半部分查找
        }
        for(int j = i-1; j>=l; j--){
            A[j+1] = A[j];
        }
        A[l] = temp;
    }
}

//shell插入排序 s为初始增量
void ShellInsertionSort(ForSort A[], int len, int s){
    ForSort temp;
    int i,j;
    // k>>=1 k=k>>1 右移一位，表示每次减半
    for(int k = s;k>0;k>>=1){
        for(i = k;i<len;i++){
            j = i-k;
            temp  = A[i];
            while(j>=0 && temp.key < A[j].key){
                A[j+k] = A[j];
                j-=k;
            }
            A[j+k] = temp;
        }
    }
}

//直接选择排序
void DirectSelectSort(ForSort A[], int len){
    ForSort temp;
    int j,m;
    for(int i = 0;i<len-1;i++){
        m=i;
        for(j = i+1;j<len;j++){
            if(A[j].key<A[m].key){
                m=j;
            }
        }
        if(i!=m){
            temp = A[i];
            A[i] = A[m];
            A[m] = temp;
        }
        Printsort(A,len);

    }
}

//树形选择排序

//冒泡交换排序
void BubbleSwapSort(ForSort A[], int len){
    int j;
    //交换标志，若一次冒泡过程中未发生交换，则说明已经排好序，无需再进行下一次冒泡
    bool flag;
    ForSort temp;

    for(int i = 0,flag = true;i<len-1 && flag == true;i++){
        flag = false;//最开始没有交换
        for(j = len-1;j>i;j--){
            if(A[j].key < A[j-1].key){
                flag = true; //冒泡过程中发生了交换
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                Printsort(A,len);
            }
        }
    }
}

//快速交换排序
void QuickSwapSort(ForSort A[], int low, int high){
    
    //注意不要忘记返回条件
    if(low >= high) return;

    int i = low;
    int j = high;
    ForSort temp = A[i];
    while(i<j){
        //从最后一个开始比较，直到找到小于等于指定值的数的位置 j 
        while(i<j && temp.key <  A[j].key) j--;
        //将这个小于等于指定值的数移到前面 i "空出" 的位置,此时 j 的值表示后面 ”空出“ 的位置
        if(i<j) A[i++] = A[j];
        //从前面开始比较，接着 填充数 后面的第一个值开始比较，直到找到大于指定值的数的位置 i 
        while(i<j && A[i].key <= temp.key) i++; 
        //将这个大于等于指定值的移到后面 j "空出" 的位置，此时 i 的值表示前面 “空出” 的位置
        if(i<j) A[j--] = A[i];
    }
    assert( i == j);
    A[i] = temp;
    printf("i: %d j: %d temp: %d\n\n",i,j,temp.key);
    Printsort(A,LENGTH);
    //此时i/j 前面的部分的数都比temp小或相等，后面部分的数都比temp大，对前后两部分进行递归操作
    QuickSwapSort(A,low,--j);
    QuickSwapSort(A,++i,high);
}

void PrintMoreSort(MoreSort * MS){
    MoreSort * p;
    for(p=MS;p!=NULL;p=p->next){
        printf("%d->",p->key[2]*100 + p->key[1]*10 + p->key[0]);
    }
    printf("\n");
}

//基数分配排序
//组成排序码基数的下界Clow， 上界Chigh，排序码的最大长度d（一共有d个排序码,本题表示有几个位）
void RadixAssignmentSort(MoreSort *MS, int clow, int chigh, int d){
    //由上界和下界计算 r
    int r = chigh - clow + 1;
    //定义组别结构体，每个结构体都有指向基本 待排序元素 的头，尾指针
    typedef struct{
        MoreSort * head;
        MoreSort * tail;
    }RGroup;
    //声明r个组别结构体(r 个分配队列)
    RGroup * rgroup = (RGroup*)malloc(sizeof(RGroup)*r);
    //定义一个用于操作当前数据，指向基本 待排序元素 的指针p
    MoreSort * p = NULL;
    
    int j;
    //循环d个排序码，依次进行处理 ,不能从头开始排
    for(int i = 0;i<d;i++){
        // PrintMoreSort(MS);
        //初始化r个组别结构体的头尾指针
        for(int k = 0;k < r; k++){
            rgroup[k].head = rgroup[k].tail = NULL;
        }
        //以当前处理的第i个排序码为标准，将 所有待排序元素分配到 r 个组别中，
        //p从MS指针遍历到空为止（即处理完所有元素）
        for(p=MS;p!=NULL;p=p->next){
            //用每个元素当前处理的分配码的值 减去 下界，即可得到此元素需要分配进哪个组别
            j = p->key[i] - clow;
            // printf("j:%d\n",j);
            //如果这个组别之前无元素结点，则将头尾指针初始化指向分配进来的元素
            if(rgroup[j].head == NULL){
                rgroup[j].head = rgroup[j].tail = p;
            }else{
            //否则直接连组别中已有元素结点的后面，并修改尾指针指向分配进来的元素
                rgroup[j].tail->next = p;
                rgroup[j].tail = p;
            }
        }
        //收集r个组别中的数据元素
        j=0;
        //找到第一个有数据的组别j，并记录此组别的头结点到 MS，尾结点到 p
        while(rgroup[j].head == NULL) j++;
        MS = rgroup[j].head;
        p = rgroup[j].tail;
        //从j+1 循环到 r，以此处理这些组别
        for(int k = j+1;k<r;k++){
            //如果头结点不为空，表明此组别类有数据元素，开始处理（使用指针直接可将此组别内的元素一整段连上）
            if(rgroup[k].head!=NULL){
                //p->next 指向此组别头结点 （已链接的数据元素链表的尾结点 连上）
                p->next = rgroup[k].head;
                //p再指向此组别的尾结点，用于下一次连接
                p = rgroup[k].tail;
            }
        }
        //p此时指向最后一个结点，一定要将他的next指针设置为空
        p->next=NULL;
    }

    //输出排序结果
    printf("result:\n");
    PrintMoreSort(MS);
    printf("\n");
    //释放组别结构体
    free(rgroup);
}

//归并排序
//二路归并排序
/*
条件： len >= 0 且 n 为自然数（0,1,3......） 
无需memcpy: 2^(2n-1) < len <= 2^(2n)
需要memcpy: 2^(2n) < len <= 2^(2n+1)
*/
void MergeSort(ForSort A[],int len){
    //声明临时数组B，与A一样的长度
    ForSort * B = (ForSort*)malloc(sizeof(ForSort)*len);
    //声明初始子文件长度sublen，代表下面要归并的原数组中的子文件的长度
    int sublen = 1;
    //A->B B->A循环归并 直到当前要归并的原数组的子文件的长度sublen >=len
    while(sublen < len){
        OnePassMerge(B,A,sublen,len);
        sublen<<=1;
        printf("now B sublen is %d\n",sublen);
        PrintMergeSort(B,len,sublen);
        printf("\n");
        if(sublen < len){
            OnePassMerge(A,B,sublen,len);
            sublen<<=1;
            printf("now A sublen is %d\n",sublen);
            PrintMergeSort(A,len,sublen);
            printf("\n");
        }else{
            memcpy(A,B,sizeof(ForSort)*len);
            printf("the is memcpy now A is:\t");
            PrintMergeSort(A,len,sublen);
        }   
    }
}

//一整趟两组归并，指扫描完整个数组长度，将Src中 sublen长度的子文件归并到，Dst中为2*sublen 长度的子文件
void OnePassMerge(ForSort Dst[], ForSort Src[], int sublen, int len){
    //执行两组归并
    int i;
    for(i = 0; i<len-2*sublen;i+=2*sublen){
        TwoWayMerge(Dst,Src,i,i+sublen-1,i+2*sublen-1);
    }
    //如果尾部还有两个子文件未处理，继续执行两组归并
    if(i< len-sublen){
        TwoWayMerge(Dst,Src,i,i+sublen-1,len-1);
    }else{
    //尾部还有一个子文件未处理,直接复制进Dst
        memcpy(Dst+i,Src+i,sizeof(ForSort)*(len-i));
    }
}

//单次两两归并，将Src中从s开始到e1的子文件，和从e1+1开始到e2的子文件进行选择排序，结果从小到大存放在Dst中从s开始的位置
void TwoWayMerge(ForSort Dst[], ForSort Src[], int s ,int e1, int e2){
    //处理两组文件，直到把其中一组的文件处理完
    int s1,s2;
    for(s1=s,s2=e1+1; s1<=e1 && s2<=e2; ){
        //第一个子文件元素的排序码小
        if(Src[s1].key <= Src[s2].key){
            Dst[s++] = Src[s1++];
        }else{
        //第二个子文件元素的排序码小
            Dst[s++] = Src[s2++];
        }
    }
    //一定会剩余一组文件未处理完，将这组文件剩余未处理的部分直接复制到Dst中
    //第一组未处理完
    if(s1<=e1){
        memcpy(Dst+s,Src+s1,sizeof(ForSort)*(e1-s1 + 1));
    }else{
    //第二组未处理完
        memcpy(Dst+s,Src+s2,sizeof(ForSort)*(e2-s2 + 1));
    }
}



























