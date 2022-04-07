//
//  main.c
//  stack_list
//
//  Created by 曾长欢 on 2022/3/26.
//

#include <stdio.h>
#include "stack.h"
void testLinkedStack(void);

int main(int argc, const char * argv[]) {
   
    testLinkedStack();
    return 0;
}
void testLinkedStack() {
    Stack S = CreateStack();

    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        Push(a[i], S);
    }
    while (Peek(S) != -1) {
        printf("%d, ", Peek(S));
        Pop(S);
    }

    DisposeStack(S);
}
