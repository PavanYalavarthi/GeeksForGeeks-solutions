/*
Problem credits: https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1

Given a weighted, undirected, and connected graph with V vertices and E edges, 

the task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph using Kruskal's Algorithm. 

The graph is represented as an edge list edges[][], where edges[i] = [u, v, w] denotes an undirected edge between u and v with weight w.

*/

// User function Template for C++
struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int parX = find(x), parY = find(y);
        if(parX == parY) return false;
        if(size[parX] < size[parY]) {
            parent[parX] = parY;
        } else {
            parent[parY] = parX;
            if (size[parX] == size[parY]) size[parX]++;
        }
        return true;
    }
 };
 
 class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](vector<int>&a, vector<int>&b) { return a[2] < b[2];});
        DSU dsu(V);
        int ans = 0;
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dsu.unite(u, v)) {
                ans += w;
            }
        }
        return ans;
    }
};