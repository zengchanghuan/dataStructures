//
//  main.c
//  c_list
//
//  Created by 曾长欢 on 2022/3/26.
//
#include <stdio.h>
#include "Status.h"
#include "linkedList.h"

void PrintElem(ElementType e);
Status CmpGreater(ElementType data, ElementType e);
int main(int argc, const char * argv[]) {

    
    LinkList L;
    int i;
    ElementType e;
    printf("init \n");
    printf("初始化单链表\n");
    InitList(&L);
    printf("IsEmpty %d",IsEmpty(L));
    printf("\n");
    for (int i = 1; i <= 9; i++) {
//        printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2 * i);
        ListInsert(L, i, 2 * i);

    }
    ListTraverse(L, PrintElem);
//    LinkList *list = Reverse(L);
    printf("\n");
//    ListTraverse(*list, PrintElem);

    /*

    printf("length %d",ListLength(L));
    printf("\n");

    ListTraverse(L, PrintElem);
    printf("\n");
    if(ListDelete(L, 6, &e) == OK) {
        printf("删除成功，被删除元素是：\"%d\"\n", e);
    } else {
        printf("删除失败，第 6 个元素不存在！\n");
    }
    
    ListTraverse(L, PrintElem);
    printf("\n");

    GetElem(L, 4, &e);
    printf("L 中第 4 个位置的元素为 \"%d\" \n", e);
    printf("\n");

    
    i = LocateElem(L, 7, CmpGreater);
    GetElem(L, i, &e);
    printf("L 中第一个元素值大于 \"7\" 的元素是 \"%d\" \n", e);
    
    ElementType cur_e = 6;

    if(PriorElem(L, cur_e, &e) == OK) {
        printf("元素 \"%d\" 的前驱为 \"%d\" \n", cur_e, e);
    } else {
        printf("元素 \"%d\" 的前驱不存在！\n", cur_e);
    }
    
    ElementType cur_e2 = 6;

    if(NextElem(L, cur_e2, &e) == OK) {
        printf("元素 \"%d\" 的后继为 \"%d\" \n", cur_e2, e);
    } else {
        printf("元素 \"%d\" 的后继不存在！\n", cur_e2);
    }
    
    printf("清空 L 前：");
    IsEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
    
    ClearList(L);
    
    printf("清空 L 后：");
    IsEmpty(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
    
    printf("销毁 L 前：");
    L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
    
    DestroyList(&L);
    
    printf("销毁 L 后：");
    L ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
    
    /*
    LinkList list;
    
    CreateListHead(&list, 5, "");
    printf("头插法建立单链表 L = ");
    ListTraverse(list, PrintElem);
    
    
    LinkList list2;
    CreateListTail(&list2, 5, "");
    printf("尾插法建立单链表 L = ");
    ListTraverse(list2, PrintElem);

     */
    return 0;
}

void PrintElem(ElementType e) {
    printf("%d ", e);
}
Status CmpGreater(ElementType data, ElementType e) {
    return data > e ? TRUE : FALSE;
}
