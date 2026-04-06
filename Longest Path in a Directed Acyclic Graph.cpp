/*
Problem credits: https://www.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1

Given a Weighted Directed Acyclic Graph (DAG) with n vertices numbered from 0 to n-1 and m edges, represented by 2d array edges[][], 
where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight. 

You are also given a source vertex s. Find the longest distances from s to all other vertices in the given graph. 
Return the distance array, in the distance array instead of passing INF you need to have INT_MIN driver will automatically update it to INF.
*/

class Solution {
    protected:
    const int inf= INT_MIN;
    private:
    void topo(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]){
        vis[node]=1;
        for(auto i: adj[node]){
            
            if(!vis[i.first]){
                topo(i.first, vis, st, adj);
            }
        }
        st.push(node);
    }
  public:
    vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src) {
        vector<int> vis(v, 0);
        vector<pair<int, int>> adj[v];
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            int wt= i[2];
            adj[u].push_back({v, wt});
        }
        stack<int> st;
        for(int i=0; i<v; i++){
            if(!vis[i]){
                topo(i, vis, st, adj);
            }
        }  
        vector<int> dist(v, inf);
        dist[src]= 0;
        while(!st.empty()){
            int u= st.top();
            st.pop();
            if (dist[u] == inf) continue;
            for(auto& [v, wt]: adj[u]) {
                if (dist[u] + wt > dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        return dist;
    }
};