#include <iostream>

using namespace std;

int binary_search_while_loop(int (&array)[10], int x, int array_length) {
    // Return index of value or -1
    int left_index = 0;
    int right_index = array_length-1;
    while (left_index <= right_index) {
        int middle = left_index + (right_index - 1) / 2;
        if (array[middle] == x) {
            return middle;
        }
        else if (x > array[middle]) {
            left_index = middle + 1;
        }
        else if (x < array[middle]) {
            right_index = middle - 1;
        }
    }
    return -1;
}

int binary_search_recursive(int (&array)[10], int x, int left_index, int right_index) {
    if (left_index <= right_index) {
        int middle = left_index + (right_index - 1) / 2;
        if (array[middle] == x) {
            return middle;
        }
        else if (x > array[middle]) {
            return binary_search_recursive(array, x, middle+1, right_index);
        }
        else if (x < array[middle]) {
            return binary_search_recursive(array, x, left_index, middle-1);
        }
    }
    return -1;
}

int main() {
    int my_array[10] = {2, 16, 28, 33, 40, 55, 68, 79, 89, 100}; 
    int search_result = binary_search_while_loop(my_array, 100, 10);
    cout << "Binary search with while loop: " << search_result << endl;
    int recursive_search_result = binary_search_recursive(my_array, 100, 0, 9);
    cout << "Binary search with recursion: " << recursive_search_result << endl;
    return 0;
}
