/*
Problem credits: https://www.geeksforgeeks.org/problems/topological-sort/1

Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.
*/

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> gr(V);
        vector<int>inDegree(V, 0);
        for(auto& edge: edges) {
            gr[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
        queue<int>q;
        for(int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int>res(V);
        int k = 0;
        while(!q.empty()) {
            int u  = q.front();
            res[k++] = u;
            q.pop();
            for(int v: gr[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return res;
    }
};