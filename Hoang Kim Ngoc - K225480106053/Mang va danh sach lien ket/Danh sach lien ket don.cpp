#include <iostream>
using namespace std;

// Định nghĩa cấu trúc một Node
struct Node {
    int data;       // Dữ liệu của Node
    Node* next;     // Con trỏ trỏ tới Node kế tiếp
};

// Hàm tạo một Node mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Hàm chèn Node vào đầu danh sách
void insertAtHead(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Hàm chèn Node vào cuối danh sách
void insertAtTail(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Hàm xóa Node theo giá trị
void deleteNode(Node*& head, int value) {
    if (head == nullptr) return; // Danh sách rỗng

    // Xóa Node đầu nếu cần
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Tìm và xóa Node ở giữa hoặc cuối
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Không tìm thấy giá trị " << value << " trong danh sách." << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
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

// Hàm hiển thị danh sách liên kết
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

// Hàm chính
int main() {
    Node* head = nullptr; // Danh sách liên kết ban đầu rỗng

    // Chèn Node vào đầu
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    cout << "Danh sách sau khi chèn vào đầu: ";
    display(head);

    // Chèn Node vào cuối
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    cout << "Danh sách sau khi chèn vào cuối: ";
    display(head);

    // Tìm kiếm
    int searchValue = 20;
    if (search(head, searchValue)) {
        cout << "Tìm thấy giá trị " << searchValue << " trong danh sách." << endl;
    } else {
        cout << "Không tìm thấy giá trị " << searchValue << " trong danh sách." << endl;
    }

    // Xóa Node
    int deleteValue = 30;
    deleteNode(head, deleteValue);

    cout << "Danh sách sau khi xóa giá trị " << deleteValue << ": ";
    display(head);

    return 0;
}
