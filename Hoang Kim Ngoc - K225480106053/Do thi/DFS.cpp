#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100; // Giới hạn số đỉnh tối đa
int daxet[MAX] = {0}; // Mảng đánh dấu các đỉnh đã thăm
vector<int> adj[MAX]; // Danh sách kề

void DeepFirstSearch(int v) {
    // Thăm đỉnh v
    cout << v << " ";
    daxet[v] = 1; // Đánh dấu đỉnh đã thăm

    // Duyệt các đỉnh kề với v
    for (int u : adj[v]) {
        if (daxet[u] == 0) { // Nếu đỉnh u chưa được thăm
            DeepFirstSearch(u); // Gọi đệ quy với đỉnh u
        }
    }
}

int main() {
    int n, m; // n: số đỉnh, m: số cạnh
    cout << "Nhập số đỉnh và số cạnh: ";
    cin >> n >> m;

    cout << "Nhập các cạnh (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Nếu đồ thị có hướng, bỏ dòng này
    }

    cout << "Kết quả duyệt DFS bắt đầu từ đỉnh 1: ";
    DeepFirstSearch(1);

    return 0;
}
