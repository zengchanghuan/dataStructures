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
    ElementType element;
    Position next;
};

List MakeEmpty(List L) {
    if (L != NULL) {
        DeleteList(L);
    }
    L = malloc(sizeof(struct Node));
    
    if (L == NULL) {
        FatalError("out of memeory!");
    }
    L->next = NULL;
    return L;
}
int IsEmpty(List L) {
//    return L->next == NULL;
    return (L == NULL || L->next == NULL);

}
int IsLast(Position p, List L) {
    return p->next == NULL;
}
Position Find(ElementType X, List L) {
    Position p;
    p = L->next;
    while (p != NULL && p -> element != X) {
        p = p -> next;
    }
    return p;
}
void Delete(ElementType X, List L) {
    Position p = NULL,tmpCell;
    if (!IsLast(p, L)) {
        tmpCell = p -> next;
        p -> next = tmpCell -> next;
        free(tmpCell);
    }
}
Position FindPrevious(ElementType x, List L) {
    Position p;
    p = L;
    while (p->next != NULL && p->next->element != x) {
        p = p->next;
    }
    return p;
}
void Insert(ElementType X, List L, Position P) {
    Position tmpCell;
    tmpCell = malloc(sizeof(struct Node));
    if (tmpCell == NULL) {
        FatalError("out of space!!!");
    }
    tmpCell->element = X;
    tmpCell->next = P->next;
    P->next = tmpCell;
}

void DeleteList(List L) {
    Position p,tmp;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}

Position Header(List L) {
    return L;
}
Position First(List L) {
    return L->next;
}
Position Advance(Position P) {
    return P->next;
}
ElementType Retrieve(Position P) {
    return P->element;
}

void Travel(List L) {
    if (IsEmpty(L)) {
        return;
    }
    
    Position p = L->next;
    while (p != NULL) {
        printf(" %d ",p->element);
        p = p->next;
    }
    printf("\n");
}
List Reverse2(List L) {
    
    //保存cur的下一个结点
    PtrToNode temp;
    //pre指针指向前一个当前结点的前一个结点
    PtrToNode pre = NULL;
    //用head代替cur，也可以再定义一个cur结点指向head。
    while(L) {
        //保存下一个结点的位置
        temp = L->next;
        //翻转操作
        L->next = pre;
        //更新结点
        pre = L;
        L = temp;
    }
    return pre;

}

List Reverse(List L) {
    
    PtrToNode curr;
    PtrToNode q;
    
    if (IsEmpty(L)) {
        return L;
    }
    
    curr = L->next;
    L->next = NULL;
    while (curr != NULL) {
        q = curr->next;
        curr->next = L->next;
        L->next = curr;
        curr = q;
    }
    return L;

}

int ListLength(List L) {
    List p = L;
    int length = 0;
    if (IsEmpty(L)) {
        return length;
    }
    
    p = p->next;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

// 头插法创建单链表
List CreateHeadListWithHead(ElementType *array, int length) {
    List head;
    PtrToNode newNode;
    head = (List)malloc(sizeof(struct Node));
    head->next = NULL;
    for (int i = 0; i < length; i++) {
        newNode = (List)malloc(sizeof(struct Node));
        newNode->element = array[i];
        newNode->next = head->next;
        head->next = newNode;
    }
    return head;
}

List CreateHeadListWithTail(ElementType *array, int length) {
    List head;
    PtrToNode p,newNode;
    head = (List)malloc(sizeof(struct Node));
    head->next = NULL;
    p = head;
    
    for (int i = 0; i < length; i++) {
        newNode = (List)malloc(sizeof(struct Node));
        newNode->element = array[i];
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return head;
}


