class Solution {
  public:
    bool isValid(vector<int> &arr, int mid, int k) {
        int sum = 0, cnt = 1;
        for(int i: arr) {
            sum += i;
            if (sum > mid) {
                cnt++;
                if (cnt > k) return false;
                sum = i;
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0), ans= -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(arr, mid, k)) {
                ans =mid;
                high = mid - 1;
            } else {
                low = mid +1;
            }
        }
        return ans;
    }
};