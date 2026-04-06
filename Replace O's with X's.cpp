/*
    credits: https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

    You are given a grid[][] of size n*m, where every element is either 'O' or 'X'. You have to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

    A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.
*/

class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};

    void bfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(),  n= grid[0].size();
        queue<pair<int, int>> q;
        grid[i][j] = '*';
        q.push({i, j});
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for(int d = 0; d < 4; d++) {
                int new_i = i + dir[d], new_j = j + dir[d+1];
                if (new_i == -1 || new_j == -1 || new_i == m || new_j == n || grid[new_i][new_j] != 'O') continue;
                grid[new_i][new_j] = '*';
                q.push({new_i, new_j});
            }
        }
    }

    void fill(vector<vector<char>>& grid) {
        int m = grid.size(),  n= grid[0].size();
        int ans = 0;
        for(int j=0; j<n; j++) {
            if(grid[0][j]=='O') bfs(grid,0,j);
            if(grid[m-1][j]=='O') bfs(grid,m-1,j);
        }
        for(int i=0; i<m; i++) {
            if(grid[i][0]=='O') bfs(grid,i,0);
            if(grid[i][n-1]=='O') bfs(grid,i,n-1);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j =0; j < n; j++) {
                if (grid[i][j] == '*') {
                    grid[i][j] = 'O';
                } else if (grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};

