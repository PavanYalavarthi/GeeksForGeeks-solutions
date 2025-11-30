/*
Problem credits: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

*/
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> mp;
        long long sum = 0;
        int ans = 0;
        mp[0] = -1;
        for(int i = 0; i< arr.size(); i++)  {
            sum += arr[i];
            if (mp.count(sum - k)) {
                ans = max(ans, i - mp[sum - k]);
            } else {
                mp[sum] = i;
            }
         }
         return ans;
            
    }
};