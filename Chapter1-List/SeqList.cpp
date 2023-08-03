//
// Created by ECCOM on 2022/10/23.
//
#include "iostream"

using namespace std;

// ������󳤶�
#define InitSize 10
#define ElemType int
typedef struct {
    // ָʾ��̬���������ָ��
    ElemType *data;
    // ˳�����������
    int MaxSize;
    // ˳���ĵ�ǰ����
    int length;
//  ˳�������Ͷ��壨��̬���䷽ʽ��
} SeqList;

// ��������������ʼ��˳���
void InitList(SeqList &L) {
    // �� malloc ��������һƬ�����Ĵ洢�ռ�
    L.data = (int *) malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
    // �����ʼ��
    for (int i = 0; i < L.MaxSize; i++) {
        L.data[i] = 0;
    }
}

// ���Ӷ�̬����ĳ���
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *) malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        // �����ݸ��Ƶ�������
        L.data[i] = p[i];
    }
    // ˳�����󳤶����� len
    L.MaxSize = L.MaxSize + len;
    // �ͷ�ԭ�����ڴ�ռ�
    free(p);
}

// ��λ�� i ������ e
bool ListInsert(SeqList &L, int i, int e) {
    // �������
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// ��λ���ң�����λ��Ϊ i ��ֵ
ElemType GetElem(SeqList L, int i) {
    return L.data[i - 1];
}

// ��ֵ���ң���˳��� L �в��ҵ�һ��ֵ���� e ��Ԫ�أ���������λ��
int LocateElem(SeqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        // �����±�Ϊ i ��Ԫ��ֵ���� e��������λ�� i+1
        if (L.data[i] == e)
            return i + 1;
    }
    // �˳�ѭ����˵������ʧ��
    return 0;
}


int main() {
    // ����˳���
    SeqList L;
    // ��ʼ��˳���
    InitList(L);
    // ���Ӷ�̬���鳤��
    IncreaseSize(L, 5);
    // ��˳����������뼸��Ԫ��
    for (int i = 0; i < 5; i++) {
        L.data[i] = i;
        L.length++;
    }
    // ����Ԫ��
    ListInsert(L, 6, 5);
    // ��λ����
    int num = GetElem(L, 2);
    printf("��λ���ң�%d\n", num);
    // ��ֵ����
    int num2 = LocateElem(L, 3);
    printf("��ֵ���ң�%d\n", num2);
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}
