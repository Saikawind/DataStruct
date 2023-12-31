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

// 初始化一个带头结点的空的单链表
bool InitList(LinkList &L) {
    // 空表，暂时没有任何结点（防止脏数据）
    L = NULL;
    return true;
}

// 后插操作：在 p 结点之后插入元素 e
bool InsertNextNode(LNode *p, ElemType e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    // 内存分配失败
    if (s == NULL)
        return false;
    s->data = e;
    // 将结点 s 连到 p 之后
    s->next = p->next;
    p->next = s;
    return true;
}

// 按位序插入（带头结点）
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    // 指针 p 指向当前扫描到的结点
    LNode *p;
    // 当前 p 指向的是第几个结点
    int j = 0;
    // L 指向头结点，头结点是第 0 个结点（不存数据）
    p = L;
    // 循环找到第 i-1 个结点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    return InsertNextNode(p, e);
    // i 值不合法
    // if (p == NULL)
    //     return false;
    // LNode *s = (LNode *) malloc(sizeof(LNode));
    // s->data = e;
    // s->next = p->next;
    // // 将结点 s 连到 p 之后
    // p->next = s;
    // // 插入成功
    // return true;
}

// 前插操作：在 p 结点之前插入元素 e，时间复杂度 O(1)
bool InsertPriorNode(LNode *p, ElemType e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    // 内存分配失败
    if (s == NULL)
        return false;
    s->next = p->next;
    // 新结点 s 连到 p 之后
    p->next = s;
    // 将 p 中元素复制到 s 中
    s->data = p->data;
    // p 中元素覆盖为 e
    p->data = e;
    return true;
}

// 删除指定结点 p
bool DeleteNode(LNode *p) {
    if (p == NULL)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}


// 按序查找
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
    //
    ListInsert(L, 2, 1);


    return 0;
}