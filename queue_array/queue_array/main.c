//
//  main.c
//  queue_array
//
//  Created by 曾长欢 on 2022/4/7.
//

#include <stdio.h>
#include "Queue.h"

void testArrayQueue(void);
int main(int argc, const char * argv[]) {
    // insert code here...
    testArrayQueue();
    return 0;
}

 
void testArrayQueue(void) {

    Queue q;
    initQueue(&q);
    enqueue(10, &q);
    enqueue(3, &q);
    enqueue(5, &q);
    enqueue(7, &q);
    enqueue(9, &q);
    enqueue(99, &q);
    
    queueTraverse(q);
//    ElementType e = getHead(q);
//    printf("Queue dequeue is %d\n",dequeue(&q));
    printf("Queue isFull %d\n",isFull(q));
    clearQueue(&q);
    printf("Queue queueLength %d\n",queueLength(&q));

    queueTraverse(q);


}
