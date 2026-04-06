/*
Problem credits: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

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
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>isVisited(V, 0);
        vector<vector<int>>gr(V);
        for(auto& edge: edges) {
            gr[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < V; i++) {
            if (!isVisited[i] && is_cycle(gr, isVisited, i)) {
                return true;
            }
        }
        return false;
    }
};