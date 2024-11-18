#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong ngăn xếp
struct Node {
    int item;         // Dữ liệu
    Node* next;       // Con trỏ trỏ đến nút tiếp theo
};

// Định nghĩa kiểu dữ liệu stack
struct Stack {
    Node* top;        // Con trỏ trỏ đến đỉnh của ngăn xếp
};

// Hàm khởi tạo stack
void initStack(Stack& stack) {
    stack.top = nullptr;
}

// Hàm kiểm tra ngăn xếp có rỗng không
bool isEmpty(Stack& stack) {
    return stack.top == nullptr;
}

// Hàm thêm phần tử vào ngăn xếp
void push(Stack& stack, int value) {
    Node* newNode = new Node(); // Cấp phát bộ nhớ cho nút mới
    newNode->item = value;      // Gán giá trị
    newNode->next = stack.top;  // Liên kết nút mới với nút hiện tại trên đỉnh
    stack.top = newNode;        // Cập nhật đỉnh của stack
}

// Hàm xóa phần tử trên đỉnh ngăn xếp
void pop(Stack& stack) {
    if (isEmpty(stack)) {
        cout << "Stack underflow. Không thể xóa phần tử!\n";
        return;
    }
    Node* temp = stack.top; // Lưu nút hiện tại trên đỉnh
    stack.top = stack.top->next; // Cập nhật đỉnh
    delete temp;           // Giải phóng bộ nhớ của nút cũ
}

// Hàm lấy giá trị phần tử trên cùng mà không xóa
int peek(Stack& stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty.\n";
        return -1;
    }
    return stack.top->item;
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Stack& stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty.\n";
        return;
    }
    Node* temp = stack.top;
    cout << "Các phần tử trong stack: ";
    while (temp != nullptr) {
        cout << temp->item << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Hàm chính
int main() {
    Stack stack;           // Tạo stack
    initStack(stack);      // Khởi tạo stack

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    display(stack);

    cout << "Phần tử trên cùng: " << peek(stack) << endl;

    pop(stack);
    display(stack);

    return 0;
} 