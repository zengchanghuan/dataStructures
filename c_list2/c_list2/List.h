//
//  List.h
//  c_list2
//
//  Created by 曾长欢 on 2022/4/7.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include <stdlib.h>
#include "Status/Status.h"
#include <string.h>

typedef int ElementType;

typedef struct Node {
    ElementType data;
    struct Node *next;
}LNode;

typedef LNode *List;
Status InitList (List L);
Status DestroyList (List *L);
Status ClearList (List L);
Status IsEmpty (List L);
Status ListLength(List L);
Status ListInsert(List L,int i,ElementType element);
Status ListDelete(List L,int i,ElementType *element);
List CreateListWithHead(ElementType *array,int length);
List CreateListWithTail(ElementType *array,int length);
void printList(List L);
List Reverse(List L);

//在带头结点的单链表L中根据序号l.获取元素的值，用e返回L中第l.个数据元素的值
Status GetElem(List L,int i,ElementType *e);

LNode * LocateElem(List L,ElementType e);

#endif /* List_h */
