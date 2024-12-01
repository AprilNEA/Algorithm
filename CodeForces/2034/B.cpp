#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve(int n, int m, int k, string& s) {
    vector<int> weak_spots(n);
    for(int i = 0; i < n; i++) {
        weak_spots[i] = (s[i] == '0');
    }
    
    int operations = 0;
    
    for(int i = 0; i <= n - m; i++) {
        bool all_weak = true;
        for(int j = i; j < i + m; j++) {
            if(!weak_spots[j]) {
                all_weak = false;
                break;
            }
        }
        
        if(all_weak) {
            operations++;
            int start = min(i + m - 1, n - k);
            for(int j = start; j < min(start + k, n); j++) {
                weak_spots[j] = 0;
            }
        }
    }
    
    return operations;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    int total_n = 0;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        total_n += n;
        if(total_n > 2e5) {
            return 1;
        }
        
        string s;
        cin >> s;
        
        cout << solve(n, m, k, s) << "\n";
    }
    
    return 0;
}