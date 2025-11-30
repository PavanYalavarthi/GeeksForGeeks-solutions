/*
https://www.geeksforgeeks.org/problems/maximum-value-of-expression2515/1
*/

class Solution {
  public:
    // Function to find the maximum value of the given expression.
    int maxValueOfExpression(vector<int>& arr) {
        int max1, max2, min1, min2;
        max1 = max2 = min1 = min2 = arr[0];
        
        for (int i =0; i< arr.size(); i++) {
            max1 = max(max1, arr[i] - i);
            min1 = min(min1, arr[i] - i);
            max2 = max(max2, arr[i] + i);
            min2 = min(min2, arr[i] + i);
        }
        
        return max(max1 - min1, max2 - min2);
        
    }
};
