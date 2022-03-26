//
//  arrayStack.c
//  stack
//
//  Created by 曾长欢 on 2022/3/26.
//

#include "arrayStack.h"
#include "fatal.h"
#include <stdlib.h>
#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

struct StackRecord {
    int capacity;
    int topOfStack;
    ElementType *array;
};

int IsEmpty(Stack stack) {
    return stack->topOfStack == EmptyTOS;
}

//检测栈是否满
int IsFull(Stack stack) {
    return stack->topOfStack == stack->capacity;
}

//创建栈
Stack CreateStack(int MaxElements) {
    Stack stack;
    if (MaxElements < MinStackSize) {
        Error("stack size is too small");
    }
    stack = malloc(sizeof(struct StackRecord));
    if (stack == NULL) {
        FatalError("out of space!!!");
    }
    
    stack->array = malloc(sizeof(ElementType) * MaxElements);
    if (stack->array == NULL) {
        FatalError("out of space!!!");
    }
    stack->capacity = MaxElements;
    MakeEmpty(stack);
    return stack;
}

//销毁栈
void DisposeStack(Stack Stack) {
    if (Stack != NULL) {
        free(Stack->array);
        free(Stack);
    }
}

//构造空栈
void MakeEmpty(Stack stack) {
    stack->topOfStack = EmptyTOS;
}

//进栈
void Push(ElementType x, Stack stack) {
    if (IsFull(stack)) {
        Error("full stack");
    } else {
        stack->array[++stack->topOfStack] = x;
    }
}

//返回栈顶元素
ElementType Top(Stack stack) {
    if (!IsEmpty(stack)) {
        return stack->array[stack->topOfStack];
    }
    Error("empty stack");
    return 0;
}

//出栈
void Pop(Stack stack) {
    if (IsEmpty(stack)) {
        Error("empty stack");

    } else {
        stack->topOfStack--;
    }
}

//返回栈顶元素并出栈
ElementType TopAndPop(Stack stack) {
    if (!IsEmpty(stack)) {
        return stack->array[stack->topOfStack];
    }
    Error("empty stack");
    return 0;
}

//遍历输出栈
void PrintStack(Stack stack) {
    if (stack == NULL) {
        return;
    }
    
    for (int i = stack->topOfStack; i > EmptyTOS; i--) {
        printf("%d ",stack->array[i]);
    }
    printf("\n");
}
