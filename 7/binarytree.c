#include<stdio.h>
#include<stdlib.h>
#include "mydefine.h"
#include "binarytree.h"

void InitBinaryTree(BinaryTree * bt){
    bt->root = NULL;
}
bool IsEmpty(BinaryTree * bt){
    return ((bt->root)?true:false);
}
//将根结点的数据存于itemptr
bool getRoot(BinaryTree * bt, ElementType * itemptr){
    if(IsEmpty(bt)){
        *itemptr = bt->root->data;
        return true;
    }else{
        return false;
    }
}
//构造二叉树
BinaryTreeNode * MakeTree(BinaryTree * bt, ElementType item, BinaryTreeNode * leftNodePtr, BinaryTreeNode * rightNodePtr){
    bt->root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if(bt->root == NULL){
        printf("binarytree.c [MakeTree] Memory allocation failure!\n");
        exit(1);
    }
    InitBinaryTreeNode(bt->root, item, leftNodePtr, rightNodePtr);
    return bt->root;
}
//前序遍历
void PreOrder(BinaryTreeNode * btNode){
    if(btNode){
        printf("%c",btNode->data);
        PreOrder(btNode->LeftChild);
        PreOrder(btNode->RightChild);
    }
}
//对称遍历
void InOrder(BinaryTreeNode * btNode){
    if(btNode){
        InOrder(btNode->LeftChild);
        printf("%c",btNode->data);
        InOrder(btNode->RightChild);
    }
}
//后序遍历
void PostOrder(BinaryTreeNode * btNode){
    if(btNode){
        PostOrder(btNode->LeftChild);
        PostOrder(btNode->RightChild);
        printf("%c",btNode->data);
    }
}
//使用栈的二叉树前序遍历非递归算法
void NlrOrder(BinaryTreeNode * btNode){
    BinaryTreeNode * stack[100];
    unsigned top = 0;
    stack[0] = btNode;
    do{
        //左结点为空时退出循环
        while(stack[top]!=NULL){
            printf("%c",stack[top]->data);
            stack[++top] = stack[top]->LeftChild;
        }
        //添加上述左结点的 根结点（回退一个结点）的右结点，  到根结点的位置；
        if(top>0)
            stack[top] = stack[--top]->RightChild;

    }while(top>0 || stack[top]!=NULL);
}
//使用栈的二叉树对称遍历非递归算法
void LnrOrder(BinaryTreeNode * btNode){
    BinaryTreeNode * stack[100];
    int top = 0;
    stack[0] = btNode;
    do{
        while(stack[top]!=NULL)
            stack[++top] = stack[top]->LeftChild;
        if(top>0){
            printf("%c",stack[--top]->data);
            stack[top] = stack[top]->RightChild;
        }
    }while(top>0 || stack[top]!= NULL);
}
//使用栈的二叉树后序遍历非递归算法
void LrnOrder(BinaryTreeNode * btNode){
    BinaryTreeNode * stack[100];
    unsigned tag[100];
    unsigned top = 1;//此处用unsigned 会出现bus error

    stack[0] = NULL;
    stack[1] = btNode;
    tag[0] = 0;
    tag[1] = 0;
    do{
        //一直添加左子结点，直到没有左子结点退出循环（添加NULL）,
        while(stack[top]!=NULL){
            stack[++top] = stack[top]->LeftChild;
            tag[top] = 0;
        }
        // printf("\n");
        // for(int i=0;i<5;i++){
        //     if(stack[i]==NULL)
        //         printf("NULL");
        //     else
        //         printf("%c",stack[i]->data);
        // }
        // printf("\n");
        // for(int i = 0;i<5;i++)
        //     printf("%d",tag[i]);
        // printf("\n");
        // printf("top:%d\n",top);
        //tag == 0 表示此结点还没有添加其右子结点在后面； tag == 1 表示此结点已经添加其右子结点在后面
        while(tag[top-1] == 1)
            printf("%c",stack[--top]->data);
        //NULL的位置添加右结点
        if(top>1){
            stack[top] = stack[top-1]->RightChild;
            tag[top-1] = 1;
            tag[top] = 0;
        }

    }while(top!=1);
}

