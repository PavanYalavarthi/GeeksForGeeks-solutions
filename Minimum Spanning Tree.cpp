/*
Problem credits: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

Given a weighted, undirected, and connected graph with V vertices and E edges, 

your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 

The graph is provided as a list of edges, 
where each edge is represented as [u, v, w], indicating an edge between vertex u and vertex v with edge weight w.
*/

class Solution {
  public:
    int prims_algo(vector<vector<pair<int, int>>>& gr) {
        int n = gr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool>isVisited(n, false);
        pq.push({0, 0});
        int ans = 0;
    
        while(!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (isVisited[u]) continue;
            isVisited[u] = true;
            ans += w;
            for(auto& [w, i]: gr[u]) {
                if (!isVisited[i]) {
                    pq.push({w, i});
                }
            }
        }
        return ans;
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> gr(V);
        for(auto& edge: edges) {
            gr[edge[0]].push_back({edge[2], edge[1]});
            gr[edge[1]].push_back({edge[2], edge[0]});
        }
        return prims_algo(gr);
    }
};