/*
Problem credits: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.


*/

class Solution {
  public:
    bool isValid(vector<vector<int>> &mat, int ele) {
        int cnt = 0;
        for(auto& v: mat) {
            if (ele >= v.front()) {
                 cnt += upper_bound(v.begin(), v.end(), ele) - v.begin();
            }
        }
        return cnt > (mat.size() * mat[0].size()) / 2;
    }
    int median(vector<vector<int>> &mat) {
        int low = 1, high = 2000;
        while (low < high) {
            int mid = (low + high) / 2;
            if (isValid(mat, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
