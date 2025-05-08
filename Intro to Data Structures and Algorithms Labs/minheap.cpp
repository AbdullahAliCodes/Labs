#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    // Helper function to maintain heap property after an insertion
    void heapifyUp(int index) {
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

    // Helper function to maintain heap property after a deletion
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Constructor
    MinHeap() {}

    // Insert an element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Remove the minimum element from the heap
    int extractMin() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        int minValue = heap[0];
        std::swap(heap[0], heap.back());
        heap.pop_back();
        heapifyDown(0);

        return minValue;
    }

    // Get the minimum element without removing it
    int getMin() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        return heap[0];
    }

    // Check if the heap is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Get the size of the heap
    size_t size() const {
        return heap.size();
    }
};

int main() {
    MinHeap minHeap;

    // Insert elements into the min-heap
    minHeap.insert(4);
    minHeap.insert(2);
    minHeap.insert(8);
    minHeap.insert(5);
    minHeap.insert(1);

    // Extract and print the minimum element until the heap is empty
    while (!minHeap.isEmpty()) {
        std::cout << "Min Element: " << minHeap.extractMin() << std::endl;
    }

    return 0;
}
