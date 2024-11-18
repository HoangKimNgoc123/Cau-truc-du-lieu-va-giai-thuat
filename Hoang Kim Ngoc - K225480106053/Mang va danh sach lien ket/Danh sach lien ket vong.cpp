#include <iostream>
using namespace std;

// Định nghĩa cấu trúc một Node của danh sách liên kết vòng
struct Node {
    int data;       // Dữ liệu của Node
    Node* next;     // Con trỏ trỏ đến Node tiếp theo
};

// Hàm tạo một Node mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Hàm chèn Node vào đầu danh sách
void insertAtHead(Node*& tail, int value) {
    Node* newNode = createNode(value);
    if (tail == nullptr) { // Danh sách rỗng
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

// Hàm chèn Node vào cuối danh sách
void insertAtTail(Node*& tail, int value) {
    Node* newNode = createNode(value);
    if (tail == nullptr) { // Danh sách rỗng
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode; // Cập nhật Node cuối
    }
}

// Hàm xóa Node theo giá trị
void deleteNode(Node*& tail, int value) {
    if (tail == nullptr) return; // Danh sách rỗng

    Node* current = tail->next;
    Node* prev = tail;

    // Tìm Node cần xóa
    do {
        if (current->data == value) {
            if (current == tail && current->next == tail) { // Chỉ có 1 Node
                delete current;
                tail = nullptr;
            } else if (current == tail->next) { // Xóa Node đầu
                tail->next = current->next;
                delete current;
            } else if (current == tail) { // Xóa Node cuối
                prev->next = tail->next;
                tail = prev;
                delete current;
            } else { // Xóa Node ở giữa
                prev->next = current->next;
                delete current;
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);

    cout << "Không tìm thấy giá trị " << value << " trong danh sách." << endl;
}

// Hàm tìm kiếm một giá trị trong danh sách
bool search(Node* tail, int value) {
    if (tail == nullptr) return false;

    Node* current = tail->next;
    do {
        if (current->data == value) return true;
        current = current->next;
    } while (current != tail->next);

    return false;
}

// Hàm hiển thị danh sách
void display(Node* tail) {
    if (tail == nullptr) {
        cout << "Danh sách rỗng." << endl;
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "(quay về đầu)" << endl;
}

// Hàm chính
int main() {
    Node* tail = nullptr; // Con trỏ cuối danh sách (đồng thời quản lý danh sách vòng)

    // Chèn Node vào đầu
    insertAtHead(tail, 10);
    insertAtHead(tail, 20);
    insertAtHead(tail, 30);

    cout << "Danh sách sau khi chèn vào đầu: ";
    display(tail);

    // Chèn Node vào cuối
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);

    cout << "Danh sách sau khi chèn vào cuối: ";
    display(tail);

    // Tìm kiếm
    int searchValue = 20;
    if (search(tail, searchValue)) {
        cout << "Tìm thấy giá trị " << searchValue << " trong danh sách." << endl;
    } else {
        cout << "Không tìm thấy giá trị " << searchValue << " trong danh sách." << endl;
    }

    // Xóa Node
    int deleteValue = 30;
    deleteNode(tail, deleteValue);

    cout << "Danh sách sau khi xóa giá trị " << deleteValue << ": ";
    display(tail);

    return 0;
}
