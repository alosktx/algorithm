#pragma once
#include<stdio.h>
#include<stdlib.h>
#include "node.h"

enum appendNewline {noNewline, addNewLine};
// typedef enum appendNewLine AppendNewline;

//打印链表
void PrintList(Node * head, enum appendNewline addn1);
//单链表中基于表目的查找
int Find(Node * head, ElementType item);
//在单链表的头部插入一个新的单链表结点
void InsertFront(Node **head, ElementType item);
//删除单链表的头结点
void DeleteAt(Node ** head);
//删除单链表中值为key的结点
void Deletekey(Node **head,ElementType key);
//在有序单链表中插入新结点
void InsertOrder(Node **head,ElementType item);
//删除整个单链表
void ClearList(Node **head);