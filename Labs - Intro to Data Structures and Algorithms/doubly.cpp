#include <iostream>
using namespace std;

// Link *temp = new Link(value);


class Node{
    public:
        Node* next;
        Node* prev;
        int value;
        Node(int value){
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        };
};

class DoublyLinkedList{
    public:
        Node* head;
        Node* tail;
        DoublyLinkedList(){
            this->head=nullptr;
            this->tail=nullptr;
        };

        void pushback(int value){
            Node *newNode = new Node(value);

            if(head==nullptr){
                newNode->next = nullptr;
                newNode->prev = nullptr;
                head = newNode;
                tail = newNode;
                return;
            };
            Node *temp = head;
            while(temp->next!= nullptr){
                temp = temp->next;
            };
            // Set the newNode's prev to the temp
            newNode->prev = temp;
            //Set the temps next to the newNode
            temp->next = newNode;
            // Setting the tail to the newNode
            tail = newNode;
        };
        void pushFront(int value){
            Node* newNode = new Node(value);
            Node* temp = head;
            temp->prev = newNode;
            newNode->next = temp;
            head = newNode;
        }

        void popFront(){
            Node* temp = head;
            head = temp->next;
            (temp->next)->prev = nullptr;
            delete temp;
        }

        void popBack(){
            Node* temp = tail;
            tail = temp->prev;
            (temp->prev)->next = nullptr;
            delete temp;
        }

        void reverse(){
            DoublyLinkedList tempList;
            Node* temp = tail;
            while(temp!=nullptr){
                tempList.pushback(temp->value);
                temp = temp->prev;
            }
            while(head!=nullptr){
                Node* temp = head;
                head = temp->next;
                delete temp;
            };
            head = tempList.head;
            tail = tempList.tail;
            tempList.head = nullptr;
            tempList.tail = nullptr;
        }

        int operator[](int index){
            if(index<0){
                cout << "Incorrect Index";
                return 0;
            }
            Node *temp = head;
            for(int i=0; i<index;i++){
                temp->next;
            }
            return temp->value;
        }

        Node* begin(){
            return head;
        }

        Node* end(){
            return tail;
        }
        
        int front(){
            return head->value;
        }

        int back(){
            return tail->value;
        }

        void print(){
            Node *temp = head;
            cout<<"Here is the list using the next:"<<endl;
            while(temp!=nullptr){
                cout << temp->value << endl;
                temp = temp->next;
            };

            cout<<"Here is using prev"<<endl;
            Node *temptail = tail;
            while(temptail!=nullptr){
                cout<< temptail->value << endl;
                temptail = temptail->prev;
            }
            
        };

        ~DoublyLinkedList(){
            while(head!=nullptr){
                Node* temp = head;
                head = temp->next;
                delete temp;
            };
        };
};

int main(){
    DoublyLinkedList d1;
    d1.pushback(42);
    d1.pushback(121);
    d1.pushFront(3);
    d1.print();
    cout << "Here is the value at 1: "<< d1[1] <<endl;
    cout << "Now we pop" <<endl;
    d1.popFront();
    d1.popBack();
    d1.print();
    DoublyLinkedList d2;
    d2.pushback(42);
    d2.pushback(121);
    d2.pushFront(3);
    d2.reverse();
    cout << "Here is the reversed list orginal";
    d2.print();
    return 0;
}