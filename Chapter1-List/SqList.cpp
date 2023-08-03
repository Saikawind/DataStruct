//
// Created by ECCOM on 2022/10/23.
//
#include "iostream"

using namespace std;

// 定义最大长度
#define MaxSize 10
#define ElemType int
typedef struct {
    // 用静态的“数组”存放数据元素
    ElemType data[MaxSize];
    // 顺序表的当前长度
    int length;
//  顺序表的类型定义（静态分配方式）
} SqList;

// 基本操作——初始化顺序表
void InitList(SqList &L) {
    for (int i = 0; i < MaxSize; ++i) {
        // 将所有数据元素设置为默认初始值
        L.data[i] = 0;
    }
    // 顺序表初始长度为 0
    L.length = 0;
}

// 在 L 的位序 i 处插入元素 e
bool ListInsert(SqList &L, int i, int e) {
    // 判断 i 的范围是否有效
    if (i < 1 || i > L.length + 1) {
        printf("位序越界\n");
        return false;
    }
    // 当前存储空间已满，不能插入
    if (L.length >= MaxSize) {
        printf("当前存储空间已满，不能插入\n");
        return false;
    }
    // 将第 i 个元素及之后的元素后移
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    // 在位置 i 处放入 e
    L.data[i - 1] = e;
    // 长度加 1
    L.length++;
    return true;
}

// 删除位序为 i 处的值，并以 e 返回删除的值
bool ListDelete(SqList &L, int i, int &e) {
    // 判断 i 的范围是否有效
    if (i < 1 || i > L.length) {
        printf("位序越界，删除失败\n");
        return false;
    }
    // 将被删除的元素赋值给 e
    e = L.data[i - 1];
    // 将第 i 个位置后的元素前移
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    // 线性表长度减 1
    L.length--;
    printf("已删除第3个元素，删除元素值为%d\n", e);
    return true;
}

ElemType GetElem(SqList L, int i) {
    return L.data[i - 1];
}

int main() {
    // 声明顺序表
    SqList L;
    // 初始化顺序表
    InitList(L);
    for (int i = 0; i < 6; i++) {
        L.data[i] = i;
        L.length++;
    }
    // 插入元素
    ListInsert(L, 7, 6);
    int e = 0;
    ListDelete(L, 3, e);
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}
