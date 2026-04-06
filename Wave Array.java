/*
Problem credits: https://www.geeksforgeeks.org/problems/wave-array-1587115621/1

Given an sorted array arr[] of integers. Sort the array into a wave-like array(In Place). In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5] ..... and so on. If there are multiple solutions, find the lexicographically smallest one.

Note: The given array is sorted in ascending order, and modify the given array in-place without returning a new array.

Solution: Swap adjacent elements
*/

class Solution {
    public void sortInWave(int arr[]) {
        for(int i = 0; i < arr.length - 1; i+=2) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}
