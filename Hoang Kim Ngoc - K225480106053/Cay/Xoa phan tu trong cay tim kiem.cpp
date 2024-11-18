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
    // Gán node gốc về NULL
    root = nullptr;
}

Node* CreateNode(int x) {
    // Tạo node mới
    Node* p = new Node;
    // Nếu cây nhị phân không rỗng
    if (p != nullptr) {
        // Gán cây con trái và cây con phải mặc định bằng NULL
        p->left = nullptr;
        p->right = nullptr;
        // Gán data bằng x
        p->data = x;
    }
    // Trả về node p
    return p;
}

int InsertNode(Tree &root, Node* p) {
    // Nếu node root khác NULL thì thực hiện thêm vào cây
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
    else { // Trường hợp nếu node root là NULL thì thêm node p vào node root
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
        // Hiển thị dữ liệu của từng node sau khi duyệt
        cout << root->data << "\t";
        // Sử dụng đệ quy để duyệt tiếp cây con trái
        NLR(root->left);
        // Sử dụng đệ quy để duyệt tiếp cây con phải
        NLR(root->right);
    }
}

void FindReplNode(Tree &p, Tree &q) {
    if (q->left) {
        FindReplNode(p, q->left);
    }
    else {
        p->data = q->data;
        p = q;
        q = q->right;
    }
}

void DeleteNode(Tree &root, int X) {
    // Nếu cây rỗng thì kết thúc hàm xóa
    if (root == nullptr) {
        return;
    }
    // Nếu khóa X nhỏ hơn data của node đang xét
    if (root->data > X) {
        // Đệ quy hàm xóa theo nhánh trái
        return DeleteNode(root->left, X);
    }
    // Nếu khóa X lớn hơn data của node đang xét
    if (root->data < X) {
        // Đệ quy hàm xóa theo nhánh phải
        return DeleteNode(root->right, X);
    }
    // Tạo node p làm node thay thế
    Node* p = root;
    // Nếu cây con trái là rỗng
    if (root->left == nullptr) {
        // Gán lại node gốc theo nhánh phải
        root = root->right;
    }
    else if (root->right == nullptr) { // Nếu cây con phải là rỗng
        // Gán lại node gốc theo nhánh trái
        root = root->left;
    }
    else { // Ngược lại, nếu cây có đủ 2 con
        // Sử dụng node thay thế
        FindReplNode(p, root->right);
    }
    // Xóa đi node p
    delete p;
}

void RemoveTree(Tree &root) {
    // Nếu vẫn tồn tại node gốc
    if (root) {
        // Đệ quy sang nhánh trái
        RemoveTree(root->left);
        // Đệ quy sang nhánh phải
        RemoveTree(root->right);
        // Xóa node gốc
        delete root;
        root = nullptr; // Đảm bảo con trỏ không trỏ đến vùng nhớ đã xóa
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
    // Tạo khóa X = 5
    int X = 5;
    // Gọi hàm xóa node theo khóa X
    DeleteNode(root, X);
    // Duyệt cây sau khi xóa node có khóa X = 5
    cout << "\nCay sau khi xoa node co khoa X = 5\n";
    NLR(root);
    // Gọi hàm hủy toàn bộ cây
    RemoveTree(root);
    return 0;
}
