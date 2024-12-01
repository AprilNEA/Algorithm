#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Store moves as pairs of indices
    vector<pair<int, int>> moves;
    
    // Keep making moves until array is sorted
    while (true) {
        // Check if array is already sorted
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i-1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) break;
        
        // Find a move that brings array closer to sorted state
        bool found_move = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                // Check if difference is exactly 1
                if (abs(a[i] - a[j]) == 1) {
                    // If left number is greater, swap to maintain ascending order
                    if (i < j && a[i] > a[j]) {
                        moves.push_back({i + 1, j + 1});
                        a[i]--;
                        a[j]++;
                        found_move = true;
                        break;
                    }
                    // If right number is greater and should be moved left
                    else if (i > j && a[i] < a[j]) {
                        moves.push_back({j + 1, i + 1});
                        a[j]--;
                        a[i]++;
                        found_move = true;
                        break;
                    }
                }
            }
            if (found_move) break;
        }
    }
    
    // Output results
    cout << moves.size() << '\n';
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}