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
//构建一棵二叉树
BinaryTreeNode * CreateBTreeNode(ElementType item, BinaryTreeNode * lptr, BinaryTreeNode * rptr);
//二叉排序树中插入新结点，将newbtNode所指结点插入以rootNode为根结点指针的二叉排序树中
void ins_bst(BinaryTreeNode * newbtNode, BinaryTreeNode ** rootNode);
//从空树出发，依次插入结点生成二叉排序树
void make_bst(BinaryTreeNode ** rootNode);
//从二叉排序树中删除一个结点, rootNode为根结点， pbtnode指向被删除的结点， fbtNode指向被删除结点的父结点
void dele_bst(BinaryTreeNode * rootNode, BinaryTreeNode * pbtNode, BinaryTreeNode * fbtNode);

void InitThreadedBTNode(ThreadedBTNode * tBTNode, ElementType item, ThreadedBTNode * leftTBTNode, ThreadedBTNode * rightTBTNode, bool ltag, bool rtag);
ThreadedBTNode * CreateThreadBTNode(ElementType item, ThreadedBTNode * leftTBTNode, ThreadedBTNode * rightTBTNode);