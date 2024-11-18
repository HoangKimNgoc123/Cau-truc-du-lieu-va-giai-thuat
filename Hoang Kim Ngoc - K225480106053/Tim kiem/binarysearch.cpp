#include <iostream>
using namespace std;


int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;  
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return -1;  
}

int main() {
    int arr[] = {2, 5, 6, 7, 8, 12, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = binarySearch(arr, n, key);
    if (result != -1) {
        cout << "Phần tử " << key << " được tìm thấy tại chỉ số " << result << endl;
    } else {
        cout << "Phần tử không được tìm thấy" << endl;
    }

    return 0;
}
