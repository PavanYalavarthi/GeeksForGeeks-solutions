/*
Problem credits: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom points to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note:
1. ↓ represents the bottom pointer and → represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.

*/

/*
class Node {
    int data;
    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}
*/

class Solution {
    public Node flatten(Node root) {
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(node -> node.data));
        while(root != null) {
            pq.add(root);
            root = root.next;
        }
        
        Node dummy = new Node(-1);
        Node tail = dummy;
        
        while(!pq.isEmpty()) {
            Node mn = pq.remove();
            tail.bottom = mn;
            tail = mn;
            mn = mn.bottom;
            if (mn != null) {
                pq.add(mn);
            }
        }
        return dummy.bottom;
    }
}