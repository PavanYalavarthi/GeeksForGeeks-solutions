/*
Problem credits: https://www.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

Given an array arr[] denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

*/

class Solution {
    int stockBuySell(int arr[]) {
        int ans = 0;
        for(int i = 1; i < arr.length; i++) {
            ans += Math.max(0, arr[i] - arr[i-1]);
        }
        return ans;
    }
}
