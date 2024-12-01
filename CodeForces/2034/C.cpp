#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<char>> grid;
    vector<vector<int>> status;  // 0: unvisited, 1: in current path, 2: visited and not in cycle, 3: in cycle
    
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    pair<int, int> getNext(int x, int y) {
        switch(grid[x][y]) {
            case 'U': return {x-1, y};
            case 'D': return {x+1, y};
            case 'L': return {x, y-1};
            case 'R': return {x, y+1};
            default: return {-1, -1};
        }
    }
    
    // 尝试形成最大循环
    bool tryFormCycle(int x, int y) {
        if (!isValid(x, y)) return false;
        if (status[x][y] == 1) return true;  // 找到循环
        if (status[x][y] >= 2) return status[x][y] == 3;  // 已知结果
        
        status[x][y] = 1;  // 标记为当前路径
        
        if (grid[x][y] == '?') {
            bool foundCycle = false;
            char bestDir = 'R';
            // 尝试所有可能的方向
            for (char dir : {'U', 'D', 'L', 'R'}) {
                grid[x][y] = dir;
                auto [nx, ny] = getNext(x, y);
                if (isValid(nx, ny)) {
                    if (tryFormCycle(nx, ny)) {
                        foundCycle = true;
                        bestDir = dir;
                        break;
                    }
                }
            }
            grid[x][y] = bestDir;
            status[x][y] = foundCycle ? 3 : 2;
            return foundCycle;
        } else {
            auto [nx, ny] = getNext(x, y);
            bool result = isValid(nx, ny) && tryFormCycle(nx, ny);
            status[x][y] = result ? 3 : 2;
            return result;
        }
    }
    
public:
    int solve(int rows, int cols, vector<string>& maze) {
        n = rows;
        m = cols;
        grid = vector<vector<char>>(n, vector<char>(m));
        status = vector<vector<int>>(n, vector<int>(m));
        
        // 复制迷宫
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = maze[i][j];
            }
        }
        
        // 尝试为每个起点形成最大循环
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (status[i][j] == 0) {
                    tryFormCycle(i, j);
                }
            }
        }
        
        // 计算陷阱格子数量
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (status[i][j] == 3) count++;
            }
        }
        
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> maze(n);
        for (int i = 0; i < n; i++) {
            cin >> maze[i];
        }
        
        Solution solution;
        cout << solution.solve(n, m, maze) << "\n";
    }
    
    return 0;
}