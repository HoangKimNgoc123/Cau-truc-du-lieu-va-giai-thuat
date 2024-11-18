#include <iostream>
#include <cmath>
using namespace std;

long long Fibonaci(int n) {
    long long F[100];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < n; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n - 1]; // Trả về số Fibonacci thứ n
}

int main() {
    int n;
    cout << "Nhập số lượng số Fibonaci cần tìm: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << Fibonaci(i) << " ";
    }
    return 0;
}
