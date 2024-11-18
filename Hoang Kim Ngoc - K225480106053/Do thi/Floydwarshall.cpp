#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF
                 && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n = 4;  // Số lượng đỉnh trong đồ thị
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Khởi tạo ma trận trọng số của đồ thị
    dist[0][0] = 0;
    dist[0][1] = 3;
    dist[0][2] = INF;
    dist[0][3] = 7;
    
    dist[1][0] = INF;
    dist[1][1] = 0;
    dist[1][2] = 1;
    dist[1][3] = 2;
    
    dist[2][0] = INF;
    dist[2][1] = INF;
    dist[2][2] = 0;
    dist[2][3] = 1;
    
    dist[3][0] = INF;
    dist[3][1] = INF;
    dist[3][2] = INF;
    dist[3][3] = 0;

    // Gọi thuật toán Floyd-Warshall
    floydWarshall(dist, n);

    // In kết quả
    cout << "Ma trận khoảng cách ngắn nhất:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
