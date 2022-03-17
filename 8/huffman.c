#include<stdio.h>
#include<stdlib.h>
#include<huffman.h>
void InitHuffmannode(Huffmannode * hfmNode,int tag,int left,int right){
    hfmNode->tag = tag;
    hfmNode->LeftChild = left;
    hfmNode->RightChild = right;
}
void InitHuffmantree(Huffmantree * hfmTree,int root){
    hfmTree->root = root;
}
//由数组a[] 构造 Huffman树
void makeHuffmantree(Huffmantree * hfmTree,int a[],Huffmannode hfmNode[],int n){
    int minNum1, minNum2;
    int tag1, tag2;
    for(int i = 0;i<n;i++){
        hfmNode[i].weight = a[i];
    }

    //对于n个结点，两两归一，总共需要构造 n-1 次
    for(int i = 1;i<=n-1;i++){
        minNum1 = minNum2 = 32767; //最小值 和 次小值 初始化为 int型所能表示的最大整数，比任何权值都大
        tag1 = tag2  = -1;

        //循环找到当前两个最小的权重值
        for(int j = 0; j<n+i-1; j++){
            if(hfmNode[j].weight < minNum1 && hfmNode[j].tag == 0 ){
                minNum2 = minNum1;
                tag2 = tag1;
                minNum1 = hfmNode[j].weight;
                tag1 = j;
            }else{
                if(hfmNode[j].weight < minNum2 && hfmNode[j].tag == 0 ){
                    minNum2 = hfmNode[j].weight;
                    tag2 = j;
                }
            }
        }

        hfmNode[tag1].tag = 1;
        hfmNode[tag2].tag = 1;

        //构造子树
        hfmNode[n-1+i].weight = hfmNode[tag1].weight + hfmNode[tag2].weight;
        hfmNode[n-1+i].LeftChild = tag1;
        hfmNode[n-1+i].RightChild = tag2;
        hfmNode[n-1+i].tag = 0;
    }
    //存放根结点的数组下标
    hfmTree->root = 2*n-2;
}

