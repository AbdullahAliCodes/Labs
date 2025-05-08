#include <iostream>
#include <vector>

class MaxHeap {
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

bool MaxHeap::isEmpty() const {
    return heap.empty();
}

size_t MaxHeap::size() const {
    return heap.size();
}

void MaxHeap::push(int value) {
    heap.push_back(value);
    heapifyUp();
}

void MaxHeap::pop() {
    if (isEmpty()) {
        std::cerr << "Cannot pop from an empty max heap." << std::endl;
        return;
    }

    // Move the last element to the root and heapify down
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown();
}

int MaxHeap::top() const {
    if (isEmpty()) {
        std::cerr << "Max heap is empty." << std::endl;
        return -1; // Assuming -1 represents an invalid value for simplicity
    }
    return heap.front();
}

void MaxHeap::heapifyUp() {
    int index = size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;

        if (heap[index] > heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void MaxHeap::heapifyDown() {
    int index = 0;
    size_t heapSize = size();

    while (true) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int largestChildIndex = index;

        if (leftChildIndex < heapSize && heap[leftChildIndex] > heap[largestChildIndex]) {
            largestChildIndex = leftChildIndex;
        }

        if (rightChildIndex < heapSize && heap[rightChildIndex] > heap[largestChildIndex]) {
            largestChildIndex = rightChildIndex;
        }

        if (index != largestChildIndex) {
            std::swap(heap[index], heap[largestChildIndex]);
            index = largestChildIndex;
        } else {
            break;
        }
    }
}

// Driver program
int main() {
    MaxHeap maxHeap;

    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(20);

    std::cout << "Top element: " << maxHeap.top() << std::endl;

    maxHeap.pop();

    std::cout << "Top element after pop: " << maxHeap.top() << std::endl;

    std::cout << "Is the max heap empty? " << (maxHeap.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
