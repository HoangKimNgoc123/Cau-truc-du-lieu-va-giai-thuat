#include <iostream>
using namespace std;

#define MAX 100 // Kích thước tối đa của ngăn xếp

struct Stack {
    int arr[MAX]; // Mảng lưu trữ các phần tử
    int top;      // Chỉ số của phần tử trên cùng
};

// Khởi tạo ngăn xếp
void initStack(Stack &s) {
    s.top = -1; // Ban đầu, ngăn xếp rỗng
}

// Kiểm tra ngăn xếp rỗng
bool isEmpty(Stack s) {
    return s.top == -1;
}

// Kiểm tra ngăn xếp đầy
bool isFull(Stack s) {
    return s.top == MAX - 1;
}

// Đẩy (push) một phần tử vào ngăn xếp
bool push(Stack &s, int value) {
    if (isFull(s)) {
        cout << "Stack overflow\n";
        return false;
    }
    s.arr[++s.top] = value;
    return true;
}

// Lấy (pop) một phần tử ra khỏi ngăn xếp
bool pop(Stack &s, int &value) {
    if (isEmpty(s)) {
        cout << "Stack underflow\n";
        return false;
    }
    value = s.arr[s.top--];
    return true;
}

// Lấy phần tử trên cùng (không xóa)
bool peek(Stack s, int &value) {
    if (isEmpty(s)) {
        cout << "Stack is empty\n";
        return false;
    }
    value = s.arr[s.top];
    return true;
}

int main() {
    Stack s;
    initStack(s);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    int value;
    while (pop(s, value)) {
        cout << value << " ";
    }
    return 0;
}