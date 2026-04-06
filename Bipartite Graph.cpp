/*
    Problem credits: https://www.geeksforgeeks.org/problems/bipartite-graph/1

    Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.

    A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

    All edges connect vertices from one set to vertices in the other set.
    No edges exist between vertices within the same set.
*/

class Solution {
  public:
    bool is_bipartite(vector<vector<int>>& gr, vector<int>& color, int node, int par) {
        for(int child: gr[node]) {
            if (child != par) {
                if (color[child] == -1) {
                    color[child] = 1 - color[node];
                    if (!is_bipartite(gr, color, child, node))
                        return false;
                } else if (color[child] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<int>color(V, -1);
        vector<vector<int>> gr(V);
        for(auto& edge: edges) {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        color[0] = 0;
        return is_bipartite(gr, color, 0, -1);
    }
};