
/*
Problem credits: https://www.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition0618/1
*/

class Solution {

  public:
    int minSteps(int N) {
       vector<int>dp(N+1);
       dp[1] = 0;
       for(int i = 2; i <= N; i++) {
           int ans = dp[i-1];
           if (i % 2 == 0) ans = min(ans, dp[i / 2]);
           if (i % 3 == 0) ans = min(ans, dp[i / 3]);
           dp[i] = ans + 1;
       }
       return dp[N];
    }
};
