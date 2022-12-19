#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (a == "X++" || a == "++X") {
            x++;
        }
        if (a == "X--" || a == "--X") {
            x--;
        }
    }
    cout << x << endl;
    return 0;
}