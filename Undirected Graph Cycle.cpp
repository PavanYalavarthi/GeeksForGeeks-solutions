/*
Problem credits: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

*/

class Solution {
  public:
    bool is_cycle(vector<vector<int>>& gr, vector<bool>& isVisited, int node) {
        isVisited[node] = true;
        queue<pair<int, int>> q;
        q.push({node, -1});
        while(!q.empty()) {
            auto [node, par] = q.front();
            q.pop();
            for(int child: gr[node]) {
                if (child != par) {
                    if (isVisited[child]) return true;
                    isVisited[child] = true;
                    q.push({child, node});
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool>isVisited(V, false);
        vector<vector<int>>gr(V);
        for(auto& edge: edges) {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < V; i++) {
            if (!isVisited[i] && is_cycle(gr, isVisited, i)) {
                return true;
            }
        }
        return false;
    }
};