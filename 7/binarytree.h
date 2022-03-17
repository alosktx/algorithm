#pragma once
#include<stdbool.h>
#include "mydefine.h"
#include "binaryTreeNode.h"
struct binaryTree{
    BinaryTreeNode * root;
};
typedef struct binaryTree BinaryTree;

struct binarySTree
{
    BinaryTreeNode * root;
};
typedef struct binarySTree BinarySTree;

struct binaryThreadTree{
    ThreadedBTNode * root;
};
typedef struct binaryThreadTree BinaryThreadTree;  

void InitBinaryTree(BinaryTree * bt);
bool IsEmpty(BinaryTree * bt);
//将根结点的数据存于itemptr
bool getRoot(BinaryTree * bt, ElementType * itemptr);
//构造二叉树
BinaryTreeNode * MakeTree(BinaryTree * bt, ElementType item, BinaryTreeNode * leftNodePtr, BinaryTreeNode * rightNodePtr);
//前序遍历
void PreOrder(BinaryTreeNode * btNode);
//对称遍历
void InOrder(BinaryTreeNode * btNode);
//后序遍历
void PostOrder(BinaryTreeNode * btNode);
//使用栈的二叉树前序遍历非递归算法
void NlrOrder(BinaryTreeNode * btNode);
//使用栈的二叉树对称遍历非递归算法
void LnrOrder(BinaryTreeNode * btNode);
//使用栈的二叉树后序遍历非递归算法
void LrnOrder(BinaryTreeNode * btNode);


//由普通二叉树构造序列化二叉树
void MakeThreadTree(ThreadedBTNode * tBTNode, BinaryTreeNode * btNode);
//递归对称树线索化二叉树
void InorderThreaded(ThreadedBTNode * tbtNode, ThreadedBTNode **pre);
//对称序线索化二叉树建立后，在对称序线索树中找指定结点的对称序后继
void Inordernext(ThreadedBTNode * tbtNode,ThreadedBTNode ** subtNode);
//对称序遍历对称序线索化二叉树
void ThreadInTravel(ThreadedBTNode *tbtNode);
//在对称序线索化二叉树中插入一新结点
void InsertThreadedBT(ThreadedBTNode * tbtNode, ThreadedBTNode *subtNode);