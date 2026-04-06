/*
    credits: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

    Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, 
    where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/


class Solution {
public:
    void topo(int node, vector<vector<pair<int,int>>>& graph,
              vector<int>& vis, stack<int>& st) {
        vis[node] = 1;

        for(auto &[child, wt] : graph[node]) {
            if(!vis[child]) {
                topo(child, graph, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(V);

        for(auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) topo(i, graph, vis, st);
        }

        vector<int> dist(V, 1e9);
        dist[0] = 0;

        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(dist[node] != 1e9) {
                for(auto &[child, wt] : graph[node]) {
                    dist[child] = min(dist[child], dist[node] + wt);
                }
            }
        }

        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};