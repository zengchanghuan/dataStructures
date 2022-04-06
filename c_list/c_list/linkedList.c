//
//  linkedList.c
//  c_list
//
//  Created by 曾长欢 on 2022/4/6.
//

#include "linkedList.h"
Status InitList (LinkList *L) {
    (*L) = (LinkList) malloc(sizeof(LNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    
    (*L)->next = NULL;
    
    return OK;
}
Status DestroyList (LinkList *L) {
    if (L == NULL || *L == NULL) {
        return ERROR;
    }
    LinkList p = *L;
    while (p != NULL) {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
    *L = NULL;
    return OK;
    
}
Status ClearList (LinkList L) {
    LinkList pre,p;
    if (L == NULL) {
        return ERROR;
    }
    
    p = L->next;
    while (p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }
    L->next = NULL;
    return OK;
}
Status IsEmpty (LinkList L) {
    if (L != NULL && L->next == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}
Status ListLength(LinkList L) {
    LinkList p = L;
    int length = 0;
    if(L == NULL || L->next == NULL) {
        return 0;
    }
    
    p = p->next;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;

}

//获取链表中第i个元素，将其存储到e中
Status GetElem(LinkList L,int i,ElementType *e) {
    if (L == NULL || L->next == NULL) {
        return ERROR;
    }
    LinkList p = L;
    int j = 0;
    
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p->next == NULL || j > i - 1) {
        return ERROR;
    }
    *e = p->next->data;
    return OK;
    
}

//返回链表中首个与e满足Compare关系的元素位序
int LocateElem(LinkList L,ElementType e,Status(Compare)(ElementType,ElementType)) {
    if (L == NULL || L->next == NULL) {
        return 0;
    }
    int i = 1;
    LinkList p = L->next;
    while (p != NULL && !Compare(p->data,e)) {
        i++;
        p = p->next;
    }
    
    if (p != NULL) {
        return i;
    } else {
        return 0;
    }
}

Status PriorElem(LinkList L,ElementType curElement,ElementType *preElement) {
    if (L == NULL || L->next == NULL) {
        return ERROR;
    }
    LinkList pre,next;
    pre = L->next;
    
    if (pre->data == curElement) {
        return ERROR;
    }
    next = pre->next;
    
    while (next != NULL && next->data != curElement) {
        pre = next;
        next = next->next;
    }
    
    if (next == NULL) {
        return ERROR;
    }
    *preElement = pre->data;
    return OK;
}

Status NextElem(LinkList L, ElementType curElement, ElementType *nextElement) {
    if (L == NULL || L->next == NULL) {
        return ERROR;
    }
    LinkList pre = L->next;
    
    while (pre->next != NULL && pre->data != curElement) {
        pre = pre->next;
    }
    
    if (pre->next == NULL) {
        return ERROR;
    }
    *nextElement = pre->next->data;
    return OK;
}

Status ListInsert(LinkList L,int i,ElementType element) {
    if(L == NULL) {
        return ERROR;
    }
    
    LinkList p = L;
    int j = 0;
    LinkList s;
    
    while (p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p == NULL || j > i - 1) {
        return ERROR;
    }
    s = malloc(sizeof(struct Node));
    if (s == NULL) {
        exit(OVERFLOW);
    }
    
    s->data = element;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList L,int i,ElementType *element) {
    if (L == NULL || L->next == NULL) {
        return ERROR;
    }
    
    LinkList p = L;
    int j = 0;
    LinkList q;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p->next == NULL || j > i - 1) {
        return ERROR;
    }
    
    q = p->next;
    p->next = q->next;
    *element = q->data;
    free(q);
    return OK;
}

void ListTraverse(LinkList L,void(Visit)(ElementType)) {
    if (L == NULL || L->next == NULL) {
        return;
    }
    
    LinkList p = L->next;
    
    while (p != NULL) {
        Visit(p->data);
        p = p->next;
    }
    printf("\n");
}
LinkList Reverse(LinkList L) {
    if (L == NULL || L->next == NULL) {
        return L;
    }
    LNode *curr;
    LNode *pre;
    
    curr = L->next;
    L->next = NULL;
    
    while (curr != NULL) {
        pre = curr->next;
        curr->next = L->next;
        L->next = curr;
        curr = pre;
    }
    return L;
}

Status CreateListHead(LinkList *L,int n,char *path) {
    int i;
        LinkList p;
        FILE* fp;
        int readFromConsole;    // 是否从控制台读取数据
        
        // 如果没有文件路径信息，则从控制台读取输入
        readFromConsole = path == NULL || strcmp(path, "") == 0;
        
        if(readFromConsole) {
            // 建立头结点
            *L = (LinkList) malloc(sizeof(LNode));
            (*L)->next = NULL;
            
            printf("请输入%d个降序元素：", n);
            
            for(i = 1; i <= n; ++i) {
                // 生成新结点
                p = (LinkList) malloc(sizeof(LNode));
                
                // 填充数据，并插入到链表中
                scanf("%d", &(p->data));
                
                p->next = (*L)->next;
                (*L)->next = p;
            }
        } else {
            // 打开文件，准备读取测试数据
            fp = fopen(path, "r");
            if(fp == NULL) {
                return ERROR;
            }
            
            // 建立头结点
            *L = (LinkList) malloc(sizeof(LNode));
            (*L)->next = NULL;
            
            for(i = 1; i <= n; ++i) {
                // 生成新结点
                p = (LinkList) malloc(sizeof(LNode));
                
                // 填充数据，并插入到链表中
                ReadData(fp, "%d", &(p->data));
                
                p->next = (*L)->next;
                (*L)->next = p;
            }
            
            fclose(fp);
        }
        
        return OK;
}

Status CreateListTail(LinkList *L,int n,char *path) {
    int i;
       LinkList p, q;
       FILE* fp;
       int readFromConsole;    // 是否从控制台读取数据
       
       // 如果没有文件路径信息，则从控制台读取输入
       readFromConsole = path == NULL || strcmp(path, "") == 0;
       
       if(readFromConsole) {
           // 建立头结点
           *L = (LinkList) malloc(sizeof(LNode));
           (*L)->next = NULL;
           
           printf("请输入%d个升序元素：", n);
           
           for(i = 1, q = *L; i <= n; ++i) {
               // 生成新结点
               p = (LinkList) malloc(sizeof(LNode));
               
               // 填充数据，并插入到链表中
               scanf("%d", &(p->data));
               
               q->next = p;
               q = q->next;
           }
           
           q->next = NULL;
       } else {
           // 打开文件，准备读取测试数据
           fp = fopen(path, "r");
           if(fp == NULL) {
               return ERROR;
           }
           
           // 建立头结点
           *L = (LinkList) malloc(sizeof(LNode));
           (*L)->next = NULL;
           
           for(i = 1, q = *L; i <= n; ++i) {
               // 生成新结点
               p = (LinkList) malloc(sizeof(LNode));
               
               // 填充数据，并插入到链表中
               ReadData(fp, "%d", &(p->data));
               
               q->next = p;
               q = q->next;
           }
           
           q->next = NULL;
           
           fclose(fp);
       }
       
       return OK;
}
// 头插法创建单链表
LinkList CreateHeadListWithHead(ElementType *array, int length) {
    LinkList head;
    LNode *newNode;
    
    head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    for (int i = 0; i < length; i++) {
        newNode = (LinkList)malloc(sizeof(LNode));
        newNode->data = array[i];
        newNode->next = head->next;
        head->next = newNode;
    }
    return head;
}

LinkList CreateHeadListWithTail(ElementType *array, int length) {
    LinkList head;
    LNode *p,*newNode;
    head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;
    p = head;
    
    for (int i = 0; i < length; i++) {
        newNode = (LinkList)malloc(sizeof(struct Node));
        newNode->data = array[i];
        newNode->next = NULL;
        p->next = newNode;
        p = newNode;
    }
    return head;
}

