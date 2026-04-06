/*
    problem credits: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

    You are given a weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
    The graph may contain negative edge weights, but it does not contain any negative weight cycles.

    Your task is to find the shortest distance between every pair of nodes i and j in the graph.

    Note: Modify the distances for every pair in place.
*/

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        int INF = 1e8;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if (dist[j][i] == INF || dist[i][k] == INF) continue;
                    int new_dist = dist[j][i] + dist[i][k];
                    if (dist[j][k] > new_dist) {
                        dist[j][k] = new_dist;
                    }
                }
            }
        }
    }
};