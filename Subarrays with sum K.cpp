/*
problem credits: https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1

Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.

*/

/*
Solution:
    store freq of sum, and add to ans mp[sum - k]
*/

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int ele : arr) {
            sum += ele;
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};