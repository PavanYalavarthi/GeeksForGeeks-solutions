/*
problem credits: https://www.geeksforgeeks.org/problems/queue-using-stack/1

Implement a Queue using stacks. You are allowed to use only stack data structures to implement the queue.
The Queue must support the following operations:

(i) enqueue(x): Insert an element x at the rear of the queue.
(ii) dequeue(): Remove the element from the front of the queue.
(iii) front(): Return the front element if the queue is not empty, else return -1.
(iv) size(): Return the number of elements currently in the queue.

There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call enqueue(x)
2: Call dequeue()
3: Call front()
4: Call size()
You just have to implement the functions enqueue, dequeue, front and size. The driver code will handle the input and output.

*/

class myQueue {

    // Initialize your data members
    Stack<Integer> input = new Stack<>();
    Stack<Integer> output = new Stack<>();

    void enqueue(int x) {
        input.add(x);
    }
    
    void shift() {
        if (output.isEmpty()) {
            while (!input.isEmpty()) {
                output.push(input.pop());
            }
        }
    }
    
    void dequeue() {
        shift();
        output.pop();
    }

    int front() {
        shift();
        return (output.isEmpty()? -1: output.peek());
    }

    int size() {
        return input.size() + output.size();
    }
}
