/*
    credits: https://www.geeksforgeeks.org/problems/min-heap-implementation/1

    Implement a class minHeap that supports the following operations:

push(x) - push element x into the heap
pop() - remove the top element from the heap
peek() - return top element from the heap, if empty return -1
size() - return the no of elements in the heap.
There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : call push(x)
2: call pop()
3: call peek()
4: call size()
The driver code will process the queries, call the corresponding functions, and print the outputs of peek(), size() operation.

You only need to implement the above four functions.
*/

class minHeap {
  private:
    vector<int>heap;
    

  public:

    void push(int x) {
        int idx = size();
        heap.push_back(x);
        while(idx > 0) {
            int parIdx = (idx - 1) / 2;
            if (heap[parIdx] <= heap[idx]) break;
            swap(heap[parIdx], heap[idx]);
            idx = parIdx;
        }
    }

    void pop() {
        if (size() == 0) return;
        swap(heap.front(), heap.back());
        heap.pop_back();
        int n = size();
        int idx = 0;
        while(true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int best = idx;
            if (right < n && heap[best] > heap[right]) best = right;
            if (left < n && heap[best] > heap[left]) best = left;
            
            if (best == idx) break;
            
            swap(heap[best], heap[idx]);
            idx = best;
        }
        
    }

    int peek() {
        return size() ? heap.front(): -1;
    }

    int size() {
        return heap.size();
    }
};