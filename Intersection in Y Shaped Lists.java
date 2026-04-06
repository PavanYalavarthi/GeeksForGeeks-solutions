/*
Problem credits: https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

You are given the heads of two non-empty singly linked lists, head1 and head2, that intersect at a certain point. Return that Node where these two linked lists intersect.

Note: It is guaranteed that the intersected node always exists.
*/

/*
class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}
*/

class Solution {
    int length(Node node) {
        int cnt = 0;
        while(node != null){
            cnt++;
            node = node.next;
        } 
        return cnt;
    }
    public Node intersectPoint(Node head1, Node head2) {
        int cnt1 = length(head1), cnt2 = length(head2);
        if (cnt1 < cnt2) {
            Node temp = head1;
            head1 = head2;
            head2 = temp;
        }
        for(int i = 0; i < Math.abs(cnt1 - cnt2); i++) {
            head1 = head1.next;
        }
        for(;head1 != null; head1 = head1.next) {
            if (head1 == head2) return head1;
            head2 = head2.next;
        }
        return null;
    }
}