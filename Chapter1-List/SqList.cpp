//
// Created by ECCOM on 2022/10/23.
//
#include "iostream"

using namespace std;

// ������󳤶�
#define MaxSize 10
#define ElemType int
typedef struct {
    // �þ�̬�ġ����顱�������Ԫ��
    ElemType data[MaxSize];
    // ˳���ĵ�ǰ����
    int length;
//  ˳�������Ͷ��壨��̬���䷽ʽ��
} SqList;

// ��������������ʼ��˳���
void InitList(SqList &L) {
    for (int i = 0; i < MaxSize; ++i) {
        // ����������Ԫ������ΪĬ�ϳ�ʼֵ
        L.data[i] = 0;
    }
    // ˳����ʼ����Ϊ 0
    L.length = 0;
}

// �� L ��λ�� i ������Ԫ�� e
bool ListInsert(SqList &L, int i, int e) {
    // �ж� i �ķ�Χ�Ƿ���Ч
    if (i < 1 || i > L.length + 1) {
        printf("λ��Խ��\n");
        return false;
    }
    // ��ǰ�洢�ռ����������ܲ���
    if (L.length >= MaxSize) {
        printf("��ǰ�洢�ռ����������ܲ���\n");
        return false;
    }
    // ���� i ��Ԫ�ؼ�֮���Ԫ�غ���
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    // ��λ�� i ������ e
    L.data[i - 1] = e;
    // ���ȼ� 1
    L.length++;
    return true;
}

// ɾ��λ��Ϊ i ����ֵ������ e ����ɾ����ֵ
bool ListDelete(SqList &L, int i, int &e) {
    // �ж� i �ķ�Χ�Ƿ���Ч
    if (i < 1 || i > L.length) {
        printf("λ��Խ�磬ɾ��ʧ��\n");
        return false;
    }
    // ����ɾ����Ԫ�ظ�ֵ�� e
    e = L.data[i - 1];
    // ���� i ��λ�ú��Ԫ��ǰ��
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    // ���Ա��ȼ� 1
    L.length--;
    printf("��ɾ����3��Ԫ�أ�ɾ��Ԫ��ֵΪ%d\n", e);
    return true;
}

ElemType GetElem(SqList L, int i) {
    return L.data[i - 1];
}

int main() {
    // ����˳���
    SqList L;
    // ��ʼ��˳���
    InitList(L);
    for (int i = 0; i < 6; i++) {
        L.data[i] = i;
        L.length++;
    }
    // ����Ԫ��
    ListInsert(L, 7, 6);
    int e = 0;
    ListDelete(L, 3, e);
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}
