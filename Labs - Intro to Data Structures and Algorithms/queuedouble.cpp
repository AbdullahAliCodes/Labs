#include <iostream>

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

// Queue class using doubly linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue (insert) an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << "Enqueued: " << value << std::endl;
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr; // Queue is now empty
        }

        std::cout << "Dequeued: " << temp->data << std::endl;

        delete temp;
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
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
