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
    /*
    List L = NULL;
    L = MakeEmpty(L);        //这边L要重新指向新的头结点

    Insert(1, L, L);
    Insert(2, L, L);
    Insert(3, L, L);
    Insert(4, L, L);
    Insert(5, L, L);
    */
    int datas[] = {2, 4, 6, 8, 10};
    // 动态计算datas数组的长度
    // 数组长度 = 数组的总空间大小 / 数组中每个元素所占空间大小
    int len = sizeof(datas) / sizeof(datas[0]);
    List L = CreateHeadListWithHead(datas, len);
    Travel(L);
    
    
    List L2 = CreateHeadListWithTail(datas, len);
    printf("IsEmpty = %d\n",IsEmpty(L2));
    Travel(L2);
    
    printf("length %d ",ListLength(L));
    return 0;
}
