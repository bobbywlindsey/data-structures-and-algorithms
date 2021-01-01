// https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/
#include <iostream>

using namespace std;

class DynamicArray {
  private:
    // So that constructor variables can be
    // accessed by methods
    int *m_array;
    int arraySize;
    int current;
  public:
    // Default constructor
    DynamicArray() {
      m_array = new int[1];
      arraySize = 1;
      current = 0;
    }

    int get(int index) {
      if (index < current) {
        return m_array[index];
      }
    }

    void insert(int data, int index) {
      if (index == arraySize) {
        // Then the index is out of memory bounds so double the size
        // of the array and move the data over
        push(data);
      }
      else {
        m_array[index] = data;
      }
    }

    void pop(int index) {
      // This is what deletion really looks like
      // (i.e. program provides no path back to the memory address)
      current--;
    }

    void push(int data) {
      if (current == arraySize) {
        // Double the size of the array
        int *biggerArray = new int[arraySize * 2]; // On heap
        // Copy original data to bigger array
        for (int i = 0; i < arraySize; i++) {
          biggerArray[i] = m_array[i];
        }
        // Delete the original array
        delete[] m_array;

        arraySize *= 2;
        m_array = biggerArray;
      }
      m_array[current] = data;
      current++;
    }

    int search(int data) {
      for (int i = 0; i < current; i++) {
        if (m_array[i] == data) {
          return i;
        }
      }
    }

    void print() {
      for (int i = 0; i < current; i++) {
        cout << m_array[i] << endl;
      }
    }

    int size() {
      return current;
    }
};

int main(void) {

  DynamicArray myArray;
  cout << myArray.get(0) << endl; // 0 or NULL (since it was initialized this way)
  myArray.push(4);
  cout << myArray.get(0) << endl; // 4
  myArray.push(5);
  cout << myArray.get(1) << endl; // 5

  // [4, 5]
  myArray.insert(99, 0); // value, position
  // [99, 5]
  cout << myArray.get(0) << endl; // 99
  myArray.pop(1);
  cout << myArray.get(0) << endl; // 99
  myArray.push(77);
  myArray.push(88);
  myArray.print();

  // Search for value in array
  int index = myArray.search(77);
  // If index == size, then element was not found
  if (index == myArray.size()) {
    cout << "Element not found" << endl;
  }
  else {
    cout << index << endl;
  }

  return 0;
}