//递归对称树线索化二叉树,进入函数前所有结点的ltag，rtag的值为0,指针变量tbtNode指示二叉树的根结点，pre（前驱）的值为NULL
//此处一定要用双重指针，单指针作函数参数，是将实参指针的值传递给一个临时指针变量，这个临时指针对其内容所作的修改， 随着函数结束 ，无法传递给原来的实参
//关键点在于，要想改变函数外的指针指向的内容，需要用到双重指针
void InorderThreaded(ThreadedBTNode * tbtNode, ThreadedBTNode **pre){
    if(tbtNode!=NULL){      
        
        InorderThreaded(tbtNode->LeftChild,pre);

        printf("上：%p_",pre);
        if((*pre)!=NULL)
            printf("%p_%c\n",(*pre),(*pre)->data);
        else
            printf("NULL\n");

        if((*pre)!=NULL && (*pre)->rtag == 1 )
            (*pre)->RightChild = tbtNode;
        if(tbtNode->LeftChild == NULL){
            tbtNode->ltag = 1;
            tbtNode->LeftChild = *pre;
        }
        if(tbtNode->RightChild == NULL)
            tbtNode->rtag = 1;
        *pre=tbtNode;
        
        printf("下：%p_",pre);
        if((*pre)!=NULL)
            printf("%p_%c\n",(*pre),(*pre)->data);
        else
            printf("NULL\n");

        InorderThreaded(tbtNode->RightChild,pre);
    }
}

//对称序线索化二叉树建立后，在对称序线索树中找指定结点的对称序后继
void Inordernext(ThreadedBTNode * tbtNode,ThreadedBTNode ** subtNode){
    // printf("内部： %p\t%p\t%c\n",subtNode,*subtNode,(*subtNode)->data);
    if(tbtNode->rtag == 1){
        *subtNode = tbtNode->RightChild;
    }
    else{
        *subtNode = tbtNode->RightChild;
        while((*subtNode)->ltag == 0)
            *subtNode = (*subtNode)->LeftChild;
    }
    // printf("内部： %p\t%p\t%c\n",subtNode,*subtNode,(*subtNode)->data);

}

//对称序线索化二叉树建立后，以对称序遍历对称序线索化二叉树
void ThreadInTravel(ThreadedBTNode *tbtNode){
    ThreadedBTNode * subtNode;
    if(tbtNode!=NULL){
        while(tbtNode->ltag == 0){
            tbtNode = tbtNode->LeftChild;
        }
        do{
            printf("%c%d%d ",tbtNode->data,tbtNode->ltag?1:0,tbtNode->rtag?1:0);
            Inordernext(tbtNode,&subtNode);
            tbtNode = subtNode;
        }while(tbtNode!=NULL);
    }
}
//在对称序线索化二叉树中插入一新结点
void InsertThreadedBT(ThreadedBTNode * tbtNode, ThreadedBTNode *newtNode){
    ThreadedBTNode * subtbtNode;
    Inordernext(tbtNode,&subtbtNode);
    if(tbtNode->RightChild == NULL)
        subtbtNode = NULL;
    newtNode->ltag = 1;
    newtNode->LeftChild = tbtNode;
    newtNode->rtag = tbtNode->rtag;
    newtNode->RightChild = tbtNode->RightChild;

    tbtNode->rtag = 0;
    tbtNode->RightChild = newtNode;
    if( (subtbtNode!=NULL) && (subtbtNode->ltag==1) )
        subtbtNode->LeftChild = newtNode;
}

//由普通二叉树构造序列化二叉树
void MakeThreadTree(ThreadedBTNode * tBTNode, BinaryTreeNode * btNode){
    if(btNode){
        tBTNode->data = btNode->data;
        tBTNode->ltag = 0;
        tBTNode->rtag = 0;
        if(btNode->LeftChild){
            ThreadedBTNode * leftTBTNode  = (ThreadedBTNode*)malloc(sizeof(ThreadedBTNode));
            MakeThreadTree(leftTBTNode, btNode->LeftChild);
            tBTNode->LeftChild = leftTBTNode;
        }else{
            tBTNode->LeftChild = NULL;
        }
        if(btNode->RightChild){
            ThreadedBTNode * rightTBTNode = (ThreadedBTNode*)malloc(sizeof(ThreadedBTNode));
            MakeThreadTree(rightTBTNode, btNode->RightChild);
            tBTNode->RightChild = rightTBTNode;
        }else{
            tBTNode->RightChild = NULL;
        }
    }
}





