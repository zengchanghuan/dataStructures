//
//  Queue.c
//  queue_list
//
//  Created by 曾长欢 on 2022/4/7.
//

#include "Queue.h"
Status initQueue(Queue *queue) {
    if (queue == NULL) {
        return ERROR;
    }
    (*queue).front = (*queue).rear = (QueuePtr)malloc(sizeof(QNode));
    if (!(*queue).front) {
        exit(OVERFLOW);
    }
    
    (*queue).front->next = NULL;
    return OK;
}

Status destroyQueue(Queue *queue) {
    if (queue == NULL) {
        return ERROR;
    }
    
    while ((*queue).front) {
        (*queue).rear = (*queue).front->next;
        free((*queue).front);
        (*queue).front = (*queue).rear;
    }
    return OK;
}

Status clearQueue(Queue *queue) {
    if (queue == NULL) {
        return ERROR;
    }
    (*queue).rear = (*queue).front->next;
    while ((*queue).rear) {
        (*queue).front->next = (*queue).rear->next;
        free((*queue).rear);
        (*queue).rear = (*queue).front->next;
    }
    (*queue).rear = (*queue).front;
    return OK;
}
Status isEmpty(Queue queue) {
    if (queue.front == queue.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

//Status isFull (Queue queue) {
//    if ((queue.rear + 1) % MAXQSIZE == queue.front) {
//        return TRUE;
//    } else {
//        return FALSE;
//    }
//
//}

int queueLength(Queue queue) {
    int length = 0;
    QueuePtr p = queue.front;
    while (p != queue.rear) {
        length++;
        p = p->next;
    }
    
    return length;
}

ElementType getHead(Queue queue) {
    QueuePtr p;
    if (queue.front == NULL || queue.front == queue.rear) {
        return ERROR;
    }
    
    p = queue.front->next;
    return p->data;
}

Status enqueue(ElementType element,Queue *queue) {
    QueuePtr p;
    if (queue == NULL || (*queue).front == NULL) {
        return ERROR;
    }
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) {
        exit(OVERFLOW);
    }
    p->data = element;
    p->next = NULL;
    (*queue).rear->next = p;
    (*queue).rear = p;
    
    return OK;
}

ElementType dequeue (Queue *queue) {
    QueuePtr p;
    if (queue == NULL || (*queue).front == NULL || (*queue).front == (*queue).rear) {
        return ERROR;
    }
    
    p = (*queue).front->next;
    ElementType e = p->data;
    (*queue).front->next = p->next;
    if ((*queue).rear == p) {
        (*queue).rear = (*queue).front;
    }
    free(p);
    return e;
}

Status queueTraverse(Queue queue) {
    QueuePtr p;
    
    if (queue.front == NULL) {
        return ERROR;
    }
    
    p = queue.front->next;
    
    while (p != NULL) {
        printf("%d ->",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
