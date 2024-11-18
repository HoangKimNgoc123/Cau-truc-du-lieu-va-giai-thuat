#include <iostream>
using namespace std;

// Định nghĩa cấu trúc node
struct Node {
    int data;
    Node* next;
};

// Định nghĩa cấu trúc queue
struct Queue {
    Node* front;
    Node* rear;
};

// Hàm khởi tạo queue
void Init(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

// Hàm tạo node mới
Node* CreateNode(int x) {
    Node* p = new Node;
    if (p == nullptr) {
        cout << "KHONG DU BO NHO!" << endl;
        return nullptr;
    }
    p->data = x;
    p->next = nullptr;
    return p;
}

// Kiểm tra queue rỗng
bool IsEmpty(Queue q) {
    return q.front == nullptr;
}

// Thêm node vào queue
void Add(Queue& q, Node* NewNode) {
    if (q.front == nullptr) {
        q.front = NewNode;
        q.rear = NewNode;
    } else {
        q.rear->next = NewNode;
        q.rear = NewNode;
    }
}

// Lấy node khỏi queue
int Remove(Queue& q) {
    if (IsEmpty(q)) {
        cout << "Queue is empty, cannot remove element!" << endl;
        return -1; // Giá trị mặc định khi lỗi
    }
    int x;
    Node* p = q.front;
    x = p->data;
    q.front = q.front->next;
    delete p;
    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    return x;
}

// Nhập dữ liệu vào queue
void Input(Queue& q, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> x;
        Node* p = CreateNode(x);
        Add(q, p);
    }
}

// Xuất dữ liệu từ queue
void Output(Queue q) {
    for (Node* p = q.front; p != nullptr; p = p->next) {
        cout << p->data << "\t";
    }
    cout << endl;
}

// Hàm chính
int main() {
    Queue q;
    Init(q);

    int n;
    cout << "NHAP N: ";
    cin >> n;

    Input(q, n);
    cout << "CAC PHAN TU TRONG HANG DOI LA" << endl;
    Output(q);

    int x = 66;
    Node* p = CreateNode(x);
    Add(q, p);
    cout << "\nHANG DOI SAU KHI THEM NODE " << x << endl;
    Output(q);

    int k = Remove(q);
    if (k != -1) {
        cout << "\nHANG DOI SAU KHI REMOVE " << k << endl;
    }
    Output(q);

    return 0;
}
