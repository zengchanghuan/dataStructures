//
//  Queue.h
//  queue_array
//
//  Created by 曾长欢 on 2022/4/7.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>        // 提供malloc、realloc、free、exit原型
#include "Status.h"

#define MAXQSIZE 20

typedef int ElementType;
typedef struct {
    ElementType *array;
    //头指针
    int front;
    //尾指针
    int rear;
}Queue;

Status initQueue(Queue *queue);

Status destroyQueue(Queue *queue);

Status clearQueue(Queue *queue);

Status isEmpty(Queue queue);

Status isFull (Queue queue);

int queueLength(Queue *queue);

ElementType getHead(Queue queue);

Status enqueue(ElementType element,Queue *queue);

ElementType dequeue (Queue *queue);

Status queueTraverse(Queue queue);

#endif /* Queue_h */
