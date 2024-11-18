#include <iostream>
using namespace std;

void ThapHaNoi(int n, char nguon, char trunggian, char dich) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu coc " << nguon << " sang coc " << dich << endl;
        return;
    }
    ThapHaNoi(n - 1, nguon, dich, trunggian);
    cout << "Di chuyen dia" << n << " tu coc " << nguon << " sang coc " << dich << endl;
    ThapHaNoi(n - 1, trunggian, nguon, dich);
}

int main() {
    int n;
    cout << "Nhập số lượng đĩa: ";
    cin >> n;
    ThapHaNoi(n, 'A', 'B', 'C');
    return 0;
}
