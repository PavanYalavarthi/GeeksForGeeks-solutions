/*
    Problem credits: https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1

    Given a weighted directed graph with n nodes and m edges. 
    Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
    
    Note: edges[i] is defined as u, v and weight.


    #bellman_ford
*/

class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        vector<int> dist(n, 0);

        for (int i = 0; i < n; i++) {
            bool updated = false;

            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    updated = true;
                }
            }

            if (!updated) return 0;
        }
        return 1;
    }
};