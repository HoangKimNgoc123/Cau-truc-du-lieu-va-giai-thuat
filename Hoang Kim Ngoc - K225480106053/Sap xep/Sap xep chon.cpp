#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên trong mảng chưa sắp xếp
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Mảng ban đầu: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr, n);

    return 0;
}
