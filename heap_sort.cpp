#include <iostream>

using namespace std;

template<typename T, size_t N>
void print(T (&array)[N]) {
    if (N == 0) {
        cout << "No elements." << endl;
    }
    else {
        cout << "Array elements: " << endl;
        for (int i=0; i < N; i++) {
            cout << array[i] << endl;
        }
    }
}

int find_left_node(int starting_index) {
    return 2 * starting_index + 1;
}

template<typename T, size_t N>
void fix_down(T (&array)[N], int array_size, int starting_index) {
    int largest = starting_index;
    int left_node_index = find_left_node(starting_index);

    // If left child is larger than parent
    if (array[left_node_index] > array[largest] && left_node_index < array_size) {
        largest = left_node_index;
    }

    // If right child is larger than parent
    if (array[left_node_index+1] > array[largest] && left_node_index+1 < array_size) {
        largest = left_node_index+1;
    }

    if (largest != starting_index) {
        swap(array[starting_index], array[largest]);
        fix_down(array, array_size, largest);
    }
}

int find_parent_node(int starting_index) {
    return (starting_index - 1) / 2;
}

template<typename T, size_t N>
void heap_sort(T (&array)[N], int array_size) {
    // Heapify
    int parent_index = find_parent_node(array_size-1);
    for (int i = parent_index; i >=0; --i) {
        fix_down(array, array_size, i);
    }

    // Swap first and last elements
    while (array_size > 1) {
        swap(array[0], array[array_size-1]);

        // Call fix_down but exclude last element
        array_size--;
        fix_down(array, array_size, 0);
    }
}

int main() {
    int array[9] = {18, 2, 25, 4, 30, 15, 19, 5, 6};
    heap_sort(array, 9);
    print(array); 
    return 0;
}