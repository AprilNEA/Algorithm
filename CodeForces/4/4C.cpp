#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<string, int> namemap;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (namemap.find(a) != namemap.end()) {
            cout << a << ++namemap[a] << endl;

        } else {
            namemap[a] = 0;
            cout << "OK" << endl;
        }
    }
    return 0;
}