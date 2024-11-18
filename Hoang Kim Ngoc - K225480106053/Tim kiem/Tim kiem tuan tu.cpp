#include <iostream>
using namespace std;

// Hàm tìm kiếm tuần tự
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Trả về chỉ số của phần tử nếu tìm thấy
        }
    }
    return -1;  // Trả về -1 nếu không tìm thấy phần tử
}

int main() {
    int arr[] = {5, 3, 8, 6, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;

    int result = linearSearch(arr, n, key);
    if (result != -1) {
        cout << "Phần tử " << key << " được tìm thấy tại chỉ số " << result << endl;
    } else {
        cout << "Phần tử không được tìm thấy" << endl;
    }

    return 0;
}
