/*
problem credits: https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

Given the root of a binary tree, determine if it is height-balanced or not.

Note: A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.

*/

/*
class Node {
    int data;
    Node left, right;

    Node(int d)
    {
        data = d;
        left = right = null;
    }
}
*/

class Solution {
    public boolean isBalanced(Node root) {
        return height(root) != -1;
    }
    
    int height(Node node) {
        if (node == null) return 0;
        int left = height(node.left);
        if (left == -1) return left;
        int right = height(node.right);
        if (right == -1) return right;
        if (Math.abs(left - right) > 1) return -1;
        return Math.max(left, right) + 1;
    }
}