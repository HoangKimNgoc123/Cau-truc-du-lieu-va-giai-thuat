#include <iostream>
using namespace std;

// Hàm hoán đổi hai phần tử
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân vùng (partition)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Chọn phần tử cuối làm pivot
    int i = low - 1;  // Chỉ số cho phần tử nhỏ hơn pivot

    // Di chuyển các phần tử nhỏ hơn pivot sang bên trái
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  // Tăng chỉ số phần tử nhỏ hơn pivot
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  // Đặt pivot vào đúng vị trí
    return i + 1;
}

// Hàm Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Phân vùng mảng
        int pi = partition(arr, low, high);

        // Đệ quy sắp xếp các phần tử trước và sau pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Mảng ban đầu: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr, n);

    return 0;
}
