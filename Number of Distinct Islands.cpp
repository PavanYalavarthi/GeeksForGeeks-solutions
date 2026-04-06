/*
    credits: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

    Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s 
    (horizontally or vertically) forms an island. 
    
    Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

*/


class Solution {
    string path;
    int dir[5] = {1, 0, -1, 0, 1};
  public:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        grid[i][j] = 0;
        for(int d = 0; d < 4; d++) {
            int new_i = i + dir[d], new_j = j + dir[d+1];
            if (new_i == -1 || new_j == -1 || new_i == m || new_j == n || grid[new_i][new_j] == 0) continue;
            path.push_back(d + '0');
            dfs(grid, new_i, new_j, m, n);
        }
        path.push_back('e');
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<string>s;
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    path.clear();
                    dfs(grid, i, j, m, n);
                    if (s.count(path) == 0) {
                        ans++;
                        s.insert(path);
                    }
                }
            }
        }
        return ans;
    }
};
