#pragma once
#include<stdbool.h>
#include "mydefine.h"
struct binaryTreeNode{
    ElementType data;
    struct binaryTreeNode * LeftChild;
    struct binaryTreeNode * RightChild;
};
typedef struct binaryTreeNode BinaryTreeNode;

struct threadedBTNode{
    bool ltag,rtag;
    ElementType data;
    struct threadedBTNode * LeftChild,*RightChild;
};
typedef struct threadedBTNode ThreadedBTNode;

void InitBinaryTreeNode(BinaryTreeNode * btNode, ElementType item, BinaryTreeNode * lptr, BinaryTreeNode* rptr);
BinaryTreeNode * CreateBTreeNode(ElementType item, BinaryTreeNode * lptr, BinaryTreeNode * rptr);
void InitThreadedBTNode(ThreadedBTNode * tBTNode, ElementType item, ThreadedBTNode * leftTBTNode, ThreadedBTNode * rightTBTNode, bool ltag, bool rtag);
ThreadedBTNode * CreateThreadBTNode(ElementType item, ThreadedBTNode * leftTBTNode, ThreadedBTNode * rightTBTNode);