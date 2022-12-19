#include <iostream>
using namespace std;

int abs(int a) {
    int i = a >> 31;
    return i == 0 ? a : (~a + 1);
}

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                cout << abs(3 - i) + abs(3 - j) << endl;
                return 0;
            }
        }
    }
}
