#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> elements;

public:
    // Function to check if the queue is empty
    bool isEmpty() {
        return elements.empty();
    }

    // Function to enqueue (insert) an element into the queue
    void enqueue(int value) {
        elements.push_back(value);
        std::cout << "Enqueued: " << value << std::endl;
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        int frontElement = elements.front();
        elements.erase(elements.begin());

        std::cout << "Dequeued: " << frontElement << std::endl;
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        for (int element : elements) {
            std::cout << element << " ";
        }

        std::cout << std::endl;
    }
};

// Driver program
int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    queue.dequeue();
    queue.dequeue();

    queue.display();

    return 0;
}
