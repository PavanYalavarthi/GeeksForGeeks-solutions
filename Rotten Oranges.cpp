/*
Problem credits: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

Given a matrix mat[][], where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges

Your task is to determine the minimum time required so that all the oranges become rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

Note: If it is impossible to rot every orange then simply return -1.

Solution: Multi bfs and keep track of fresh oranges left
*/

class Solution {
  public:
    int dir[5] = {1, 0, -1, 0, 1};
    int orangesRot(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), noOfFresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (mat[i][j] == 2) {
                    q.emplace(i, j);
                } else if (mat[i][j] == 1) {
                    noOfFresh++;
                }
            }
        }
        int ans = (q.empty() ? 0 : -1);
        while(!q.empty()) {
            ans++;
            int sz = q.size();
            while(sz--) {
                auto [i, j] = q.front();
                q.pop();
                for(int k = 0; k <4; k++) {
                    int newI = i + dir[k], newJ = j + dir[k+1];
                    if (newI == -1 || newJ == -1 || newI == m || newJ == n || mat[newI][newJ] != 1) {
                        continue;
                    }
                    noOfFresh--;
                    mat[newI][newJ] = 2;
                    q.emplace(newI, newJ);
                }
            }
        }
        return (noOfFresh == 0) ? ans : -1;
    }
};