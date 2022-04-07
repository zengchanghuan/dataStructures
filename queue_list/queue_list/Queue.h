//
//  Queue.h
//  queue_list
//
//  Created by 曾长欢 on 2022/4/7.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include "Status/Status.h"

typedef int ElementType;
typedef struct Node{
    ElementType data;
    struct Node *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
} Queue;

Status initQueue(Queue *queue);

Status destroyQueue(Queue *queue);

Status clearQueue(Queue *queue);

Status isEmpty(Queue queue);

int queueLength(Queue queue);

ElementType getHead(Queue queue);

Status enqueue(ElementType element,Queue *queue);

ElementType dequeue (Queue *queue);

Status queueTraverse(Queue queue);

#endif /* Queue_h */
