#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> prices;
    unordered_map<int, ll> revenue;
    for (int i = 0; i < k; i++) {
        int b, c; cin >> b >> c;
        revenue[b] += c;
    }

    priority_queue<ll> pq;
    for (auto u : revenue) pq.push(u.second);

    ll sum = 0;
    for (int i = 0; i < n && !pq.empty(); i++) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << '\n';
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