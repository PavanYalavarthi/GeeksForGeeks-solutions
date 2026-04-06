/*
Problem credits: https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

Implement a class SpecialStack that supports following operations:

push(x) - Insert an integer x into the stack.
pop() - Remove the top element from the stack.
peek() - Return the top element from the stack. If the stack is empty, return -1.
getMin() - Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
isEmpty() -  Return true if stack is empty, else false
There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call push(x)
2:  Call pop()
3: Call peek()
4: Call getMin()
5: Call isEmpty()
The driver code will process the queries, call the corresponding functions, and print the outputs of peek(), getMin(), isEmpty() operations.
You only need to implement the above five functions.
*/

class SpecialStack {
    Stack<Integer>stk1, stk2;
    public SpecialStack() {
        // Define Stack
        stk1 = new Stack<>();
        stk2 = new Stack<>();
    }

    public void push(int x) {
        // Add an element to the top of Stack
        stk1.push(x);
        if (stk2.isEmpty() || stk2.peek() >= x) {
            stk2.push(x);
        }
    }

    public void pop() {
        int ele = stk1.pop();
        if (ele == stk2.peek())
            stk2.pop();
    }

    public int peek() {
        // Returns top element of the Stack
        return stk1.isEmpty() ? -1 : stk1.peek();
    }

    boolean isEmpty() {
        // Check if the stack is empty
        return stk1.isEmpty();
    }

    public int getMin() {
        // Finds minimum element of Stack
        return stk2.empty() ? -1 : stk2.peek();
    }
}