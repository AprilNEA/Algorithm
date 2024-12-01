#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, D, S;
    cin >> N >> D >> S;
    long long highest = S;
    long long curr = S;
 
    while (true) {
        bool found_next = false;
        long long next_floor = N + 1;
        
        for (long long k = 2; k * curr <= N; k++) {
            long long next = curr * k;
            if (next - curr > D) break;
            
            if (next < next_floor) {
                next_floor = next;
                found_next = true;
            }
        }
        
        if (!found_next) break;
        curr = next_floor;
        highest = max(highest, curr);
    }
    
    cout << highest << endl;
    return 0;
}
