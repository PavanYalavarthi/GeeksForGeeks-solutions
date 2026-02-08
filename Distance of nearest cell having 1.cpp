/*
problem credits: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

Given a binary grid[][], where each cell contains either 0 or 1, find the distance of the nearest 1 for every cell in the grid.
The distance between two cells (i1, j1)  and (i2, j2) is calculated as |i1 - i2| + |j1 - j2|. 
You need to return a matrix of the same size, where each cell (i, j) contains the minimum distance from grid[i][j] to the nearest cell having value 1.

Note: It is guaranteed that there is at least one cell with value 1 in the grid.

*/

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
       int dir[] = { 1, 0, -1, 0, 1 };
       queue<pair<int,int>>q;
       
       int m = grid.size(), n = grid[0].size();
       
       vector<vector<int>>cost(m, vector<int>(n, -1));
       
       for(int i= 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
               if (grid[i][j] == 1) {
                   q.emplace(i, j);
                   cost[i][j] = 0;
               }
           }
       }
       
       while(!q.empty()) {
           auto [i, j] = q.front();
           q.pop();
           for(int k = 0; k <4; k++) {
               int newI = i + dir[k], newJ = j + dir[k+1];
               if (newI == -1 || newJ == -1 || newI == m || newJ == n || cost[newI][newJ] != -1) {
                   continue;
               }
               
               cost[newI][newJ] = cost[i][j] + 1;
               q.emplace(newI, newJ);
           }
       }
       return cost;
    }
};