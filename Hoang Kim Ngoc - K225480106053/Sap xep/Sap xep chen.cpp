#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Lấy phần tử hiện tại
        int j = i - 1;

        // Di chuyển các phần tử lớn hơn key lên một vị trí
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Chèn key vào vị trí đúng
    }
}

int main() {
    vector<int> arr = {5, 3, 4, 1, 2};

    cout << "Mảng trước khi sắp xếp: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    insertionSort(arr);

    cout << "Mảng sau khi sắp xếp: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
