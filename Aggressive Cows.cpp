class Solution {
  public:
    bool isValid(vector<int> &stalls, int mid, int k) {
        int prev = stalls.front(), cnt = 1;
        for(int ele: stalls) {
            if (ele - prev >= mid) {
                cnt++;
                if (cnt == k) return true;
                prev = ele;
            }
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls.back() - stalls[0], ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(stalls, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};