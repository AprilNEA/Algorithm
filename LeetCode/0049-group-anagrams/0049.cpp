#include <string.h>
#include<vector>
#include<iostream>
using namespace std;

int main() {
	
	int x = 1;
	x++;
	x--;
	
	int y;
	y = x * 2;
	
	int z = x * 3;
	
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
	
	float d = 3.14;
	bool c = false;
	
	cout << d << endl;
	cout << c << endl;
	
	return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> mp;
	for (string& str: strs) {
		string key = str;
		sort(key.begin(), key.end());
		mp[key].emplace_back(str);
	}
	vector<vector<string>> ans;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		ans.emplace_back(it->second);
	}
	return ans;
}
