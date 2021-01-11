#include <iostream>
#include <vector>

using namespace std;

// Max priority queue implementation using max heap

struct Heap {
    // Using a vector since it's equivalent to a dynamic array
    vector<int> heap;
    int array_size;

    // Default constructor
    Heap() {
        array_size = 0;
    }

    // Swap two elements in the vector/heap
    void swap(int i, int j) {
        int j_value = heap[j];
        heap[j] = heap.at(i);
        heap[i] = j_value;
    }

    void fix_up() {
        // Move the last array element/node in tree up the heap to
        // the right spot
        int last_index = array_size - 1;
        int parent_index = find_parent_node(last_index);
        // While array element index is positive and the parent node value is less
        // than the child value
        while (parent_index >= 0 && heap.at(parent_index) < heap.at(last_index)) {
            // Swap child and parent
            swap(last_index, parent_index);
            // Child is now parent
            last_index = parent_index;
            // Find new parent
            parent_index = find_parent_node(parent_index);
        }
    }

    void fix_down() {
        // Start at root node/first element in the vector/heap
        int index = 0;
        while (index < array_size-1) {
            int left_node_index = find_left_node(index);
            // If left node value is less than right node value and right node exists
            if (heap.at(index) < heap.at(left_node_index+1) && left_node_index+1 < array_size-1) {
                // Swap first element/root node with the right node
                swap(index, left_node_index+1);
                index = left_node_index+1;
            }
            // If node greater than or equal to its children nodes
            else if (heap.at(index) >= heap.at(left_node_index+1)) {
                // Done fixing
                break;
            }
            else {
                // Swap element at index with the left node
                swap(index, left_node_index);
                index = left_node_index+1;
            }
        }
    }

    void insert(int priority) {
        array_size++;
        heap.push_back(priority);
        fix_up();
    }

    int delete_max() {
        // Swap first and last element
        swap(0, array_size-1);
        array_size--;
        // Move the first element to its proper place
        fix_down();
        return heap.at(array_size);

    }

    int find_left_node(int starting_index) {
        return 2 * starting_index + 1;
    }

    int find_right_node(int starting_index) {
        return find_left_node(starting_index) + 1;
    }

    int find_parent_node(int starting_index) {
        return (starting_index - 1) / 2;
    }

    void print() {
        if (array_size == 0) {
            cout << "No elements." << endl;
        }
        else {
            cout << "Array elements: " << endl;
            for (int i=0; i < array_size; i++) {
                cout << heap.at(i) << endl;
            }
        }
    }

    void log() {
        cout << "Heap size: " << array_size << endl;
        print();
    }
};

int main() {
    Heap heap;
    heap.insert(30);
    heap.insert(19);
    heap.insert(25);
    heap.insert(18);
    heap.insert(15);
    heap.insert(2);
    heap.insert(4);
    heap.insert(5);
    heap.insert(21);
    heap.log();
    return 0;
}