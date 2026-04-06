/*
    credits: https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

    Given a square chessboard of size (n x n), the initial position and target postion of Knight are given. Find out the minimum steps a Knight will take to reach the target position.

    Note: The initial and the target position coordinates of Knight have been given according to 1-base indexing.
*/

class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        queue<pair<int, int>> q;
        q.push({knightPos[0]-1, knightPos[1]-1});
        visited[knightPos[0]-1][knightPos[1]-1] = true;
        int dir[] = {2, 1, -2, -1, 2, -1, -2, 1, 2};
        for(int level = 0; !q.empty(); level++) {
            int sz = q.size();
            while(sz--) {
                auto [i, j] = q.front();
                q.pop();
                if (i == targetPos[0]-1 && j == targetPos[1]-1) return level;
                for(int k=0;k<8;k++) {
                    int ni = i + dir[k];
                    int nj = j + dir[k+1];

                    if(ni<0 || nj<0 || ni>=n || nj>=n || visited[ni][nj]) continue;

                    visited[ni][nj] = true;
                    q.push({ni,nj});
                }   
            }
            
        }
        return -1;
    }
};