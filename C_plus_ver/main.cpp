#include <iostream>

const int MaxSize = 100;

template<class DataType> //模板类
class SeqList {
public:
    SeqList(); //构造函数
    SeqList(DataType a[], int n);

    ~SeqList(); //析构函数
    int Length();

    DataType Get(int i);

    int Locate(DataType x);

    void Insert(int i, DataType x);

    DataType Delete(int i);

private:
    DataType data[MaxSize];
    int length;
};

template<class DataType>
SeqList<DataType>::SeqList() {
    length = 0;
}

template<class DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
    if (n > MaxSize)
        throw "数组长度超过最大值";
    for (int i = 0; i < n; i++)
        data[i] = a[i];
    length = n;
}

template<class DataType>
SeqList<DataType>::~SeqList() {
}

template<class DataType>
int SeqList<DataType>::Length() {
    return length;
}

template<class DataType>
DataType SeqList<DataType>::Get(int i) {
    if (i >= 1 && i <= length)
        return data[i - 1];
    else
        throw "位置不合法";
}

template<class DataType>
int SeqList<DataType>::Locate(DataType x) {
    for (int i = 0; i < length; i++) {
        if (data[i] == x)
            return i + 1;
    }
    return 0;
}

template<class DataType>
void SeqList<DataType>::Insert(int i, DataType x) {
    if (length >= MaxSize)
        throw "顺序表已满，无法插入";
    if (i < 1 || i > length + 1)
        throw "位置不合法";
    for (int j = length; j >= i; j--)
        data[j] = data[j - 1];
    data[i - 1] = x;
    length++;
}

template<class DataType>
DataType SeqList<DataType>::Delete(int i) {
    if (length == 0)
        throw "顺序表为空，无法删除";
    if (i < 1 || i > length)
        throw "位置不合法";
    DataType x = data[i - 1];
    for (int j = i; j < length; j++)
        data[j - 1] = data[j];
    length--;
    return x;
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    SeqList<int> list(a, 5);
    std::cout << "Length: " << list.Length() << std::endl;
    std::cout << "Get(3): " << list.Get(3) << std::endl;
    std::cout << "Locate(4): " << list.Locate(4) << std::endl;

    list.Insert(2, 6);
    std::cout << "After Insert(2, 6): ";
    for (int i = 1; i <= list.Length(); i++)
        std::cout << list.Get(i) << " ";
    std::cout << std::endl;

    list.Delete(3);
    std::cout << "After Delete(3): ";
    for (int i = 1; i <= list.Length(); i++)
        std::cout << list.Get(i) << " ";
    std::cout << std::endl;

    return 0;
}
