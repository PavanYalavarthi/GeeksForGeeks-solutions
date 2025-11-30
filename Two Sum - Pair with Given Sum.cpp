class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
       unordered_set<int>s;
       for(int a: arr) {
           if (s.count(target - a))
                return true;
            s.insert(a);
       }
       return false;
    }
};