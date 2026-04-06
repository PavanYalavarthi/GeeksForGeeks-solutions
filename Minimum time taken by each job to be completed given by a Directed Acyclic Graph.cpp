/*
Problem credits: https://www.geeksforgeeks.org/problems/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/1

Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V 
such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by job to be completed 
where each Job takes unit time to get completed.

*/

// User function Template for C++

class Solution {
  public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
        vector<vector<int>> gr(n);
        vector<int>inDegree(n, 0);
        for(auto& edge: edges) {
            gr[edge[0]-1].push_back(edge[1]-1);
            inDegree[edge[1]-1]++;
        }
        
        vector<int>res(n);
        queue<int>q;
        for(int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                res[i] = 1;
            }
        }
        int k = 0;
        while(!q.empty()) {
            int u  = q.front();
            q.pop();
            for(int v: gr[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    res[v] = res[u] + 1;
                    q.push(v);
                }
            }
        }
        return res;
        
    }
};