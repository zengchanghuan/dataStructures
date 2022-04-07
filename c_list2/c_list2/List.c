//
//  List.c
//  c_list2
//
//  Created by 曾长欢 on 2022/4/7.
//

#include "List.h"
Status InitList (List L) {
    L = (List) malloc(sizeof(LNode));
    if (L == NULL) {
        exit(OVERFLOW);
    }
    L->next = NULL;
    return OK;
    
}
Status DestroyList (List *L) {
    if (L == NULL || *L == NULL) {
        return ERROR;
    }
    List p = *L;
    while (p != NULL) {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
    *L = NULL;
    return OK;
}

Status ClearList (List L) {
    if (L == NULL) {
        return ERROR;
    }
    
    List pre,p;
    p = L->next;
    while (p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }
    L->next = NULL;
    return OK;
}

Status IsEmpty (List L) {
    if (L != NULL && L->next == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Status ListLength(List L) {
    List p = L;
    int length = 0;
    if (L == NULL || L->next == NULL) {
        return 0;
    }
    
    p = p->next;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

Status ListInsert(List L,int i,ElementType element) {
    if (L == NULL) {
        return ERROR;
    }
    
    List p = L;
    int j = 0;
    List s;
    
    while (p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    
    if (p == NULL || j > i - 1) {
        return ERROR;
    }
    
    s = malloc(sizeof(struct Node));
    if (s == NULL) {
        exit(OVERFLOW);
    }
    
    s->data = element;
    s->next = p->next;
    p->next = s;
    return OK;
}
Status ListDelete(List L,int i,ElementType *element) {
    if (L == NULL || L->next == NULL) {
        return ERROR;
    }
    
    List p = L;
    int j = 0;
    List q;
    
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    
    if (p->next == NULL || j > i - 1) {
        return ERROR;
    }
    
    q = p->next;
    p->next = q->next;
    *element = q->data;
    free(q);
    return OK;
}

List CreateListWithHead(ElementType *array,int length) {
    List head = malloc(sizeof(LNode));
    head->next = NULL;
    LNode *newNode;
    
    for (int i = 0; i < length; i++) {
        newNode = malloc(sizeof(LNode));
        newNode->data = array[i];
        newNode->next = head->next;
        head->next = newNode;
    }
    return head;
    
}
List CreateListWithTail(ElementType *array,int length) {
    List head = malloc(sizeof(LNode));
    head->next = NULL;
    
    LNode *p,*newNode;
    p = head;
    
    for (int i = 0; i < length; i++) {
        newNode = malloc(sizeof(LNode));
        newNode->data = array[i];
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return head;
}
void printList(List L) {
    if (L == NULL || L->next == NULL) {
        return;
    }
    
    List p = L->next;
    
    while (p != NULL) {
        printf("%d->",p->data);
        p = p->next;
    }
    printf("\n");
}

List Reverse(List L) {
    if (L == NULL || L->next == NULL) {
        return L;
    }
    LNode *curr = L->next;
    L->next = NULL;
    
    LNode *pre;
    
    while (curr != NULL) {
        pre = curr->next;
        curr->next = L->next;
        L->next = curr;
        curr = pre;
    }
    return L;
    
}

Status GetElem(List L,int i,ElementType *e) {
    if (L == NULL || L->next == NULL) {
        return ERROR;
    }
    List p = L;
    int j = 0;
    
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    
    if (p->next == NULL || j > i - 1) {
        return ERROR;
    }
    *e = p->next->data;
    return OK;
}

LNode * LocateElem(List L,ElementType e) {
    if (L == NULL || L->next == NULL) {
        return 0;
    }
    
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}
