#include <iostream>

using namespace std;

// Print array; pass by reference
template<typename T, size_t N>
void log(T (&array)[N]) {
    for (int i=0; i < N; i++) {
        cout << array[i] << endl;
    }
}

template<typename T, size_t N>
void swap(T (&array)[N], int i, int j) {
    int j_value = array[j];
    array[j] = array[i];
    array[i] = j_value;
}

template<typename T, size_t N>
int quick_sort_range(T (&array)[N], int first, int last) {
    // Base case
    if (last <= first) {
        return 0;
    }

    // Recursive case
    // Choose pivot (going to naively choose
    // the first element each time)
    int pivot = array[first];

    // Start at the back of the array
    int position = last;

    // Work your way backward through the array
    // each time comparing the position value to
    // the pivot value.
    for (int i = last; i > first; i--) {
        // If value at i is greater than pivot value,
        // put it in the back of the array by swapping
        // with position value.
        if (array[i] > pivot) {
            swap(array, position, i);
            position--;
        }
    }
    swap(array, first, position);

    quick_sort_range(array, first, position-1);
    quick_sort_range(array, position+1, last);
    return 0;
}

template<typename T, size_t N>
void quick_sort(T (&array)[N]) {
    quick_sort_range(array, 0, N-1);
}

int main() {
    int array[5] = {5, 4, 3, 2, 1};
    quick_sort(array);
    log(array);
    return 0;
}
