//
//  list.c
//  list
//
//  Created by 曾长欢 on 2022/3/25.
//

#include "list.h"
#include "fatal.h"
#include <stdlib.h>

struct Node {
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L) {
    if (L != NULL) {
        DeleteList(L);
    }
    L = malloc(sizeof(struct Node));
    
    if (L == NULL) {
        FatalError("out of memeory!");
    }
    L->Next = NULL;
    return L;
}
int IsEmpty(List L) {
//    return L->Next == NULL;
    return (L == NULL || L->Next == NULL);

}
int IsLast(Position p, List L) {
    return p->Next == NULL;
}
Position Find(ElementType X, List L) {
    Position p;
    p = L->Next;
    while (p != NULL && p -> Element != X) {
        p = p -> Next;
    }
    return p;
}
void Delete(ElementType X, List L) {
    Position p = NULL,tmpCell;
    if (!IsLast(p, L)) {
        tmpCell = p -> Next;
        p -> Next = tmpCell -> Next;
        free(tmpCell);
    }
}
Position FindPrevious(ElementType x, List L) {
    Position p;
    p = L;
    while (p->Next != NULL && p->Next->Element != x) {
        p = p->Next;
    }
    return p;
}
void Insert(ElementType X, List L, Position P) {
    Position tmpCell;
    tmpCell = malloc(sizeof(struct Node));
    if (tmpCell == NULL) {
        FatalError("out of space!!!");
    }
    tmpCell->Element = X;
    tmpCell->Next = P->Next;
    P->Next = tmpCell;
}
/* Incorrect DeleteList algorithm */
/*
void DeleteList(List L) {
    Position p;
    
    p = L->Next;
    L->Next = NULL;
    while (p != NULL) {
        free(p);
        p = p->Next;
    }
}
*/

void DeleteList(List L) {
    Position p,tmp;
    p = L->Next;
    L->Next = NULL;
    while (p != NULL) {
        tmp = p->Next;
        free(p);
        p = tmp;
    }
}

Position Header(List L) {
    return L;
}
Position First(List L) {
    return L->Next;
}
Position Advance(Position P) {
    return P->Next;
}
ElementType Retrieve(Position P) {
    return P->Element;
}

void PrintList(List L) {
    if (L == NULL) {
        return;
    }
    
    Position p = L->Next;
    while (p != NULL) {
        printf(" %d ",p->Element);
        p = p->Next;
    }
    printf("\n");
}

int ListLength(List L) {
    List p = L;
    int length = 0;
    if (IsEmpty(L)) {
        return length;
    }
    
    p = p->Next;
    while (p != NULL) {
        length++;
        p = p->Next;
    }
    return length;
}

// 头插法创建单链表
List CreateHeadListWithHead(ElementType *array, int length) {
    List head;
    PtrToNode newNode;
    head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    for (int i = 0; i < length; i++) {
        newNode = (List)malloc(sizeof(struct Node));
        newNode->Element = array[i];
        newNode->Next = head->Next;
        head->Next = newNode;
    }
    return head;
}

List CreateHeadListWithTail(ElementType *array, int length) {
    List head;
    PtrToNode p,newNode;
    head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    p = head;
    
    for (int i = 0; i < length; i++) {
        newNode = (List)malloc(sizeof(struct Node));
        newNode->Element = array[i];
        newNode->Next = NULL;
        p->Next = newNode;
        p = newNode;
    }
    return head;
}