//
//  linkedList.h
//  c_list
//
//  Created by 曾长欢 on 2022/4/6.
//

#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、realloc、free、exit 原型
#include <string.h>     // 提供 strstr 原型
#include "Status.h"

typedef int ElementType;

typedef struct Node {
    ElementType data;
    struct Node *next;
} LNode;

typedef LNode *LinkList;

Status InitList (LinkList *L);
Status DestroyList (LinkList *L);
Status ClearList (LinkList L);
Status IsEmpty (LinkList L);
Status ListLength(LinkList L);

//获取链表中第i个元素，将其存储到e中
Status GetElem(LinkList L,int i,ElementType *e);

//返回链表中首个与e满足Compare关系的元素位序
int LocateElem(LinkList L,ElementType e,Status(Compare)(ElementType,ElementType));

Status PriorElem(LinkList L,ElementType curElement,ElementType *preElement);

Status NextElem(LinkList L, ElementType curElement, ElementType *nextElement);

Status ListInsert(LinkList L,int i,ElementType element);

Status ListDelete(LinkList L,int i,ElementType *element);

void ListTraverse(LinkList L,void(Visit)(ElementType));

LinkList Reverse(LinkList L);

// 头插法创建单链表
LinkList CreateHeadListWithHead(ElementType *array, int length);

// 尾插法创建单链表
LinkList CreateHeadListWithTail(ElementType *array, int length);

#endif /* linkedList_h */
