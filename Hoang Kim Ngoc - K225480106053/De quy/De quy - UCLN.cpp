#include<iostream>
using namespace std;
int UCLN (int a, int b){
    if(b == 0) return a;
    else return UCLN(b, a % b);
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << UCLN(a, b);
    return 0;
}