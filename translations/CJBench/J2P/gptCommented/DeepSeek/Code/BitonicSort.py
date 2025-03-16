import sys
import math

# Enum to define sorting direction
class Direction(Enum):
    DESCENDING = 1
    ASCENDING = 2

# Method to sort an array using Bitonic Sort
def sort(array):
    # Return the original array if it's empty
    if len(array) == 0:
        return array
    # Calculate the next power of two for padding the array
    padded_size = next_power_of_two(len(array))
    # Create a padded array to accommodate the Bitonic Sort
    padded_array = array + [max(array)] * (padded_size - len(array))
    # Perform Bitonic Sort on the padded array in ascending order
    bitonic_sort(padded_array, 0, len(padded_array), Direction.ASCENDING)
    # Return the sorted array, excluding the padded elements
    return padded_array[:len(array)]

# Recursive method to perform Bitonic Sort
def bitonic_sort(array, low, cnt, direction):
    # Base case: if the count is greater than 1, continue sorting
    if cnt > 1:
        k = cnt // 2
        # Sort the first half in ascending order
        bitonic_sort(array, low, k, Direction.ASCENDING)
        # Sort the second half in descending order
        bitonic_sort(array, low + k, cnt - k, Direction.DESCENDING)
        # Merge the two halves
        bitonic_merge(array, low, cnt, direction)

# Method to merge two sorted halves of the array
def bitonic_merge(array, low, cnt, direction):
    # Base case: if the count is greater than 1, continue merging
    if cnt > 1:
        k = cnt // 2
        # Define a predicate to check if elements are sorted based on the direction
        are_sorted = (lambda a, b: a < b) if direction == Direction.ASCENDING else (lambda a, b: a > b)
        # Compare and swap elements to ensure they are in the correct order
        for i in range(low, low + k):
            if not are_sorted(array[i], array[i + k]):
                array[i], array[i + k] = array[i + k], array[i]
        # Recursively merge the first and second halves
        bitonic_merge(array, low, k, direction)
        bitonic_merge(array, low + k, cnt - k, direction)

# Method to find the next power of two greater than or equal to n
def next_power_of_two(n):
    count = 0
    # If n is already a power of two, return it
    if n & (n - 1) == 0:
        return n
    # Calculate the next power of two
    while n != 0:
        n >>= 1
        count += 1
    return 1 << count

# Method to find the maximum element in an array
def max(array):
    return max(array)

# Method to swap two elements in an array
def swap(array, i, j):
    array[i], array[j] = array[j], array[i]

# Main method to execute the sorting program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    array = list(map(int, data[1:n+1]))
    # Sort the array using Bitonic Sort
    sorted_array = sort(array)
    # Print the sorted array
    print(" ".join(map(str, sorted_array)))
