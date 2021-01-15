"""
Merge sort in Python since
I'm too lazy to implement it in C++
"""

# array is passed by reference since it's mutable
def merge_sort(array):
    """Sort your unsorted list with merge sort.

    Args:
        array (int): Array of ints
    """

    if len(array) > 1:
        # Divide
        mid = len(array)//2
        left = array[:mid]
        right = array[mid:]
        # Sort
        merge_sort(left)
        merge_sort(right)
        # Compare and overwrite
        left_index = 0
        right_index = 0
        array_index = 0
        while left_index < len(left) and right_index < len(right):
            if left[left_index] < right[right_index]:
                array[array_index] = left[left_index]
                left_index+=1
            else:
                array[array_index] = right[right_index]
                right_index+=1
            array_index+=1
        # Copy leftovers from left array
        while left_index < len(left):
            array[array_index] = left[left_index]
            left_index+=1
            array_index+=1
        # Copy leftovers from right array
        while right_index < len(right):
            array[array_index] = right[right_index]
            right_index+=1
            array_index+=1
    return None

array_1 = [5, 4, 3, 2, 1]
print(f'Unsorted: {array_1}')
merge_sort(array_1)
print(f'Sorted: {array_1}')
array_2 = [2, 6, 3, 1, 4, 5]
print('\n')
print(f'Unsorted: {array_2}')
merge_sort(array_2)
print(f'Sorted: {array_2}')
