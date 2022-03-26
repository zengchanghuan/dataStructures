//
//  main.c
//  stack_array
//
//  Created by 曾长欢 on 2022/3/26.
//

#include <stdio.h>
#include "arrayStack.h"

int main(int argc, const char * argv[]) {
    Stack S = CreateStack(10);

       printf("栈S%s为空\n", IsEmpty(S)?"":"不");

       Push(1, S);
       Push(3, S);
       Push(5, S);
       Push(7, S);
       Push(9, S);
       PrintStack(S);

       printf("两次出栈后：");
       Pop(S);
       Pop(S);
       PrintStack(S);

       DisposeStack(S);
    return 0;
}
