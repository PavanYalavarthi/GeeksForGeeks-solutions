/*
    credits: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

    Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

    Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.
*/

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int MAX = 100000;
        vector<bool>isVisited(MAX, false);
        
        if (start == end) return 0;
        
        queue<int>q;
        q.push(start);
        isVisited[start] = true;
        
        for(int level = 1; !q.empty(); level++) {
            int sz = q.size();
            while (sz--) {
                int node = q.front();
                q.pop();
                for(int i: arr) {
                    int val = (node * i) % MAX;
                    if (val == end) return level;
                    if (!isVisited[val]) {
                        isVisited[val] = true;
                        q.push(val);
                    }
                }
            }
            
        }
        return -1;
    }
};
