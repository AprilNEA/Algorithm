#include <iostream>
using namespace std;

int main() {
    int d, sumtime;
    cin >> d >> sumtime;
    int mintime = 0;
    int maxtime = 0;
    int time[d][2];
    for (int i = 0; i < d; i++) {
        cin >> time[i][0] >> time[i][1];
        mintime += time[i][0];
        maxtime += time[i][1];
    }
    int time_left = sumtime - mintime;
    if (sumtime >= mintime && sumtime <= maxtime) {
        cout << "YES" << endl;
        for (int i = 0; i < d; i++) {
            int df = time[i][1] - time[i][0];
            while (df > 0) {
                if (time_left == 0)
                    break;
                df--;
                time[i][0]++;
                time_left--;
            }
            cout << time[i][0] << " ";
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}