/*
    credits: https://www.geeksforgeeks.org/problems/minimum-edges/1

    Given a directed graph with N nodes and M edges. A source node and a destination node are also given, we need to find how many edges we need to reverse in order to make at least 1 path from the source node to the destination node.
    Note: In case there is no way then return -1.

    Solution: Basic BFS with weights of 0 or 1.
*/

class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pair<int,int>>> gr(n);

        for(auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            gr[u].push_back({v, 0});
            gr[v].push_back({u, 1});
        }

        deque<int> dq;
        vector<int> dist(n, 1e9);

        src--, dst--;

        dist[src] = 0;
        dq.push_front(src);

        while(!dq.empty()) {
            int node = dq.front();
            dq.pop_front();

            for(auto &[child, wt] : gr[node]) {
                if(dist[child] > dist[node] + wt) {
                    dist[child] = dist[node] + wt;

                    if(wt == 0)
                        dq.push_front(child);
                    else
                        dq.push_back(child);
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};