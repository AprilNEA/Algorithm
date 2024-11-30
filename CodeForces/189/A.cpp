#include <bits/stdc++.h>

#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fill(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef long long ll;

int a[3];
int table[6000];

// 表示长度为 n 的绳子能切出的最大段数
int solve(int n) {
    if (n==0) return 0;
	  int &ans = table[n];
	  if (ans != -1) return ans;
	  ans = -1000000;
	  rep(i, 3) if (n >= a[i]) ans = max(ans, solve(n-a[i])+1);
	  return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    fill(table, -1);
    rep(i, 3) cin >> a[i];
    cout << solve(n) << '\n';
    return 0;
}