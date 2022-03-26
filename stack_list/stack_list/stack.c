//
//  stack.c
//  stack_list
//
//  Created by 曾长欢 on 2022/3/26.
//

#include "stack.h"
#include "fatal.h"
#include <stdlib.h>

struct Node {
    ElementType element;
    PrtToNode next;
};
int IsEmpty(Stack s) {
    return s->next == NULL;
}
Stack CreateStack(void) {
    Stack stack;
    stack = malloc(sizeof(struct Node));
    if (stack == NULL) {
        FatalError("out of space!!!");
    }
    stack->next = NULL;
    MakeEmpty(stack);
    return stack;
}
void DisposeStack(Stack stack) {
    MakeEmpty(stack);
    free(stack);
}
void MakeEmpty(Stack stack) {
    if (stack == NULL) {
        Error("must use createStack first");
    } else {
        while (!IsEmpty(stack)) {
            Pop(stack);
        }
    }
}
void Push(ElementType x,Stack stack) {
    PrtToNode tempCell;
    tempCell = malloc(sizeof(struct Node));
    if (tempCell == NULL) {
        FatalError("out of space!!!");
    } else {
        tempCell->element = x;
        tempCell->next = stack->next;
        stack->next = tempCell;
    }
}
void Pop(Stack stack) {
    PrtToNode firstCell;
    if (IsEmpty(stack)) {
        Error("empty stack");
    } else {
        firstCell = stack->next;
        stack->next = stack->next->next;
        free(firstCell);
    }
}
ElementType Top(Stack stack) {
    if (!IsEmpty(stack)) {
        return stack->next->element;
    }
    Error("error stack");
    return 0;
}
