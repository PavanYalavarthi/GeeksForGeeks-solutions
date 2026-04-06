/*
Problem credits: https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1

A message containing letters A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are given a string digits. You have to determine the total number of ways that message can be decoded.

*/

// User function Template for Java
class Solution {
    public int countWays(String digits) {
        int n = digits.length();
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return helper(digits, 0, dp);
    }
    
    int helper(String digits, int i, int[] dp) {
        int n = digits.length();
        if (i == n) return 1;
        if (dp[i] != -1) return dp[i];
        int ans = 0;
        int digit = digits.charAt(i) - '0';
        if (digit > 0 && digit <= 9) {
            ans += helper(digits, i+1, dp);
            if (i < n-1) {
                digit = digit * 10 + digits.charAt(i+1) - '0';
                if (digit > 9 && digit < 27) {
                    ans += helper(digits, i + 2, dp);
                }
            }
            
        }
        return dp[i] = ans;
    }
    
}