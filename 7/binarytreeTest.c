#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include "mydefine.h"
#include "binaryTreeNode.h"
#include "binarytree.h"

void PreOrderTBTNode(ThreadedBTNode * tbtNode){
    if(tbtNode){
        printf("%c%d%d ",tbtNode->data,tbtNode->ltag?1:0,tbtNode->rtag?1:0);
        PreOrderTBTNode(tbtNode->LeftChild);
        PreOrderTBTNode(tbtNode->RightChild);
    }
}

void PrintTBTNode(ThreadedBTNode * tbtNode){
    printf("%c%d%d",tbtNode->data,tbtNode->ltag?1:0,tbtNode->rtag?1:0);
    if(tbtNode->LeftChild == NULL){
        printf("%c",'L');
    }else{
        printf("%c",tbtNode->LeftChild->data);
    }

    if(tbtNode->RightChild == NULL){
        printf("%c",'R');
    }else{
        printf("%c",tbtNode->RightChild->data);
    }
    printf("\n");
}

void PrintEveryTBTNode(ThreadedBTNode * tbtNode){
    // a a00bc a00bc
    PrintTBTNode(tbtNode);
    // b b00de b00de
    PrintTBTNode(tbtNode->LeftChild);
    //d d00LR d11Lb
    PrintTBTNode(tbtNode->LeftChild->LeftChild);
    //e e00LR e11ba
    PrintTBTNode(tbtNode->LeftChild->RightChild);
    // c c00fR c01fR
    PrintTBTNode(tbtNode->RightChild);
    // f f00LR f11ac
    PrintTBTNode(tbtNode->RightChild->LeftChild);
    printf("\n\n");
}

int main(int argc, char const *argv[])
{
    BinaryTree * bt = (BinaryTree*)malloc(sizeof(BinaryTree));
    BinaryTreeNode *a,*b,*c,*d,*e,*f;
    f = MakeTree(bt,'f',NULL,NULL);
    e = MakeTree(bt,'e',NULL,NULL);
    d = MakeTree(bt,'d',NULL,NULL);
    c = MakeTree(bt,'c',f,NULL);
    b = MakeTree(bt,'b',d,e);
    a = MakeTree(bt,'a',b,c);

    printf("PreOrder:\n");
    PreOrder(bt->root);
    printf("\n\n");

    printf("InOrder:\n");
    InOrder(bt->root);
    printf("\n\n");

    printf("PostOrder:\n");
    PostOrder(bt->root);
    printf("\n\n");

    printf("NLR:\n");
    NlrOrder(bt->root);
    printf("\n\n");

    printf("LNR:\n");
    LnrOrder(bt->root);
    printf("\n\n");

    printf("LRN:\n");
    LrnOrder(bt->root);
    printf("\n\n");

    printf("Thread first****************\n");
    BinaryThreadTree * tbt = (BinaryThreadTree*)malloc(sizeof(BinaryThreadTree));  
    tbt->root = (ThreadedBTNode*)malloc(sizeof(ThreadedBTNode));
    MakeThreadTree(tbt->root,bt->root);
    PreOrderTBTNode(tbt->root);
    printf("\n\n");

    PrintEveryTBTNode(tbt->root);

    ThreadedBTNode * tbttest = NULL;
    ThreadedBTNode **pre ;
    pre = &tbttest; 
    InorderThreaded(tbt->root,pre);
    
    PrintEveryTBTNode(tbt->root);

    ThreadInTravel(tbt->root);
    printf("\n\n");

    ThreadedBTNode * subtNode = (ThreadedBTNode*)malloc(sizeof(ThreadedBTNode));
    printf("外部： %p\t%p\t%c\n",&subtNode,subtNode,subtNode->data);
    Inordernext(tbt->root,&subtNode);
    printf("外部： %p\t%p\t%c\n",&subtNode,subtNode,subtNode->data);

    printf("\n\n");

    ThreadedBTNode *newtNode = (ThreadedBTNode*)malloc(sizeof(ThreadedBTNode));
    newtNode->data = 'n';
    InsertThreadedBT(tbt->root,newtNode);
    ThreadInTravel(tbt->root);
    printf("\n\n");

    return 0;
}
