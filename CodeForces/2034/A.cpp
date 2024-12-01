#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

long long solve(long long a, long long b) {
    if (a == b) return a;
    
    long long m = min(a, b);
    
    if (gcd(a, b) == 1) {
        return lcm(a, b);
    }
    
    long long l = lcm(a, b);
    

    while (m <= l) {
        if (m >= a || m >= b) {  
            if (m % a == m % b) { 
                return m;
            }
        }
        m++;
    }
    
    return l; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    
    return 0;
}