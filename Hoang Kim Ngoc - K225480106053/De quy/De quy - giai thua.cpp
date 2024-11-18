#include<iostream>
using namespace std;

int Giaithua (int n){
    if (n <= 1) return 1;
    else return Giaithua (n-1) * n;
}

int main(){
    int n; cin >> n;
    cout << "Giai thua cua " << n << " la: ";
    cout << Giaithua(n);
    return 0;
}