/*
    Problem credits: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. 
    The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. 
    
    Find the number of strongly connected components in the graph.
*/

class Solution {
public:
    void topoDFS(int node, vector<bool>& vis, vector<vector<int>>& gr, stack<int>& st) {
        vis[node] = true;

        for (int v : gr[node]) {
            if (!vis[v]) {
                topoDFS(v, vis, gr, st);
            }
        }

        st.push(node);
    }

    void dfs(int node, vector<bool>& vis, vector<vector<int>>& gr) {
        vis[node] = true;

        for (int v : gr[node]) {
            if (!vis[v]) {
                dfs(v, vis, gr);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>>& edges) {
        vector<vector<int>> gr(V), grr(V);

        for (auto &e : edges) {
            gr[e[0]].push_back(e[1]);
            grr[e[1]].push_back(e[0]);
        }

        stack<int> st;
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoDFS(i, vis, gr, st);
            }
        }

        fill(vis.begin(), vis.end(), false);

        int ans = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                ans++;
                dfs(node, vis, grr);
            }
        }

        return ans;
    }
};