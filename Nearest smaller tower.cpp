/*
    credits: https://www.geeksforgeeks.org/problems/nearest-smaller-tower--170647/1

    Given an array where each element arr[i] represents the height of the tower. Find for each tower, the nearest possible tower that is shorter than it. You can look left or right on both sides.
Note : 

If two smaller towers are at the same distance, pick the smallest tower.

If two towers have the same height then we choose the one with a smaller index.
*/

class Solution {
  public:
    vector<int> getSmaller(vector<int> arr) {
        stack<int> stk;
        
        int n = arr.size();
        
        vector<int>left(n, -1), right(n, -1);
        
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && arr[stk.top()] > arr[i]) {
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        
         for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && arr[stk.top()] > arr[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        vector<int>ans(n);
        for(int i = 0; i < n; i++) {
            if (left[i] != -1 && right[i] != -1) {
                int dl = abs(i - right[i]);
                int dr = abs(left[i] - i);
        
                if (dl < dr) {
                    ans[i] = right[i];
                } 
                else if (dr < dl) {
                    ans[i] = left[i];
                } 
                else {
                    if (arr[right[i]] <= arr[left[i]]) {
                        ans[i] = right[i];
                    } 
                    else {
                        ans[i] = left[i];
                    }
                }
            } 
            else {
                ans[i] = max(left[i], right[i]);
            }
        }
        
        return ans;
        
    }
};