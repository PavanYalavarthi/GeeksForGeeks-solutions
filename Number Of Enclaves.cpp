/*
Problem credits: https://www.geeksforgeeks.org/problems/number-of-enclaves/1

You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Solution: Basic dfs from boundary and then adding left over Ones.
*/

// User function Template for C++
class Solution {
    int dir[5] = {1, 0, -1, 0, 1};
  public:
    void dfs(vector<vector<int>> &grid, int i, int j) {
        if (i == -1 || j == -1 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0) return; 
        grid[i][j] = 0;
        for(int k = 0; k < 4; k++) {
            dfs(grid, i + dir[k], j + dir[k+1]);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0 ; i < m; i++) {
            if (grid[i][0]) {
                dfs(grid, i, 0);
            }
            if (grid[i][n-1]) {
                dfs(grid, i, n-1);
            }
        }
        
        for(int i = 0 ; i < n; i++) {
            if (grid[0][i]) {
                dfs(grid, 0, i);
            }
            if (grid[m-1][i]) {
                dfs(grid, m-1, i);
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += (grid[i][j]);
            }
        }
        return ans;
    }
};
