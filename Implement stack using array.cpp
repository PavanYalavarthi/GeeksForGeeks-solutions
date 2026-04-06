/*
    credits: https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

    Implement a Stack using an Array, where the size of the array, n is given.
The Stack must support the following operations:

(i) push(x): Insert an element x at the top of the stack.
(ii) pop(): Remove the element from the top of the stack.
(iii) peek(): Return the top element if not empty, else -1.
(iv) isEmpty(): Return true if the stack is empty else return false.
(v) isFull(): Return true if the stack is full else return false.

There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call push(x)

2 : Call pop()

3 : Call peek()

4  : Call isEmpty()

5 : Call isFull()

You just have to implement the functions push, pop, peek, isEmpty, and isFull. The driver code will handle the output.
*/

class myStack {
    vector<int>v;
    int size =0;
  public:
    myStack(int n) {
        v = vector<int>(n);
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == v.size();
    }

    void push(int x) {
        if (!isFull()) {
            v[size++] = x;
        }
    }

    void pop() {
        if(!isEmpty()) {
            size--;
        }
    }

    int peek() {
        if (isEmpty()) return -1;
        return v[size-1];
    }
};