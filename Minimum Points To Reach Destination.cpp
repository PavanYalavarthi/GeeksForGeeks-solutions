/*
    credits: https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1

    Given a m*n grid with each cell consisting of a positive, negative, or zero integer. We can move across a cell only if we have positive points. Whenever we pass through a cell, points in that cell are added to our overall points, the task is to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :
1. From a cell (i, j) we can move to (i + 1, j) or (i, j + 1).
2. We cannot move from (i, j) if your overall points at (i, j) are <= 0.
3. We have to reach at (m-1, n-1) with minimum positive points i.e., > 0.

*/

class Solution {

  public:
    int minPoints(int m, int n, vector<vector<int>> points) {
        points[m-1][n-1] = max(1, 1 - points[m-1][n-1]);
        for(int j = n - 2; j >= 0; j--) {
            points[m-1][j] = max(1, points[m-1][j+1] - points[m-1][j]);
        }

        for(int i = m - 2; i >= 0; i--) {
            points[i][n-1] = max(1, points[i+1][n-1] - points[i][n-1]);
        }

        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                int need = min(points[i+1][j], points[i][j+1]);
                points[i][j] = max(1, need - points[i][j]);
            }
        }

        return points[0][0];
        
    }
};
