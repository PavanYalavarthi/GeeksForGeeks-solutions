/*
Problem credits: https://www.geeksforgeeks.org/problems/sum-tree/1

Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
*/

/* A Binary Tree node
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
*/
class Solution {
    boolean isSumTree(Node root) {
        return helper(root) != -1;
    }
    
    int helper(Node root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return root.data;
        int left = helper(root.left);
        if (left == -1) return left;
        int right = helper(root.right);
        if (right == -1 || left + right != root.data) return -1;
        return left+right+root.data;
    }
}