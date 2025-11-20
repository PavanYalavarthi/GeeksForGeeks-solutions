/*
    Problem credits: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
    
    Paritions <= k with max_sum is monotonic function. SO applying binary search on it
*/
class Solution {
  public:
    int noOfPartitions(vector<int>& arr, int max_sum) {
        int sum = 0, count = 1;
        for(int i=0; i< arr.size(); i++) {
            sum += arr[i];
            if(sum > max_sum) {
                count++;
                sum = arr[i];
            }
        }
        return count;
    }
    int minTime(vector<int>& arr, int k) {
        int start = 0, end = 0, ans;
        for(int i = 0; i< arr.size();i++) {
            start = max(start, arr[i]);
            end += arr[i];
        }
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (noOfPartitions(arr, mid) <= k) {
                ans = mid;
                end = mid -1;
            } else {
                start = mid +1;
            }
        }
        return ans;
    }
};