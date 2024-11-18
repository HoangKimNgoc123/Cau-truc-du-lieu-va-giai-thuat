void dijkstra(int n, int start, vector<vector<pii>>& adj) {
    vector<int> dist(n, INT_MAX);  
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    pq.push({0, start});  
    while (!pq.empty()) {
        int u = pq.top().second;  
        int d = pq.top().first;  
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Không thể đến đỉnh " << i << endl;
        } else {
            cout << "Khoảng cách từ " << start << " đến " << i << " là: " << dist[i] << endl;
        }
    }
}
