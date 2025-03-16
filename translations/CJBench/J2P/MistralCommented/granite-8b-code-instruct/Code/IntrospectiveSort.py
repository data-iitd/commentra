

import sys

def main():
    n = int(input()) # Read the number of elements in the array from the console

    array = [int(x) for x in input().split()] # Read the elements of the array from the console and convert them to integers

    introspectiveSort(array, 0, len(array) - 1, 2 * (int(math.log(len(array), 2)))) # Call the introspectiveSort method to sort the array

    print(" ".join(map(str, array))) # Print the sorted array

def introspectiveSort(array, low, high, depth):
    # Base case: if the depth is 0, use heap sort instead of introspective sort
    if depth == 0:
        heapSort(array, low, high)
        return

    # Find the pivot index using partition method and recursively sort the right side of the pivot
    pivotIndex = partition(array, low, high)
    introspectiveSort(array, pivotIndex + 1, high, depth - 1)
    high = pivotIndex - 1 # Update the high index to the last index of the left side of the pivot

def partition(array, low, high):
    # Choose the last element as the pivot
    pivot = array[high]

    i = low - 1 # Initialize i to the index of the last element in the left side of the pivot

    for j in range(low, high): # Iterate through the array to find the position of the pivot element
        if array[j] <= pivot: # If the current element is smaller than or equal to the pivot
            i += 1 # Increment i to move to the next position in the left side of the pivot
            array[i], array[j] = array[j], array[i] # Swap the current element with the element at position i

    array[i + 1], array[high] = array[high], array[i + 1] # Swap the pivot element with the element at position i+1 (the correct position for the pivot)

    return i + 1 # Return the index of the pivot

def insertionSort(array, low, high):
    # Iterate through the array to sort it using insertion sort algorithm
    for i in range(low + 1, high + 1):
        key = array[i]
        j = i - 1
        while j >= low and array[j] > key: # Find the position for the key element
            array[j + 1] = array[j] # Swap the current element with the next element
            j -= 1
        array[j + 1] = key # Insert the key element at its correct position

def heapSort(array, low, high):
    # Base case: if the size of the sub-array is 1 or less, the array is already sorted
    if high - low + 1 <= 0:
        return

    # Heapify the root node of the sub-array
    heapify(array, 0, high - low + 1, low)

    # Swap the root node with the last node, and recursively heapify the sub-array of size n-1
    array[low], array[high] = array[high], array[low]
    heapify(array, 0, high - low, low)

def heapify(array, i, n, low):
    # Find the index of the left and right child nodes of the current node
    left = 2 * i + 1
    right = 2 * i + 2

    # Find the index of the largest node among the current node, its left child, and its right child
    largest = i
    if left < n and array[low + left] > array[low + largest]:
        largest = left
    if right < n and array[low + right] > array[low + largest]:
        largest = right

    # If the current node is not at its correct position, swap it with its correct position and recursively heapify the sub-tree rooted at the new position
    if largest!= i:
        array[low + i], array[low + largest] = array[low + largest], array[low + i]
        heapify(array, largest, n, low)

if __name__ == "__main__":
    main()

