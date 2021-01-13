#include <iostream>

using namespace std;

// Selection sort - O(N^2)
template<typename T, size_t N>
void selection_sort(T (&array)[N]) {
    for (int i = 0; i < N-1; i++) {
        int min_index = i;
        for (int j = i+1; j < N; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        // Swap (even if there was lower min value found)
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }

}

// Print array; pass by reference
template<typename T, size_t N>
void log(T (&array)[N]) {
    for (int i=0; i < N; i++) {
        cout << array[i] << endl;
    }
}

int main() {
    int array[5] = {5, 4, 3, 2, 1};
    selection_sort(array);
    log(array);
    return 0;
}