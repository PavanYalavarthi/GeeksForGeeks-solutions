/*
https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1
*/

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int>mp;
        int ans = 0;
        for(int i = 0; i< arr.size(); i++) {
            if(mp.count(arr[i]) == 0) {
                mp[arr[i]] = i;
            } else {
                ans = max(ans, i - mp[arr[i]]);
            }
            
        }
        return ans;
    }
};