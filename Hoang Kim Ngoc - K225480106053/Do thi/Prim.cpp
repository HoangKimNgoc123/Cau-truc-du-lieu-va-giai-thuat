#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> Edge; // Định nghĩa cặp (trọng số, đỉnh)

void prim(int n, vector<vector<Edge>>& graph) {
    vector<int> parent(n, -1);       // Mảng lưu đỉnh cha trong cây khung
    vector<int> key(n, INT_MAX);    // Mảng lưu trọng số nhỏ nhất của cạnh kết nối
    vector<bool> inMST(n, false);   // Đánh dấu đỉnh đã thuộc cây khung hay chưa

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Heap ưu tiên

    // Bắt đầu từ đỉnh 0
    key[0] = 0;
    pq.push({0, 0}); // (trọng số, đỉnh)

    while (!pq.empty()) {
        int u = pq.top().second; // Đỉnh u với trọng số nhỏ nhất
        pq.pop();

        if (inMST[u]) continue; // Nếu đã thuộc cây khung, bỏ qua
        inMST[u] = true;

        // Duyệt các cạnh kề của đỉnh u
        for (auto& [weight, v] : graph[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({weight, v});
            }
        }
    }

    // In cây khung nhỏ nhất
    cout << "Cạnh trong cây khung nhỏ nhất:" << endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (trọng số: " << key[i] << ")" << endl;
    }
}

int main() {
    int n = 5; // Số đỉnh
    vector<vector<Edge>> graph(n);

    // Thêm các cạnh vào đồ thị (u, v, weight)
    graph[0].push_back({2, 1});
    graph[1].push_back({2, 0});

    graph[0].push_back({3, 3});
    graph[3].push_back({3, 0});

    graph[1].push_back({3, 2});
    graph[2].push_back({3, 1});

    graph[1].push_back({1, 3});
    graph[3].push_back({1, 1});

    graph[3].push_back({5, 4});
    graph[4].push_back({5, 3});

    graph[2].push_back({4, 4});
    graph[4].push_back({4, 2});

    prim(n, graph);

    return 0;
}
