#include <iostream>
using namespace std;

struct Node {
    // Khai báo dữ liệu của node có kiểu int
    int data;
    // Khai báo con trỏ đến cây con trái
    Node* left;
    // Khai báo con trỏ đến cây con phải
    Node* right;
};
typedef Node* Tree;

void Init(Tree &root) {
    // Gán node gốc về nullptr
    root = nullptr;
}

Node* CreateNode(int x) {
    // Tạo node mới
    Node* p = new Node;
    // Nếu cây nhị phân không rỗng
    if (p != nullptr) {
        // Gán cây con trái và cây con phải mặc định bằng nullptr
        p->left = nullptr;
        p->right = nullptr;
        // Gán data bằng x
        p->data = x;
    }
    // Trả về node p
    return p;
}

int InsertNode(Tree &root, Node* p) {
    // Nếu node root khác nullptr thì thực hiện thêm vào cây
    if (root != nullptr) {
        // Nếu 2 data của 2 node bằng nhau thì kết thúc
        if (root->data == p->data) {
            return 0;
        }
        // Nếu khóa của root lớn hơn khóa của p thì gọi đệ quy trái
        if (root->data > p->data) {
            return InsertNode(root->left, p);
        }
        else { // Nếu khóa của root nhỏ hơn khóa của p thì gọi đệ quy phải
            return InsertNode(root->right, p);
        }
    }
    else { // Trường hợp nếu node root là nullptr thì thêm node p vào node root
        root = p;
    }
}

void Input(Tree &root) {
    int n;
    cout << "Nhap so luong node can them: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cout << "Nhap data cua node " << i << ": ";
        cin >> x;
        // Tạo node p có data = x
        Node* p = CreateNode(x);
        // Thêm node p có data x vào trong cây
        InsertNode(root, p);
    }
}

void NLR(Tree root) {
    if (root != nullptr) {
        // Xử lý node gốc
        cout << root->data << "\t";
        // Sử dụng đệ quy để duyệt tiếp cây con trái
        NLR(root->left);
        // Sử dụng đệ quy để duyệt tiếp cây con phải
        NLR(root->right);
    }
}

void LNR(Tree root) {
    if (root != nullptr) {
        // Sử dụng đệ quy để duyệt tiếp cây con trái
        LNR(root->left);
        // Xử lý node gốc
        cout << root->data << "\t";
        // Sử dụng đệ quy để duyệt tiếp cây con phải
        LNR(root->right);
    }
}

void LRN(Tree root) {
    if (root != nullptr) {
        // Sử dụng đệ quy để duyệt tiếp cây con trái
        LRN(root->left);
        // Sử dụng đệ quy để duyệt tiếp cây con phải
        LRN(root->right);
        // Xử lý node gốc
        cout << root->data << "\t";
    }
}

int main() {
    // Tạo cây với node gốc là root
    Tree root;
    // Khởi tạo cây
    Init(root);
    // Nhập n phần tử vào cây
    Input(root);
    // Duyệt cây theo NLR
    cout << "Duyet cay theo NLR\n";
    NLR(root);
    // Duyệt cây theo LNR
    cout << "\nDuyet cay theo LNR\n";
    LNR(root);
    // Duyệt cây theo LRN
    cout << "\nDuyet cay theo LRN\n";
    LRN(root);

    return 0;
}
