class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        unordered_map<int, int> mp;

        for(int a: arr) mp[a]++;
        
        vector<vector<int>> ans;
        for(auto& [ele, freq]: mp) {
            ans.push_back({ele, freq});
        }
        return ans;
    }
};