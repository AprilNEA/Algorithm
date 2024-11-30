#include <bits/stdc++.h>

#define sz(x) ((int) (x).size())

#define fill(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll w,h; cin >> w >> h;
    ll ans = 0;
    for(ll i=1;i<w;i++){
      for(ll j=1;j<h;j++){
        ans += min(i,w-i)*min(j,h-j);
      }
    }
    cout << ans << '\n';
    return 0;
}