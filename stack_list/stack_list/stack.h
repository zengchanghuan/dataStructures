//
//  stack.h
//  stack_list
//
//  Created by 曾长欢 on 2022/3/26.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>

typedef int ElementType;
struct Node;
typedef struct Node *PrtToNode;
typedef PrtToNode Stack;

int IsEmpty(Stack s);
Stack CreateStack(void);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType x,Stack s);
void Pop(Stack s);
ElementType Top(Stack s);

#endif /* stack_h */
