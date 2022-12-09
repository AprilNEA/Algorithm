#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans =0;
    for (int i=0;i<n;i++){
        int flag = 0;
        for (int j=0;j<3;j++) {
            int a;
            cin >> a;
            if (a==1) flag +=1;
        }
        if (flag >= 2) ans+=1;     
    }
    cout << ans << endl;
    return 0;
}