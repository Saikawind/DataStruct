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

// 按位序插入（不带带头结点）
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    // 插入第 1 个结点的操作与其他结点操作不同
    if (i == 1) {
        LNode *s = (LNode *) malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        // 头指针指向新结点
        L = s;
        return true;
    }
    // 指针 p 指向当前扫描到的结点
    LNode *p;
    // 当前 p 指向的是第几个结点
    int j = 1;
    // L 指向头结点，头结点是第 0 个结点（不存数据）
    p = L;
    // 循环找到第 i-1 个结点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    // i 值不合法
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    // 将结点 s 连到 p 之后
    p->next = s;
    // 插入成功
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