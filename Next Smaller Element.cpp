/*
    credits: https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

    You are given an integer array arr[ ]. For every element in the array, your task is to determine its Next Smaller Element (NSE).


The Next Smaller Element (NSE) of an element x is the first element that appears to the right of x in the array and is strictly smaller than x.

If no such element exists, assign -1 as the NSE for that position.

*/

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int>stk;
        vector<int>ans(n);
        for(int i = n -1; i >= 0; i--) {
            while(!stk.empty() && stk.top() >= arr[i]) stk.pop();
            ans[i] = (stk.empty() ? - 1 : stk.top());
            stk.push(arr[i]);
        }
        return ans;
    }
};