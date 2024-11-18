#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hàm thực hiện thuật toán BFS
void BreadthFirstSearch(int v, vector<vector<int>>& graph, vector<int>& daxet) {
    queue<int> q;        // Khởi tạo hàng đợi
    q.push(v);           // Đưa đỉnh bắt đầu vào hàng đợi
    daxet[v] = 1;        // Đánh dấu đỉnh nguồn đã thăm

    // Duyệt qua tất cả các đỉnh trong hàng đợi
    while (!q.empty()) {
        int u = q.front(); // Lấy đỉnh đầu tiên trong hàng đợi
        q.pop();            // Xóa đỉnh khỏi hàng đợi
        cout << u << " ";   // In ra đỉnh vừa lấy

        // Duyệt qua tất cả các đỉnh kề của u
        for (int w : graph[u]) {
            if (daxet[w] == 0) {  // Nếu đỉnh w chưa được thăm
                q.push(w);        // Đưa w vào hàng đợi
                daxet[w] = 1;     // Đánh dấu w là đã thăm
            }
        }
    }
}

int main() {
    // Khai báo đồ thị dưới dạng danh sách kề
    vector<vector<int>> graph = {
        {1, 2},   // Đỉnh 0 kề với 1, 2
        {0, 3, 4}, // Đỉnh 1 kề với 0, 3, 4
        {0, 5},   // Đỉnh 2 kề với 0, 5
        {1},      // Đỉnh 3 kề với 1
        {1},      // Đỉnh 4 kề với 1
        {2}       // Đỉnh 5 kề với 2
    };

    int start = 0;  // Đỉnh nguồn bắt đầu tìm kiếm
    vector<int> daxet(6, 0); // Mảng đánh dấu đã thăm, khởi tạo tất cả là 0

    cout << "Thứ tự các đỉnh trong BFS bắt đầu từ đỉnh " << start << ": ";
    BreadthFirstSearch(start, graph, daxet); // Gọi hàm BFS

    return 0;
}
