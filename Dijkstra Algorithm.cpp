/*
Problem credits: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
It is guaranteed that all the shortest distance will fit in a 32-bit integer.

*/

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<int>dist(V, 1e9);
        vector<vector<pair<int, int>>> gr(V);
        for(auto& v: edges) {
            gr[v[0]].push_back({v[2], v[1]});
            gr[v[1]].push_back({v[2], v[0]});
        }
        
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();
            if (w > dist[node]) continue;
            for(auto& [weight, child]: gr[node]) {
                if (dist[child] > dist[node] + weight) {
                    dist[child] = dist[node] + weight;
                    pq.push({dist[child], child});
                }
            }
        }
        return dist;
    }
};