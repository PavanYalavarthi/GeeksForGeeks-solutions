/*

https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

*/

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        if (b.size() > a.size()) return false;
        unordered_map<int, int>mp;
        for(int ele: a) {
            mp[ele]++;
        }
        for(int ele: b) {
            if(mp[ele] == 0) return false;
            mp[ele]--;
        }
        return true;
        
    }
};