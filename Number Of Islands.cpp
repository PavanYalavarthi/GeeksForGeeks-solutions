/*
    credits: https://www.geeksforgeeks.org/problems/number-of-islands/1

    You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. 
    Matrix elements is 0 if there is water or 1 if there is land. 
    
    Originally, the 2D matrix is all 0 which means there is no land in the matrix. 
    The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can 
    change the cell matrix[A[i][0]][A[i][1]] from sea to island. 
    
    Return how many island are there in the matrix after each operation.You need to return an array of size k.
    
    Note : An island means group of 1s such that they share a common side.
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
        if(size[parX] < size[parY]) swap(parX, parY);
        parent[parY] = parX;
        size[parX] += size[parY];
        return true;
    }
 };

class Solution {
public:
    vector<int> numOfIslands(int m, int n, vector<vector<int>>& operators) {
        int p = operators.size();
        vector<int>ans(p);
        int k = 0, cnt = 0;
        DSU dsu(m * n);
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        for(auto& position: operators) {
            int i = position[0], j = position[1];
            if (!isVisited[i][j]) {
                isVisited[i][j] = true;
                cnt++;
                for(int d = 0; d < 4; d++) {
                    int new_i = i + dir[d], new_j = j + dir[d + 1];
                    if (new_i != -1 && new_i != m && new_j != -1 && new_j != n && isVisited[new_i][new_j] && dsu.unite(new_i * n + new_j, i * n + j)) {
                        cnt--;
                    }
                }
            }
            ans[k++] = cnt;
        }
        return ans;
    }
};