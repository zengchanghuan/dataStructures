//
//  main.c
//  c_list
//
//  Created by 曾长欢 on 2022/3/26.
//
#include <stdio.h>
#include "list.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("create list");
    List L = NULL;
    L = MakeEmpty(L);        //这边L要重新指向新的头结点

    Insert(1, L, L);
    Insert(2, L, L);
    Insert(3, L, L);
    Insert(4, L, L);
    Insert(5, L, L);
    PrintList(L);
    
    printf("length %d ",ListLength(L));
    return 0;
}
