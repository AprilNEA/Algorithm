#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    
    function<bool(int)> check = [&](int pos) {
        for (int i = max(0, pos - 3); i <= min(pos, (int)s.length() - 4); i++) {
            if (s[i] == '1' && s[i + 1] == '1' && 
                s[i + 2] == '0' && s[i + 3] == '0') {
                return true;
            }
        }
        return false;
    };
    
    while (q--) {
        int i, v;
        cin >> i >> v;    
        0 HYT GV  YBJNM.'?
        |7*-     
        i--; // Convert to 0-based indexing
        s[i] = '0' + v;
        cout << (check(i) ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}