/*
    credits: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

    Implement a Queue using an Array, where the size of the array, n is given.
The Queue must support the following operations:

(i) enqueue(x): Insert an element x at the rear of the queue.
(ii) dequeue(): Remove the element from the front of the queue.
(iii) getFront(): Return front element if not empty, else -1.
(iv) getRear(): Return rear element if not empty, else -1.
(v) isEmpty(): Return true if the queue is empty else return false.
(vi) isFull(): Return true if the queue is full else return false.

There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call enqueue(x)
2: Call dequeue()
3: Call getFront()
4: Call getRear()
5: Call isEmpty()
6: Call isFull()
You just have to implement the functions enqueue, dequeue, getFront, getRear, isEmpty and isFull and the driver code will handle the output.
*/

class myQueue {
    vector<int>v;
    int front, rear, n, size;
  public:
    myQueue(int n) {
        v = vector<int>(n);
        this->n = n;
        front = 0, rear = -1, size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == n;
    }

    void enqueue(int x) {
        if (isFull()) return;
        size++;
        rear = (rear + 1) % n;
        v[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) return;
        size--;
        front = (front + 1) % n;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return v[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return v[rear];
    }
};