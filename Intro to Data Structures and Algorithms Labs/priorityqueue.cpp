#include <iostream>
#include <vector>

class PriorityQueue {
private:
    std::vector<int> heap;

    // Helper functions for heap operations
    void heapifyUp();
    void heapifyDown();

public:
    bool isEmpty() const;
    size_t size() const;
    void push(int value);
    void pop();
    int top() const;
};

bool PriorityQueue::isEmpty() const {
    return heap.empty();
}

size_t PriorityQueue::size() const {
    return heap.size();
}

void PriorityQueue::push(int value) {
    heap.push_back(value);
    heapifyUp();
}

void PriorityQueue::pop() {
    if (isEmpty()) {
        std::cerr << "Cannot pop from an empty priority queue." << std::endl;
        return;
    }

    // Move the last element to the root and heapify down
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown();
}

int PriorityQueue::top() const {
    if (isEmpty()) {
        std::cerr << "Priority queue is empty." << std::endl;
        return -1; // Assuming -1 represents an invalid value for simplicity
    }
    return heap.front();
}

void PriorityQueue::heapifyUp() {
    int index = size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;

        if (heap[index] < heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapifyDown() {
    int index = 0;
    size_t heapSize = size();

    while (true) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int smallestChildIndex = index;

        if (leftChildIndex < heapSize && heap[leftChildIndex] < heap[smallestChildIndex]) {
            smallestChildIndex = leftChildIndex;
        }

        if (rightChildIndex < heapSize && heap[rightChildIndex] < heap[smallestChildIndex]) {
            smallestChildIndex = rightChildIndex;
        }

        if (index != smallestChildIndex) {
            std::swap(heap[index], heap[smallestChildIndex]);
            index = smallestChildIndex;
        } else {
            break;
        }
    }
}

// Driver program
int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(20);

    std::cout << "Top element: " << pq.top() << std::endl;

    pq.pop();

    std::cout << "Top element after pop: " << pq.top() << std::endl;

    std::cout << "Is the priority queue empty? " << (pq.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
