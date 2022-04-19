//
//  main.c
//  c_list2
//
//  Created by 曾长欢 on 2022/4/7.
//

#include <stdio.h>
#include "List.h"
void testLinkedList(void);
int main(int argc, const char * argv[]) {
    // insert code here...
    testLinkedList();
    return 0;
}
void testLinkedList() {
   

    int array[10] = {1,3,5,7,9,11,13,15,17,21};
    List list = CreateListWithTail(array, 10);
    printList(list);
    printList(Reverse(list));
    ElementType e;
    GetElem(list, 4, &e);
    printf("L 中第 4 个位置的元素为 \"%d\" \n", e);
    
    LNode *node = LocateElem(list, 13);
    printf("node.next = %d\n",node->next->data);

//    Position P = find(3, list);
//    insert(0, list, P);
//    printList(list);
//
//    delete(1, list);
//    printList(list);
//
//    delete(-1, list);
//    printList(list);
//
//    deleteList(list);
}

