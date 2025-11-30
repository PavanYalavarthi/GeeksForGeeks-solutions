/*
problem credits: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.
*/

/*
Solution:
    store freq of Xor, and add to ans mp[k ^ Xor]
*/


class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        mp[0] = 1;
        int Xor = 0, ans = 0;
        for(int ele: arr) {
            Xor ^= ele;
            ans += mp[k ^ Xor];
            mp[Xor]++;
        }
        return ans;
    }
};