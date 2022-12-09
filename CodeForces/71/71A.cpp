#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string words[n];
    for (int i=0;i<n;i++) {
        cin >> words[i];
    }
    for (int i=0;i<n;i++) {
        int l = words[i].size();
        if (l>10) {
            words[i] = words[i][0]+ to_string(l-2)+words[i][l-1];
        }
        cout << words[i] << endl;
    }
    return 0;
}