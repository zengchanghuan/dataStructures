//
//  linkedList.c
//  c_list
//
//  Created by 曾长欢 on 2022/4/6.
//

#include "linkedList.h"
Status InitList (LinkList *L) {
    if( L != NULL ) {
        DestroyList(L);
    }
    *L = (LinkList)malloc( sizeof( struct Node ) );
    if( L == NULL ) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    return OK;
}
Status DestroyList (LinkList *L);
Status ClearList (LinkList L);
Status IsEmpty (LinkList L);
Status ListLength(LinkList L);

//获取链表中第i个元素，将其存储到e中
Status GetElem(LinkList L,int i,ElementType *e);

//返回链表中首个与e满足Compare关系的元素位序
int LocateElem(LinkList L,ElementType e,Status(Compare)(ElementType,ElementType));

Status PriorElem(LinkList L,ElementType curElement,ElementType preElement);

Status NextElem(LinkList L, ElementType curElement, ElementType* preElement);

Status ListInsert(LinkList L,int i,ElementType element);

Status ListDelete(LinkList L,int i,ElementType *element);

void ListTraverse(LinkList L,void(Visit)(ElementType));

Status CreateListHead(LinkList *L,int n,char *path);

Status CreateListTail(LinkList *L,int n,char *path);
