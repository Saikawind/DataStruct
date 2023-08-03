//
// Created by Saika on 2023/8/3.
//
#include "iostream"

using namespace std;
#define ElemType int

// 定义单链表节点类型
typedef struct LNode {
    // 每个节点存放一个数据元素
    ElemType data;
    // 指针指向下一个节点
    struct LNode *next;
} LNode, *LinkList;
// LinkList 强调这是一个单链表
// LNode *  强调这是一个结点

// 不带头结点的单链表
// 初始化一个空的单链表
bool InitList(LinkList &L) {
    // 空表，暂时没有任何结点（防止脏数据）
    L = NULL;
    return true;
}


LNode *GetElem(LinkList L, int i) {
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 判断单链表是否为空
bool Empty(LinkList L) {
    if (L == NULL)
        return true;
    else
        return false;
}

int main() {
    // 声明一个指向单链表的指针
    LinkList L;
    // 初始化一个空表
    InitList(L);


    return 0;
}