/*
Problem credits: https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

You are given a 2D grid image[][], where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate (sr, sc) representing the starting pixel (row and column) and a new color value newColor.

Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

SOlution: Basic flood fill algorithm
*/

class Solution {
  public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int newColor) {
        if (sr == - 1 || sc == -1 || sr == image.size() || sc == image[0].size() || image[sr][sc] != color) {
            return;
        }
        
        image[sr][sc] = newColor;
        dfs(image, sr+1, sc, color, newColor);
        dfs(image, sr, sc+1, color, newColor);
        dfs(image, sr-1, sc, color, newColor);
        dfs(image, sr, sc-1, color, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        if (image[sr][sc] != newColor) {
            dfs(image, sr, sc, image[sr][sc], newColor);
        }
        return image;
    }
};