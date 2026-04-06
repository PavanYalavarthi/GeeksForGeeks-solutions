/*
Problem credits: https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

You are given n identical eggs and you have access to a k-floored building from 1 to k.

There exists a floor f where 0 <= f <= k such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the egg breaks on a certain floor, it will break on any floor above.
Return the minimum number of moves you need to determine the value of f with certainty.

Solution:

dp[egg][cnt] = dp[egg][cnt-1] + dp[egg-1][cnt-1] + 1
*/

class Solution {

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    static int eggDrop(int n, int k) {
        int[] dp = new int[n+1];
        int cnt = 0;
        while(dp[n] < k) {
            cnt++;
            for(int i = n; i > 0; i--) {
                dp[i] += dp[i-1] + 1;
            }
        }
        return cnt;
    }
}