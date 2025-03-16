import math
import sys

# Enum to define sorting directions
class Direction(Enum):
    DESCENDING = 1
    ASCENDING = 2

# Method to sort an array using bitonic sort algorithm
def sort(array):
    # If the array is empty, return it as is
    if len(array) == 0:
        return array
    
    # Calculate the next power of two for padding the array size
    padded_size = next_power_of_two(len(array))
    
    # Copy the original array and pad it with the maximum value
    padded_array = array + [max(array)] * (padded_size - len(array))
    
    # Perform bitonic sort on the padded array
    bitonic_sort(padded_array, 0, padded_size, Direction.ASCENDING)
    
    # Return the sorted portion of the array
    return padded_array[:len(array)]

# Recursive method to perform bitonic sort
def bitonic_sort(array, low, cnt, direction):
    # Base case: if the count is greater than one, continue sorting
    if cnt > 1:
        k = cnt // 2
        # Sort the first half in ascending order
        bitonic_sort(array, low, k, Direction.ASCENDING)
        # Sort the second half in descending order
        bitonic_sort(array, low + k, cnt - k, Direction.DESCENDING)
        # Merge the two halves
        bitonic_merge(array, low, cnt, direction)

# Method to merge two halves of the array in a bitonic sequence
def bitonic_merge(array, low, cnt, direction):
    # Base case: if the count is greater than one, continue merging
    if cnt > 1:
        k = cnt // 2
        # Define the predicate for comparing elements based on direction
        are_sorted = (lambda a, b: a < b) if direction == Direction.ASCENDING else (lambda a, b: a > b)
        # Compare and swap elements to ensure the correct order
        for i in range(low, low + k):
            if not are_sorted(array[i], array[i + k]):
                array[i], array[i + k] = array[i + k], array[i]
        # Recursively merge the two halves
        bitonic_merge(array, low, k, direction)
        bitonic_merge(array, low + k, cnt - k, direction)

# Method to calculate the smallest power of two greater than or equal to n
def next_power_of_two(n):
    count = 0
    if (n & (n - 1)) == 0:
        return n
    while n != 0:
        n >>= 1
        count += 1
    return 1 << count

# Method to find the maximum element in the array
def max(array):
    return max(array)

# Method to swap two elements in an array
def swap(array, i, j):
    array[i], array[j] = array[j], array[i]

# Main method to read input, sort the array, and print the sorted array
def main():
    n = int(input())
    array = list(map(int, input().split()))
    sorted_array = sort(array)
    print(" ".join(map(str, sorted_array)))

if __name__ == "__main__":
    main()
