#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, vector<Edge>& edges, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    for (int i = 1; i < V; i++) {
        for (auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    for (auto& edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
            cout << "Đồ thị có chu trình âm!" << endl;
            return;
        }
    }

    for (int i = 0; i < V; i++) {
        cout << "Khoảng cách từ đỉnh " << source << " đến đỉnh " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "Không thể đến" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

int main() {
    int V = 5;  // Số đỉnh
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(V, edges, 0);

    return 0;
}
