/*
Problem credits: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.

Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.
*/

class Solution {
    int majorityElement(int arr[]) {
        int ans = arr[0], cnt = 0;
        for(int i: arr) {
            if (ans == i) {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    ans = i;
                    cnt = 1;
                }
            }
        }
        cnt = 0;
        for(int i: arr) {
            if (i == ans) {
                cnt++;
            }
        }
        
        return (cnt > arr.length / 2 ? ans : -1);
    }
}