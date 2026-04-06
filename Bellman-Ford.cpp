/*
    credits: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

    Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], 
    where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

    Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, 
    its distance should be marked as 10^8. 
    
    Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

*/

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V, 1e8);
        dist[src] = 0;
        int i = 0;
        for( ; i < V; i++) {
            bool isUpdated = false;
            for(auto& edge: edges) {
                int u = edge[0], v= edge[1], w = edge[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w ;
                    isUpdated = true;
                }
            }
            if (!isUpdated) break;
        }
        if (i == V) {
            return {-1};
        }
        return dist;
    }
};
