//
// Created by ECCOM on 2022/10/23.
//

#ifndef DATA_STRUCT_LINKLIST_H
#define DATA_STRUCT_LINKLIST_H

#include "iostream"

using namespace std;

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法建表，链表逆序
// [3, 2, 1] => 1->2->3
LinkList CreateList(LinkList &L) {
    LNode *s;
    int x;
    // 建立头结点
    L = (LinkList) malloc(sizeof(LNode));
    // 表尾设置为空
    L->next = NULL;
    cin >> x;
    // 当输入 x 为 9999，中断建表
    while (x != 9999) {
        // 建立一个结点
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}

void PrintList(LinkList L) {
    L = L->next;
    while (L != NULL) {
        cout << L->data << endl;
        L = L->next;
    }
}


#endif //DATA_STRUCT_LINKLIST_H
