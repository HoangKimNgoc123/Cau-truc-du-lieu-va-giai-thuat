#include <iostream>
#define MAX 100

using namespace std;

// Định nghĩa struct queue
struct Queue {
    int A[MAX];
    int front, rear;
};

// Hàm khởi tạo queue
void Init(Queue &q) {
    q.front = 0;
    q.rear = -1;
}

// Kiểm tra queue rỗng
bool IsEmpty(Queue q) {
    return q.front > q.rear;
}

// Kiểm tra queue đầy
bool IsFull(Queue q) {
    return q.rear == MAX - 1;
}

// Thêm phần tử vào queue
void Add(Queue &q, int x) {
    if (!IsFull(q)) {
        q.rear++;
        q.A[q.rear] = x;
    } else {
        cout << "Queue is full. Cannot add element." << endl;
    }
}

// Lấy phần tử khỏi queue
int Remove(Queue &q) {
    if (!IsEmpty(q)) {
        int x = q.A[q.front];
        q.front++;
        return x;
    } else {
        cout << "Queue is empty. Cannot remove element." << endl;
        // Đặt lại trạng thái queue
        q.front = 0;
        q.rear = -1;
        return -1; // Giá trị trả về mặc định
    }
}

// Nhập các phần tử vào queue
void Input(Queue &q, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
        cin >> x;
        Add(q, x);
    }
}

// Xuất các phần tử trong queue
void Output(Queue q) {
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.A[i] << "\t";
    }
    cout << endl;
}

int main() {
    // Khai báo và khởi tạo queue
    Queue q;
    Init(q);

    // Nhập số lượng phần tử
    int n;
    cout << "NHAP N: ";
    cin >> n;

    // Nhập n phần tử vào queue
    Input(q, n);

    // Hiển thị các phần tử trong queue
    cout << "Cac phan tu vua nhap vao queue la: " << endl;
    Output(q);

    // Thao tác thêm phần tử
    int x = 66;
    Add(q, x);
    cout << "\nHang doi sau khi add " << x << " la: " << endl;
    Output(q);

    // Thao tác lấy phần tử ra khỏi queue
    int front = Remove(q);
    if (front != -1) { // Kiểm tra nếu lấy thành công
        cout << "\nHang doi sau khi remove phan tu " << front << " la: " << endl;
    }
    Output(q);

    return 0;
}
