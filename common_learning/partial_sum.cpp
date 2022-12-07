#include<iostream>

using namespace std;

int sum(int table[3][3], int r,int c) {
    
    int res = 0;
    if (r<0 || c<0) return 0;

    if (r == 0) {
        if (c > 0) {
            for (int i=0; i<=c;i++){
                res += table[0][i];
            }
            return res;
        }
        
    }
    if (c == 0) {
        if (r > 0) {
            for (int i=0; i<=r;i++){
                res += table[i][0];
            }
            return res;
        }
    }
    return sum(table,r  ,c-1) 
         + sum(table,r-1,c)
         - sum(table,r-1,c-1) 
         + table[r][c];
}
int main () {
    int table[3][3] = {{1,3,4},{2,3,4},{4,5,7}};
    cout << sum(table,0,0)<<endl;
    cout << sum(table,0,1)<<endl;
    cout << sum(table,1,1)<<endl;
}