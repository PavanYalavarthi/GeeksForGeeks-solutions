/*
Problem credits: https://www.geeksforgeeks.org/problems/total-number-of-spanning-trees-in-a-graph/1

Given a connected undirected graph of N vertices and M edges. The task is the find the total number of spanning trees possible in the graph.


Note: A spanning tree is a subset of Graph G, which has all the vertices covered with the minimum possible number of edges. 
Hence, a spanning tree does not have cycles and it cannot be disconnected. 

By this definition, we can draw a conclusion that every connected and undirected Graph G has at least one spanning tree.

Solution: Kirchoffs Law
*/

class Solution {
public:
    long long determinant(vector<vector<double>> mat, int n) {
        double det = 1;

        for (int i = 0; i < n; i++) {
            int pivot = i;

            for (int j = i; j < n; j++) {
                if (abs(mat[j][i]) > 1e-9) {
                    pivot = j;
                    break;
                }
            }

            if (abs(mat[pivot][i]) < 1e-9) return 0;

            if (i != pivot) {
                swap(mat[i], mat[pivot]);
                det *= -1;
            }

            det *= mat[i][i];

            for (int j = i + 1; j < n; j++) {
                double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return llround(det);
    }

    int countSpanningTrees(vector<vector<int>>& graph, int n, int m) {
        vector<vector<int>> lap(n, vector<int>(n, 0));

        for (auto &e : graph) {
            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;
            lap[u][v]--;
            lap[v][u]--;
        }

        vector<vector<double>> minor(n-1, vector<double>(n-1));

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                minor[i-1][j-1] = lap[i][j];
            }
        }

        return determinant(minor, n-1);
    }
};