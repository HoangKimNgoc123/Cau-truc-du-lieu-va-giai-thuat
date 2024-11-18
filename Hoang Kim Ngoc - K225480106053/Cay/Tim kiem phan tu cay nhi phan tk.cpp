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

Node* SearchNodeRecursion(Tree root, int x) {
    // Nếu cây không rỗng
    if (root != nullptr) {
        // Nếu data của node gốc bằng x cần tìm
        if (root->data == x) {
            // Trả về node gốc của cây
            return root;
        }
        // Nếu data của node gốc lớn hơn x cần tìm
        if (root->data > x) {
            // Gọi lại hàm tìm kiếm theo cây con trái
            return SearchNodeRecursion(root->left, x);
        }
        else { // Ngược lại, data của node gốc nhỏ hơn x cần tìm
            // Gọi lại hàm tìm kiếm theo cây con phải
            return SearchNodeRecursion(root->right, x);
        }
    }
    // Nếu không tìm thấy node có data bằng x thì trả về NULL
    return nullptr;
}

Node* SearchNode(Tree root, int x) {
    // Tạo và gán node p bằng node gốc
    Node* p = root;
    // Duyệt từ node gốc đến hết cây
    while (p != nullptr) {
        // Nếu có data của node p đang xét bằng x cần tìm
        if (p->data == x) {
            // Trả về node đang được xét
            return p;
        }
        else {
            // Nếu phần tử x cần tìm nhỏ hơn data của node đang xét
            if (x < p->data) {
                // Tìm kiếm theo cây con trái
                p = p->left;
            }
            else { // Ngược lại, nếu phần tử x cần tìm lớn hơn data của node đang xét
                // Tìm kiếm theo cây con phải
                p = p->right;
            }
        }
    }
    // Nếu không tìm thấy node có data bằng x thì trả về NULL
    return nullptr;
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
    cout << "\n";
    
    // Tìm kiếm
    int x = 5;
    
    // Tìm kiếm theo hàm có sử dụng đệ quy
    Node* p = SearchNodeRecursion(root, x);
    if (p == nullptr) { // Nếu node p là NULL
        cout << "Khong tim thay node\n";
    }
    else {
        cout << "Tim thay phan tu " << x << " theo phuong phap de quy\n";
    }
    
    // Tìm kiếm theo hàm không dùng đệ quy
    Node* k = SearchNode(root, x);
    if (k == nullptr) { // Nếu node k là NULL
        cout << "Khong tim thay node\n";
    }
    else {
        cout << "Tim thay phan tu " << x << " khong dung de quy\n";
    }
    
    return 0;
}
