//
// Created by ECCOM on 2022/10/23.
//
#include "iostream"

using namespace std;

// 定义最大长度
#define InitSize 10
#define ElemType int
typedef struct {
    // 指示动态分配数组的指针
    ElemType *data;
    // 顺序表的最大容量
    int MaxSize;
    // 顺序表的当前长度
    int length;
//  顺序表的类型定义（动态分配方式）
} SeqList;

// 基本操作——初始化顺序表
void InitList(SeqList &L) {
    // 用 malloc 函数申请一片连续的存储空间
    L.data = (int *) malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
    // 数组初始化
    for (int i = 0; i < L.MaxSize; i++) {
        L.data[i] = 0;
    }
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        // 将数据复制到新区域
        L.data[i] = p[i];
    }
    // 顺序表最大长度增加 len
    L.MaxSize = L.MaxSize + len;
    // 释放原来的内存空间
    free(p);
}

// 在位序 i 处插入 e
bool ListInsert(SeqList &L, int i, int e) {
    // 数组后移
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 按位查找，返回位序为 i 的值
ElemType GetElem(SeqList L, int i) {
    return L.data[i - 1];
}

// 按值查找，在顺序表 L 中查找第一个值等于 e 的元素，并返回其位序
int LocateElem(SeqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        // 数组下标为 i 的元素值等于 e，返回其位序 i+1
        if (L.data[i] == e)
            return i + 1;
    }
    // 退出循环，说明查找失败
    return 0;
}


int main() {
    // 声明顺序表
    SeqList L;
    // 初始化顺序表
    InitList(L);
    // 增加动态数组长度
    IncreaseSize(L, 5);
    // 在顺序表中随便插入几个元素
    for (int i = 0; i < 5; i++) {
        L.data[i] = i;
        L.length++;
    }
    // 插入元素
    ListInsert(L, 6, 5);
    // 按位查找
    int num = GetElem(L, 2);
    printf("按位查找：%d\n", num);
    // 按值查找
    int num2 = LocateElem(L, 3);
    printf("按值查找：%d\n", num2);
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}
