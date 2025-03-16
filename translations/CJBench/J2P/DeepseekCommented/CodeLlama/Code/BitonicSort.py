
import math
import sys

# Enum to define sorting directions
class Direction:
    DESCENDING = 0
    ASCENDING = 1

# Method to sort an array using bitonic sort algorithm
def sort(array):
    # If the array is empty, return it as is
    if len(array) == 0:
        return array
    # Calculate the next power of two for padding the array size
    paddedSize = nextPowerOfTwo(len(array))
    # Copy the original array and pad it with the maximum value
    paddedArray = array[:]
    maxValue = max(array)
    paddedArray.extend([maxValue] * (paddedSize - len(array)))
    # Perform bitonic sort on the padded array
    bitonicSort(paddedArray, 0, paddedSize, Direction.ASCENDING)
    # Return the sorted portion of the array
    return paddedArray[:len(array)]

# Recursive method to perform bitonic sort
def bitonicSort(array, low, cnt, direction):
    # Base case: if the count is greater than one, continue sorting
    if cnt > 1:
        k = cnt // 2
        # Sort the first half in ascending order
        bitonicSort(array, low, k, Direction.ASCENDING)
        # Sort the second half in descending order
        bitonicSort(array, low + k, cnt - k, Direction.DESCENDING)
        # Merge the two halves
        bitonicMerge(array, low, cnt, direction)

# Method to merge two halves of the array in a bitonic sequence
def bitonicMerge(array, low, cnt, direction):
    # Base case: if the count is greater than one, continue merging
    if cnt > 1:
        k = cnt // 2
        # Define the predicate for comparing elements based on direction
        areSorted = (direction == Direction.ASCENDING) and (lambda a, b: a < b) or (lambda a, b: a > b)
        # Compare and swap elements to ensure the correct order
        for i in range(low, low + k):
            if not areSorted(array[i], array[i + k]):
                array[i], array[i + k] = array[i + k], array[i]
        # Recursively merge the two halves
        bitonicMerge(array, low, k, direction)
        bitonicMerge(array, low + k, cnt - k, direction)

# Method to calculate the smallest power of two greater than or equal to n
def nextPowerOfTwo(n):
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

# Main method to read input, sort the array, and print the sorted array
def main():
    n = int(input())
    array = list(map(int, input().split()))
    sorter = Main()
    sortedArray = sorter.sort(array)
    for num in sortedArray:
        print(num, end=" ")

if __name__ == "__main__":
    main()

