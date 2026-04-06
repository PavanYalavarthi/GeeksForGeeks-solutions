/*
    credits: https://www.geeksforgeeks.org/problems/sum-of-max-of-subarrays/1

    Given an array arr[], the task is to find the sum of the maximum elements of every possible non-empty sub-arrays of the given array arr[].

Note: The answer will always fit into 32 bit integer.
*/

class Solution {
  public:
    int sumOfMax(vector<int> &arr) {
        int n = arr.size();
        stack<int>stk;
        vector<int>left(n), right(n);
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && arr[stk.top()] < arr[i]) stk.pop();
            left[i] = stk.empty() ? i + 1: (i -stk.top());
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && arr[stk.top()] <= arr[i]) stk.pop();
            right[i] = stk.empty() ? n - i : (stk.top() - i);
            stk.push(i);
        }
        long long ans = 0;
        for(int i =0; i < n; i++) {
            ans = ans + arr[i]* left[i] * right[i];
        }
        
        return ans;
        
    }
};