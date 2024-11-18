#include <iostream>
using namespace std;

// Định nghĩa cấu trúc một Node của danh sách liên kết đôi
struct Node {
    int data;       // Dữ liệu của Node
    Node* next;     // Con trỏ trỏ đến Node tiếp theo
    Node* prev;     // Con trỏ trỏ đến Node trước đó
};

// Hàm tạo một Node mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Hàm chèn Node vào đầu danh sách
void insertAtHead(Node*& head, Node*& tail, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) { // Danh sách rỗng
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Hàm chèn Node vào cuối danh sách
void insertAtTail(Node*& head, Node*& tail, int value) {
    Node* newNode = createNode(value);
    if (tail == nullptr) { // Danh sách rỗng
        head = tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

// Hàm xóa Node theo giá trị
void deleteNode(Node*& head, Node*& tail, int value) {
    if (head == nullptr) return; // Danh sách rỗng

    Node* temp = head;

    // Tìm Node cần xóa
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Không tìm thấy giá trị " << value << " trong danh sách." << endl;
        return;
    }

    // Nếu Node cần xóa là Node đầu
    if (temp == head) {
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr; // Danh sách chỉ còn 1 Node
    }
    // Nếu Node cần xóa là Node cuối
    else if (temp == tail) {
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        else head = nullptr; // Danh sách chỉ còn 1 Node
    }
    // Nếu Node cần xóa nằm ở giữa
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
}

// Hàm tìm kiếm một giá trị trong danh sách
bool search(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

// Hàm hiển thị danh sách từ đầu đến cuối
void displayForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

// Hàm hiển thị danh sách từ cuối về đầu
void displayBackward(Node* tail) {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "null" << endl;
}

// Hàm chính
int main() {
    Node* head = nullptr; // Con trỏ đầu danh sách
    Node* tail = nullptr; // Con trỏ cuối danh sách

    // Chèn Node vào đầu
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);

    cout << "Danh sách sau khi chèn vào đầu: ";
    displayForward(head);

    // Chèn Node vào cuối
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Danh sách sau khi chèn vào cuối: ";
    displayForward(head);

    // Hiển thị danh sách từ cuối về đầu
    cout << "Danh sách từ cuối về đầu: ";
    displayBackward(tail);

    // Tìm kiếm
    int searchValue = 20;
    if (search(head, searchValue)) {
        cout << "Tìm thấy giá trị " << searchValue << " trong danh sách." << endl;
    } else {
        cout << "Không tìm thấy giá trị " << searchValue << " trong danh sách." << endl;
    }

    // Xóa Node
    int deleteValue = 30;
    deleteNode(head, tail, deleteValue);

    cout << "Danh sách sau khi xóa giá trị " << deleteValue << ": ";
    displayForward(head);

    return 0;
}
