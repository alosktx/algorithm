#include<stdio.h>
#include<stdlib.h>
#include "mydefine.h"
#include "binaryTreeNode.h"
void InitBinaryTreeNode(BinaryTreeNode * btNode, ElementType item, BinaryTreeNode * lptr, BinaryTreeNode* rptr){
    btNode->data = item;
    btNode->LeftChild = lptr;
    btNode->RightChild = rptr;
}

BinaryTreeNode * CreateBTreeNode(ElementType item, BinaryTreeNode * lptr, BinaryTreeNode * rptr){
    BinaryTreeNode * btNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if(btNode == NULL)
        printf("binaryTreeNode.c [CreateBTreeNode] Memory allocation failure!\n");
    else
        InitBinaryTreeNode(btNode, item, lptr, rptr);
    return btNode;
}

void InitThreadedBTNode(ThreadedBTNode * tBTNode, ElementType item, ThreadedBTNode * leftTBTNode, ThreadedBTNode * rightTBTNode, bool ltag, bool rtag){
    tBTNode->data = item;
    tBTNode->LeftChild = leftTBTNode;
    tBTNode->RightChild = rightTBTNode;
    tBTNode->ltag = ltag;
    tBTNode->rtag = rtag;
}
ThreadedBTNode * CreateThreadBTNode(ElementType item, ThreadedBTNode * leftTBTNode, ThreadedBTNode * rightTBTNode){
    ThreadedBTNode * tBTNode = (ThreadedBTNode*)malloc(sizeof(ThreadedBTNode));
    if(tBTNode == NULL)
        printf("binaryTreeNode.c [CreateThreadBTNode] Memory allocation failure!\n");
    else
        InitThreadedBTNode(tBTNode,item,leftTBTNode,rightTBTNode,0,0);
    return tBTNode;
}