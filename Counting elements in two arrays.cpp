class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int m = a.size();
        sort(b.begin(), b.end());
        vector<int>ans(m);
        for(int i = 0; i < m ;i++) {
            ans[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        }
        return ans;
    }
};