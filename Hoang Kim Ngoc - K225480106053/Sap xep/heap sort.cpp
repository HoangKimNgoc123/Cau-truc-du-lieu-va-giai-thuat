#include <iostream>
using namespace std;

// Hàm xây dựng heap (heapify)
void heapify(int arr[], int n, int i) {
    int largest = i;        // Khởi tạo phần tử gốc là lớn nhất
    int left = 2 * i + 1;   // Chỉ số con trái
    int right = 2 * i + 2;  // Chỉ số con phải

    // Kiểm tra nếu con trái lớn hơn gốc
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Kiểm tra nếu con phải lớn hơn gốc
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Nếu phần tử lớn nhất không phải gốc, hoán đổi và đệ quy
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Đệ quy vào node con
    }
}

// Hàm thực hiện Heap Sort
void heapSort(int arr[], int n) {
    // Xây dựng heap tối đa
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Trích xuất từng phần tử ra khỏi heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Chuyển phần tử lớn nhất về cuối
        heapify(arr, i, 0);   // Gọi heapify trên phần còn lại
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mảng ban đầu: ";
    displayArray(arr, n);

    heapSort(arr, n);

    cout << "Mảng sau khi sắp xếp Heap Sort: ";
    displayArray(arr, n);

    return 0;
}
