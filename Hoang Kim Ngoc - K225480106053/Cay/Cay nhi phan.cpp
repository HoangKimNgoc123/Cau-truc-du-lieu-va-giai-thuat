#include <iostream>
using namespace std;

// Khai báo cấu trúc của Node
struct Node {
    int data;       // Dữ liệu của Node
    Node* left;     // Con trỏ tới cây con trái
    Node* right;    // Con trỏ tới cây con phải
};

// Khai báo kiểu cây nhị phân
typedef Node* Tree;
Tree root;

// Hàm khởi tạo cây
void Init(Tree &root) {   
    root = nullptr; // Gán node gốc bằng nullptr
}

// Hàm tạo một Node mới
Node* CreateNode(int x) {
    // Cấp phát bộ nhớ cho Node mới
    Node* p = new Node;
    // Nếu cấp phát thành công
    if (p != nullptr) {
        p->left = nullptr;  // Gán con trỏ trái là nullptr
        p->right = nullptr; // Gán con trỏ phải là nullptr
        p->data = x;        // Gán dữ liệu cho Node
    }
    return p; // Trả về Node vừa tạo
}

int main() {
    // Tạo cây với node gốc là root
    Tree root;
    // Khởi tạo cây
    Init(root);

    // Tạo một Node ví dụ để kiểm tra
    Node* newNode = CreateNode(10);
    if (newNode != nullptr) {
        cout << "Node created with data: " << newNode->data << endl;
    } else {
        cout << "Failed to create node!" << endl;
    }

    return 0;
}
