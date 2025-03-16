
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
    padded_size = 1 << math.ceil(math.log2(len(array)))
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
        are_sorted = (direction == Direction.ASCENDING)
        def compare(a, b):
            return a < b if are_sorted else a > b
        # Compare and swap elements to ensure the correct order
        for i in range(low, low + k):
            if not compare(array[i], array[i + k]):
                array[i], array[i + k] = array[i + k], array[i]
        # Recursively merge the two halves
        bitonic_merge(array, low, k, direction)
        bitonic_merge(array, low + k, cnt - k, direction)

# Main method to read input, sort the array, and print the sorted array
def main():
    n = int(input())
    array = [int(x) for x in input().split()]
    sorted_array = sort(array)
    print(" ".join(map(str, sorted_array)))

if __name__ == "__main__":
    main()

