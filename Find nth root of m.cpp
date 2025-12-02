class Solution {
  public:
    int nthRoot(int n, int m) {
       if (m < 2 || n == 1) return m;
       int l = 1, r = m;
       while(l <= r) {
           int mid = (l + r) / 2;
           int powerN = pow(mid, n);
           if (powerN == m) return mid;
           else if (powerN < m) l = mid + 1;
           else r = mid -1;
       }
       return -1;
    }
};