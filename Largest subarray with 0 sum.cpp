/*
Problem credits:  https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

*/

/*
Solution: store first oocurance of sum and check for biggest difference
*/

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        for(int i = 0, sum = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (mp.count(sum)) {
                ans = max(ans, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};