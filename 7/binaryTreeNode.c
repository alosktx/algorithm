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

//二叉排序树中插入新结点，将newbtNode所指结点插入以rootNode为根结点指针的二叉排序树中,递归
void ins_bst(BinaryTreeNode * newbtNode, BinaryTreeNode ** rootNode){
    if(*rootNode == NULL)
        *rootNode = newbtNode;
    else if(newbtNode->data < (*rootNode)->data)
        ins_bst(newbtNode, &( (*rootNode)->data) );
    else    
        ins_bst(newbtNode, &( (*rootNode)->data ) );   
}

//从空树出发，依次插入结点生成二叉排序树，非递归
void make_bst(BinaryTreeNode ** rootNode){
    BinaryTreeNode * newbtNode, * insertbtNode, * tempRootNode;
    ElementType item;
    *rootNode = NULL;

    printf("input insert node: ");
    scanf("%d",&item);
    if(item != endmark){
        newbtNode = CreateBTreeNode(item, NULL, NULL);
        *rootNode = newbtNode;
    }

    printf("input insert node: ");
    scanf("%d",&item);
    
    while(item != endmark){
        newbtNode = CreateBTreeNode(item, NULL, NULL);
        insertbtNode = *rootNode;
        while(insertbtNode!=NULL){
            tempRootNode = insertbtNode;
            if(newbtNode->data < insertbtNode->data)
                insertbtNode = insertbtNode->LeftChild;
            else
                insertbtNode = insertbtNode->RightChild;
        }

        if(newbtNode->data < tempRootNode->data)
            tempRootNode->LeftChild = newbtNode;
        else
            tempRootNode->RightChild = newbtNode;

        printf("input insert node: ");
        scanf("%d",&item);
    }
}

//从二叉排序树中删除一个结点, rootNode为根结点， pbtnode指向被删除的结点， fbtNode指向被删除结点的父结点
//删除操作就是看如何处理被删除结点的左右子树
void dele_bst(BinaryTreeNode * rootNode, BinaryTreeNode * pbtNode, BinaryTreeNode * fbtNode){
    BinaryTreeNode * tempbtNode;
    //如果被删除结点无左子树
    if(pbtNode->LeftChild == NULL){
        //被删除的结点是树根
        if(fbtNode == NULL){
            rootNode = pbtNode->RightChild;
        }
        //被删除的结点是其父结点的左子树
        else if(pbtNode == fbtNode->LeftChild){
            fbtNode->LeftChild = pbtNode->RightChild;
        }
        //被删除的结点是其父结点的右子树
        else{
            fbtNode->RightChild = pbtNode->RightChild;
        }
    }
    //如果被删除结点无右子树
    else if(pbtNode->RightChild == NULL){
        //被删除的结点是树根
        if(fbtNode == NULL){
            rootNode = pbtNode->LeftChild;
        }
        //被删除的结点是其父结点的左子树
        else if(pbtNode == fbtNode->LeftChild){
            fbtNode->LeftChild = pbtNode->LeftChild;
        }
        //被删除的结点是其父结点的右子树
        else{
            fbtNode->RightChild = pbtNode->LeftChild;
        }
    }
    //被删除结点既有左子树，又有右子树
    else{
        //求被删除结点的左子树的对称序的最后一个结点
        tempbtNode = fbtNode->LeftChild;
        while(tempbtNode->RightChild!=NULL){
            tempbtNode = tempbtNode->RightChild;
        }
        //被删除的结点是树根
        if(fbtNode == NULL){
            rootNode = pbtNode->LeftChild;
            tempbtNode->RightChild = pbtNode->RightChild;
        }
        //被删除的结点是其父结点的左子树
        else if(pbtNode == fbtNode->LeftChild){
            fbtNode->LeftChild = pbtNode->LeftChild;
            tempbtNode->RightChild = pbtNode->RightChild;
        }
        //被删除的结点是其父结点的右子树
        else{
            fbtNode->RightChild = pbtNode->LeftChild;
            tempbtNode->RightChild = pbtNode->RightChild;
        }
    }
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