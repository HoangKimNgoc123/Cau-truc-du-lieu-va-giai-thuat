#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findSet(int u, vector<int>& parent) {
    if (u != parent[u])
        parent[u] = findSet(parent[u], parent); // Path compression
    return parent[u];
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findSet(u, parent);
    v = findSet(v, parent);
    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare); // Sắp xếp các cạnh
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int mst_weight = 0, edge_count = 0;
    for (auto edge : edges) {
        if (findSet(edge.u, parent) != findSet(edge.v, parent)) {
            unionSet(edge.u, edge.v, parent, rank);
            mst_weight += edge.weight;
            edge_count++;
            if (edge_count == n - 1) break;
        }
    }
    return mst_weight;
}

int main() {
    int n, m;
    cout << "Nhập số đỉnh và số cạnh: ";
    cin >> n >> m;
    vector<Edge> edges(m);
    cout << "Nhập các cạnh (u v trọng số):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--; edges[i].v--; // Chuyển về 0-based index
    }
    cout << "Trọng số cây khung nhỏ nhất: " << kruskal(n, edges) << endl;
    return 0;
}
