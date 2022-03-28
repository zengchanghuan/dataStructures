//
//  list.h
//  list
//
//  Created by 曾长欢 on 2022/3/25.
//

typedef int ElementType;


#ifndef list_h
#define list_h

#include <stdio.h>


struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
//生成空链表
List MakeEmpty(List L);

//判断链表是否为空
int IsEmpty(List L);

//判断结点P是否为尾结点
int IsLast(Position p, List L);

//查找链表中数据项为X的第一个结点
Position Find(ElementType x, List L);

//删除链表中数据项为X的第一个结点
void Delete(ElementType x, List L);

//查找链表中数据项为X的第一个结点的前驱
Position FindPrevious(ElementType x, List L);

//在链表中指定位置P插入数据项为X的结点
void Insert(ElementType x, List L, Position p);

//删除链表中除头结点外的所有结点
void DeleteList(List L);

//获得链表中头结点位置
Position Header(List L);

//获得链表中第一个数据结点的位置
Position First(List L);

//获得指定结点的后继结点
Position Advance(Position p);

//获得指定结点的数据项
ElementType Retrieve(Position p);

//遍历输出链表
void Travel(List L);
//链表长度
int ListLength(List L);

// 头插法创建单链表
List CreateHeadListWithHead(ElementType *array, int length);

//尾插法创建单链表
List CreateHeadListWithTail(ElementType *array, int length);

//逆序
List Reverse(List L);

List Reverse2(List L);
#endif /* list_h */
