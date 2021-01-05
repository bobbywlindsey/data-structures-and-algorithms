#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class BST {
    private:
        struct Node* root;
    public:
        BST() {
            root = NULL;
        }

        Node* insertBSTNode(int data, Node* currentNode) {
            // Base case
            if (currentNode == NULL) {
                Node* newNode = new Node;
                newNode->data = data;
                currentNode = newNode;
            }
            // Recursive cases
            else if (data < currentNode->data) {
                currentNode->left = insertBSTNode(data, currentNode->left);
            }
            else if (data > currentNode->data) {
                currentNode->right = insertBSTNode(data, currentNode->right);
            }
            return currentNode;
        }

        void BSTInsert(int data) {
            root = insertBSTNode(data, root);
        }

        void print() {
            cout << "root data: " << root->data << endl;
            cout << "left subtree: " << root->left->data << endl;
            cout << "right subtree: " << root->right->data << endl;
            cout << "left left subtree: " << root->left->left->data << endl;
        }
};

int main() {
    BST* bst = new BST;
    bst->BSTInsert(5);
    bst->BSTInsert(3);
    bst->BSTInsert(6);
    bst->BSTInsert(1);
    bst->print();
    return 0;
}