//
//  arrayStack.h
//  stack
//
//  Created by 曾长欢 on 2022/3/26.
//

#ifndef arrayStack_h
#define arrayStack_h

#include <stdio.h>

typedef int ElementType;

struct StackRecord;
typedef struct StackRecord *Stack;

//检测栈是否为空
int IsEmpty(Stack stack);

//检测栈是否满
int IsFull(Stack stack);

//创建栈
Stack CreateStack(int MaxElements);

//销毁栈
void DisposeStack(Stack stack);

//构造空栈
void MakeEmpty(Stack stack);

//进栈
void Push(ElementType x, Stack stack);

//返回栈顶元素
ElementType Top(Stack stack);

//出栈
void Pop(Stack stack);

//返回栈顶元素并出栈
ElementType TopAndPop(Stack stack);

//遍历输出栈
void PrintStack(Stack stack);

#endif /* arrayStack_h */
