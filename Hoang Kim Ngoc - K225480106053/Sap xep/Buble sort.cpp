#include <iostream>
using namespace std;

// Hàm thực hiện Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Biến cờ để kiểm tra nếu không có sự hoán đổi
        bool swapped = false;

        // Duyệt qua các phần tử
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi nếu phần tử trước lớn hơn phần tử sau
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Nếu không có hoán đổi nào, mảng đã được sắp xếp
        if (!swapped) break;
    }
}

// Hàm hiển thị mảng
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm chính
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mảng ban đầu: ";
    displayArray(arr, n);

    bubbleSort(arr, n);

    cout << "Mảng sau khi sắp xếp Bubble Sort: ";
    displayArray(arr, n);

    return 0;
}
