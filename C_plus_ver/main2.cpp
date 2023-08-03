#include "iostream"

template<class DataType>
struct Node {
    DataType data;
    Node<DataType> *next;
};

template<class DataType>
class LinkList {
public:
    LinkList();                                // 构造函数
    LinkList(DataType a[], int n);             // 构造函数
    ~LinkList();                               // 析构函数
    int Length();                              // 返回链表长度
    DataType Get(int i);                       // 获取第i个节点的值
    int Locate(DataType x);                    // 查找元素x的位置
    void Insert(int i, DataType x);            // 在第i个位置插入元素x
    DataType Delete(int i);                    // 删除第i个位置的元素
    void PrintList();                          // 打印链表内容

private:
    Node<DataType> *first;                     // 头指针
};

// 默认构造函数
template<class DataType>
LinkList<DataType>::LinkList() {
    first = nullptr;
}

// 有参构造函数
template<class DataType>
LinkList<DataType>::LinkList(DataType a[], int n) {
    first = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        Node<DataType> *newNode = new Node<DataType>;
        newNode->data = a[i];
        newNode->next = first;
        first = newNode;
    }
}

// 析构函数
template<class DataType>
LinkList<DataType>::~LinkList() {
    Node<DataType> *temp;
    while (first != nullptr) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

// 返回链表长度
template<class DataType>
int LinkList<DataType>::Length() {
    int len = 0;
    Node<DataType> *p = first;
    while (p != nullptr) {
        len++;
        p = p->next;
    }
    return len;
}

// 获取第i个节点的值
template<class DataType>
DataType LinkList<DataType>::Get(int i) {
    if (i < 0 || i >= Length()) {
        throw std::out_of_range("Invalid index");
    }
    Node<DataType> *p = first;
    for (int j = 0; j < i; j++) {
        p = p->next;
    }
    return p->data;
}

// 查找元素x的位置
template<class DataType>
int LinkList<DataType>::Locate(DataType x) {
    int pos = 0;
    Node<DataType> *p = first;
    while (p != nullptr) {
        if (p->data == x) {
            return pos;
        }
        pos++;
        p = p->next;
    }
    return -1; // 表示未找到元素x
}

// 在第i个位置插入元素x
template<class DataType>
void LinkList<DataType>::Insert(int i, DataType x) {
    if (i < 0 || i > Length()) {
        throw std::out_of_range("Invalid index");
    }
    if (i == 0) {
        // 插入头部
        Node<DataType> *newNode = new Node<DataType>;
        newNode->data = x;
        newNode->next = first;
        first = newNode;
    } else {
        Node<DataType> *p = first;
        for (int j = 0; j < i - 1; j++) {
            p = p->next;
        }
        Node<DataType> *newNode = new Node<DataType>;
        newNode->data = x;
        newNode->next = p->next;
        p->next = newNode;
    }
}

// 删除第i个位置的元素
template<class DataType>
DataType LinkList<DataType>::Delete(int i) {
    if (i < 0 || i >= Length()) {
        throw std::out_of_range("Invalid index");
    }
    DataType x;
    if (i == 0) {
        // 删除头节点
        Node<DataType> *temp = first;
        first = first->next;
        x = temp->data;
        delete temp;
    } else {
        Node<DataType> *p = first;
        for (int j = 0; j < i - 1; j++) {
            p = p->next;
        }
        Node<DataType> *temp = p->next;
        p->next = temp->next;
        x = temp->data;
        delete temp;
    }
    return x;
}

// 打印链表内容
template<class DataType>
void LinkList<DataType>::PrintList() {
    Node<DataType> *p = first;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 使用有参构造函数创建链表
    LinkList<int> myList(arr, n);

    // 打印链表内容
    std::cout << "Original list: ";
    myList.PrintList();

    // 获取链表长度
    std::cout << "Length: " << myList.Length() << std::endl;

    // 在第2个位置插入元素 10
    myList.Insert(1, 10);
    std::cout << "After inserting 10 at position 2: ";
    myList.PrintList();

    // 删除第3个位置的元素
    myList.Delete(2);
    std::cout << "After deleting element at position 3: ";
    myList.PrintList();

    // 获取第4个位置的元素
    int element = myList.Get(3);
    std::cout << "Element at position 4: " << element << std::endl;

    // 查找元素 5 的位置
    int pos = myList.Locate(5);
    if (pos != -1) {
        std::cout << "Element 5 found at position: " << pos << std::endl;
    } else {
        std::cout << "Element 5 not found in the list" << std::endl;
    }

    return 0;
}

