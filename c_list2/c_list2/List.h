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
void printList(List L);
List Reverse(List L);
#endif /* List_h */
