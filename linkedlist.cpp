#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

class LinkedList {
    private:
        Node* head = new Node();
        Node* tail = new Node();
    public:
        int size = 0;
        LinkedList() {
            // The head is the tail on instantiation
            head->next = NULL;
        }
    public:
        int get_node_value(int index) {
            // Handle bad request
            if (index+1 > size) {
                throw std::invalid_argument("List index out of range");
            }
            // Retrieve node value at given node index
            int count = 0;
            Node* current = head;
            while (current->next != NULL) {
                if (count == index) {
                    return current->data;
                }
                current = current->next;
                count++;
            }
        }

        bool search(int value) {
            // Look for value in all nodes
            Node* current = head;
            while (current->next != NULL) {
                if (current->data == value) {
                    return true;
                }
                current = current->next;
            }
            // Check if last node contains value
            if (current->data == value) {
                return true;
            }
            return false;
        }
        
        void insert_front(int data) {
            // Create new node
            Node* newNode = new Node();

            // Hook new node up to head node
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            cout << "New head is: " << head->data << endl;
            if (size == 0) {
                tail = newNode;
                tail->next = NULL;
            }
            size++;
        }

        void insert_back(int data) {
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

        void print() {
            Node* current = head;
            while (current->next != NULL) {
                cout << current->data << endl;
                current = current->next;
            }
            // Tail still has a value
            cout << current->data << endl;
        }

        void remove_node_by_value(int value) {
            // Will remove the first node with the given value
            Node* current = head;
            Node* previous = head;
            while (current->next != NULL) {
                if (current->data == value) {
                    break;
                }
                previous = current;
                current = current->next;
            }
            // If the value doesn't exist in the linked list
            if (current->next == NULL){
                return;
            }
            // If the element to be deleted is the head node
            if (current == previous) {
                head = head->next;
                delete previous;
            }
            else {
                previous->next = current->next;
                delete current;
            }
        }
};

int main(void) {
    LinkedList list;

    // Add some nodes to the front of the linked list
    list.insert_front(34);
    list.insert_front(42);
    list.insert_front(100);
    // Print out all elements in linked list
    list.print();
    // Get linked list size
    cout << list.size << endl;
    // Get node value by index
    cout << "Getting node value by index: " << list.get_node_value(2) << endl;
    // Search for existence of value
    cout << "Searching: " << list.search(42) << endl;
    // Remove node by value
    list.remove_node_by_value(42); list.print();
    // Insert node from the back of the linked list
    list.insert_back(22);
    list.print();

    return 0;
}