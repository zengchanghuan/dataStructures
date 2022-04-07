//
//  Queue.c
//  queue_array
//
//  Created by 曾长欢 on 2022/4/7.
//

#include "Queue.h"
Status initQueue(Queue *queue) {
    if(queue == NULL) {
        return ERROR;
    }
    
    (*queue).array = (ElementType *) malloc(MAXQSIZE * sizeof(ElementType));
    if(!(*queue).array) {
        exit(OVERFLOW);
    }
    
    (*queue).front = (*queue).rear = 0;
    
    return OK;
}
int queueLength(Queue *queue) {
    if (queue->array == NULL) {
        return 0;
    }
    
    int length = (queue->rear - queue->front + MAXQSIZE) % MAXQSIZE;
    return length;
}

Status enqueue(ElementType element,Queue *queue) {
    if (queue == NULL || queue->array == NULL) {
        return ERROR;
    }
    
    // 队列满的标志（会浪费一个空间来区分队列空和队列满）
    if(((*queue).rear + 1) % MAXQSIZE == (*queue).front) {
        return ERROR;
    }
    
    //入队
    queue->array[queue->rear] = element;
    
    //尾指针前进
    queue->rear = (queue->rear + 1) % MAXQSIZE;
    return OK;
    
    
}

ElementType dequeue (Queue *queue) {
    if (queue == NULL || queue->array == NULL) {
        return ERROR;
    }
    
    if (queue->front == queue->rear) {
        return ERROR;
    }
    
    ElementType elemen = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAXQSIZE;
    
    return elemen;
    
}
Status dequeue2 (ElementType *elemen,Queue *queue) {
    if (queue == NULL || queue->array == NULL) {
        return ERROR;
    }
    
    if (queue->front == queue->rear) {
        return ERROR;
    }
    
    *elemen = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAXQSIZE;
    
    return OK;
    
}
Status destroyQueue(Queue *queue) {
    if (queue == NULL) {
        return ERROR;
    }
    if (queue->array) {
        free(queue->array);
    }
    queue->array = NULL;
    (*queue).front = (*queue).rear = 0;
    return ERROR;
}

Status clearQueue(Queue *queue) {
    if (queue == NULL || (*queue).array == NULL) {
        return ERROR;
    }
    
    (*queue).front = (*queue).rear = 0;
    return OK;
}

Status isEmpty(Queue queue) {
    if (queue.front == queue.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Status isFull (Queue queue) {
    if ((queue.rear + 1) % MAXQSIZE == queue.front) {
        return TRUE;
    } else {
        return FALSE;
    }
}

ElementType getHead(Queue queue) {
    if (isEmpty(queue)) {
        return ERROR;
    }
    
    ElementType e = queue.array[queue.front];
    return e;
}


Status queueTraverse(Queue queue) {
    if (queue.array == NULL) {
        return ERROR;
    }
    
    int i;
    for (i = queue.front; i != queue.rear; i = (i + 1) % MAXQSIZE) {
        printf("%d->",queue.array[i]);
    }
    printf("\n");
    return OK;
}
