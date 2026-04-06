/*
    Problem credits: https://www.geeksforgeeks.org/problems/find-number-of-closed-islands/1

    Given a binary matrix mat[][] of dimensions NxM such that 1 denotes land and 0 denotes water. Find the number of closed islands in the given matrix.
    An island is a 4-directional(up,right,down and left) connected part of 1's.

    Note: A closed island is a group of 1s surrounded by only 0s on all the boundaries (except diagonals). In simple words, a closed island is an island whose none of the 1s lie on the edges of the matrix.
*/

// User function Template for C++

class Solution {
  public:
    int dir[5] = {1, 0, -1, 0, 1};
    void bfs(vector<vector<int>>& matrix, int i, int j) {
        int m = matrix.size(),  n= matrix[0].size();
        queue<pair<int, int>> q;
        matrix[i][j] = 0;
        q.push({i, j});
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for(int d = 0; d < 4; d++) {
                int new_i = i + dir[d], new_j = j + dir[d+1];
                if (new_i == -1 || new_j == -1 || new_i == m || new_j == n || matrix[new_i][new_j] == 0) continue;
                matrix[new_i][new_j] = 0;
                q.push({new_i, new_j});
            }
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        int m = matrix.size(),  n= matrix[0].size();
        int ans = 0;
        for(int j=0; j<n; j++) {
            if(matrix[0][j]==1) bfs(matrix,0,j);
            if(matrix[m-1][j]==1) bfs(matrix,m-1,j);
        }
        for(int i=0; i<m; i++) {
            if(matrix[i][0]==1) bfs(matrix,i,0);
            if(matrix[i][n-1]==1) bfs(matrix,i,n-1);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j =0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    ans++;
                    bfs(matrix, i, j);
                }
            }
        }
        return ans;
    }
};