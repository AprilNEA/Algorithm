#include<vector>
#include<iostream>
using namespace std;

bool isInGird(vector<vector<char>>& grid, int r, int c) {
	return 0 <= r < grid.size() && 0 <= c < grid[0].size();
}

void dfs(vector<vector<char>>& grid ,int r,int c){
	if (!isInGird(grid,r,c)) {
		return ;
	}
	if (grid[r][c] != '1') {
		return ;
	}
	grid[r][c] = '2';
	
	dfs(grid,r-1,c);
	dfs(grid,r+1,c);
	dfs(grid,r,c-1);
	dfs(grid,r,c+1);
}


int numIslands(vector<vector<char>>& grid) {
	int ans = 0;
	for (int r=0;r<grid.size();r++) {
		for (int c=0;c<grid[r].size();c++) {
			if (grid[r][c] == '1') {
				ans++;
				dfs(grid,r,c);
			}
		}
	}
	return ans;
}

int main(){

	vector<vector<char>> grid= {{"1","1","1","1","0"},
		{"1","1","0","1","0"},
		{"1","1","0","0","0"},
		{"0","0","0","0","0"}};
	int result = numIslands(gird);
	cout<<result<<endl;
}
