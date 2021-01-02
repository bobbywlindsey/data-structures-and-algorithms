#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

class Queue {
    private:
        Node* head = new Node();
        Node* tail = new Node();
    public:
        int size = 0;
        Queue() {
            // The head is the tail on instantiation
            head->next = NULL;
        }
    public:
        void enqueue(int data) {
            // Create new node
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;

            // Hook new node up to previous node
            tail->next = newNode;
            tail = newNode;
            cout << "New tail is: " << tail->data << endl;
            if (size == 0) {
                head = newNode;
            }
            size++;
        }

        int dequeue() {
            if (head == NULL) {
                throw length_error("No elements to dequeue");
            }
            else {
                int headValue = head->data;
                Node* oldHead = head;
                head = head->next;
                delete oldHead;
                size--;
                return headValue;
            }
        }

        int peek() {
            if (head == NULL) {
                throw length_error("No elements to peek");
            }
            return head->data;
        }

        bool isEmpty() {
            if (size == 0) {
                return true;
            }
            return false;
        }

        void print() {
            Node* current = head;
            while (current->next != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << current->data << endl;
        }
};

int main(void) {
    Queue queue;

    cout << "Queue size: " << queue.size << endl;
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    cout << "Queue size: " << queue.size << endl;
    queue.print();
    cout << "Dequeue-ing: " << queue.dequeue() << endl;
    queue.print();
    cout << "Queue size: " << queue.size << endl;
    cout << "Dequeue-ing: " << queue.dequeue() << endl;
    queue.print();
    cout << "Queue size: " << queue.size << endl;
    cout << "Dequeue-ing two more times..." << endl;
    queue.dequeue();
    queue.dequeue();
    cout << "Is empty?: " << queue.isEmpty() << endl;
    cout << "Peak: " << queue.peek() << endl;
    cout << "Dequeue-ing one more time..." << endl;
    queue.dequeue();
    cout << "Queue size: " << queue.size << endl;
    cout << "Is empty?: " << queue.isEmpty() << endl;
    cout << queue.dequeue() << endl;

    return 0;
}