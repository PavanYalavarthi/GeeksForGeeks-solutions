/*
https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int, int> mp;
        long long ans = 0;
        for(int a: arr) {
            ans += mp[target - a];
            mp[a]++;
        }
        return ans;
    }
};