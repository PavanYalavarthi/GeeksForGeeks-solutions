/*
Problem credits: https://www.geeksforgeeks.org/problems/course-schedule-i/1

You are given n courses, labeled from 0 to n - 1 and a 2d array prerequisites[][] where prerequisites[i] = [x, y] 
indicates that we need to take course y first if we want to take course x.

Find if it is possible to complete all tasks. Return true if all tasks can be completed, or false if it is impossible.
*/

class Solution {
  public:
    
    bool is_cycle(vector<vector<int>>& gr, vector<int>& isVisited, int node) {
        isVisited[node] = 1;
        for(int v: gr[node]) {
            if (!isVisited[v]) {
                if (is_cycle(gr, isVisited, v)) {
                    return true;
                }
            } else if (isVisited[v] == 1) {
                return true;
            }
        }
        isVisited[node] = 2;
        return false;
    }
    
    bool isCyclic(vector<vector<int>> &gr) {
        int V = gr.size();
        vector<int>isVisited(V, 0);
        for(int i = 0; i < V; i++) {
            if (!isVisited[i] && is_cycle(gr, isVisited, i)) {
                return true;
            }
        }
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>gr(n);
        for(auto& edge: prerequisites) {
            gr[edge[0]].push_back(edge[1]);
        }
        return !isCyclic(gr);
        
    }
};