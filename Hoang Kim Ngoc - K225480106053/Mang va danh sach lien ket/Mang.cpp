#include <iostream>
using namespace std;

// Hàm hiển thị mảng
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm tìm kiếm tuyến tính
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i; // Trả về vị trí nếu tìm thấy
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

// Hàm sắp xếp chèn
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Dịch chuyển các phần tử lớn hơn key lên một vị trí
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Chèn key vào vị trí đúng
    }
}

// Hàm chính
int main() {
    // Khai báo và khởi tạo mảng
    int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]); // Số phần tử trong mảng

    // Hiển thị mảng ban đầu
    cout << "Mảng ban đầu: ";
    displayArray(arr, n);

    // Tìm kiếm tuyến tính
    int key;
    cout << "Nhập giá trị cần tìm kiếm: ";
    cin >> key;
    int pos = linearSearch(arr, n, key);
    if (pos != -1) {
        cout << "Giá trị " << key << " được tìm thấy tại vị trí " << pos << "." << endl;
    } else {
        cout << "Giá trị " << key << " không có trong mảng." << endl;
    }

    // Sắp xếp mảng
    insertionSort(arr, n);
    cout << "Mảng sau khi sắp xếp tăng dần: ";
    displayArray(arr, n);

    return 0;
}
