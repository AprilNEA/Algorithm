#include<iostream>
using namespace std;

int main() {
    int m,n;
    cin >> m >> n;
    int square = m*n;
    if (m*n % 2 ==0){
        cout << square /2 <<endl;
    } else {
        cout << (square-1)/2 <<endl;
    }
    return 0;
}