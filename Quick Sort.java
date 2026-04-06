/*
Problem credits: https://www.geeksforgeeks.org/problems/quick-sort/1

Implement Quick Sort, a Divide and Conquer algorithm, to sort an array, arr[] in ascending order.
Given an array arr[], with starting index low and ending index high, complete the functions partition() and quickSort().
Use the last element as the pivot, so that all elements less than or equal to the pivot come before it, and elements greater than the pivot follow it.

*/

class Solution {
    public void quickSort(int[] arr, int low, int high) {
        // code here
        if (low >= high) return;
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot);
        quickSort(arr, pivot+1, high);
    }

    private int partition(int[] arr, int low, int high) {
       int pivot = arr[low];
       int left = low - 1, right = high + 1;
       while(true) {
            do {
               left++;
            } while(arr[left] < pivot);
       
            do {
               right--;
            } while(arr[right] > pivot);
       
            if (left >= right) return right;
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
       }
       
    }
}