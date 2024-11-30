#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll rob(vector<ll>& cnt) {
    int n = cnt.size();
    vector<ll> dp(n);
    dp[0] = 0;
    if (n > 1) dp[1] = cnt[1];
    
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + cnt[i]);
    }
    return dp[n-1];
}

void solve() {
    int n; cin >> n;

    vector<int> nums(n);
    int maxNum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        maxNum = max(maxNum, nums[i]);
    }
    vector<ll> cnt(maxNum + 1, 0);
    for (int x : nums) {
        cnt[x] += x;
    }
    cout << rob(cnt) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}