/*
Problem credits: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Solution: basic flood fill algorithm
*/

class Solution {
    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

  public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i == -1 || j == -1 || i == grid.size() || j == grid[0].size() || grid[i][j] == 'W') {
            return;
        }
        
        grid[i][j] = 'W';
        for(int k = 0; k < 8; k++) 
            dfs(grid, i + dr[k], j + dc[k]);
    }
    int countIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 'L') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};