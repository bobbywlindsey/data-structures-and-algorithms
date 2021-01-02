#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

class Stack {
    private:
        Node* head = new Node();
    public:
        int size = 0;
        Stack() {
            // The head is the tail on instantiation
            head->next = NULL;
        }
    public:
        void push(int data) {
            // Create new node
            Node* newNode = new Node();

            // Hook new node up to head node
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            cout << "New head is: " << head->data << endl;
            size++;
        }

        int pop() {
            if (head->next == NULL) {
                throw length_error("No elements to pop");
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
            cout << endl;
        }

};

int main(void) {
    Stack stack;
    cout << "Stack size: " << stack.size << endl;
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    cout << "Stack size: " << stack.size << endl;
    stack.print();
    cout << "Popping: " << stack.pop() << endl;
    stack.print();
    cout << "Stack size: " << stack.size << endl;
    cout << "Popping: " << stack.pop() << endl;
    stack.print();
    cout << "Stack size: " << stack.size << endl;
    stack.pop();
    stack.pop();
    cout << "Is empty?: " << stack.isEmpty() << endl;
    cout << "Peak: " << stack.peek() << endl;
    stack.pop();
    cout << "Stack size: " << stack.size << endl;
    cout << "Is empty?: " << stack.isEmpty() << endl;
    cout << stack.pop() << endl;

    return 0;
}