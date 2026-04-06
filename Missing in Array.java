/*
Problem credits: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

*/

class Solution {
    int missingNum(int arr[]) {
        // code here
        int ans = 0;
        for(int i = 0; i < arr.length; i++) {
            ans ^= (i+1) ^ arr[i];
        }
    
        return ans ^ (arr.length + 1);
    }
}