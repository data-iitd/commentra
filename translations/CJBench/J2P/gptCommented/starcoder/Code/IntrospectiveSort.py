import sys

# Threshold for switching to insertion sort
INSERTION_SORT_THRESHOLD = 16

def main():
    # Read the number of elements to be sorted
    n = int(sys.stdin.readline())
    array = []
    
    # Read the elements into the array
    for i in range(n):
        array.append(int(sys.stdin.readline()))
    
    # Perform introspective sort on the array
    introspectiveSort(array, 0, len(array) - 1, 2 * (int)(math.log(len(array)) / math.log(2)))
    
    # Print the sorted array
    for num in array:
        print(num, end=" ")

# Introspective sort that switches between quicksort and heapsort based on depth and size
def introspectiveSort(array, low, high, depth):
    # Continue sorting until the size of the subarray is less than the threshold
    while high - low > INSERTION_SORT_THRESHOLD:
        # If the depth limit is reached, switch to heapsort
        if depth == 0:
            heapSort(array, low, high)
            return
        # Partition the array and get the pivot index
        pivotIndex = partition(array, low, high)
        # Recursively sort the right subarray
        introspectiveSort(array, pivotIndex + 1, high, depth - 1)
        # Update high to sort the left subarray
        high = pivotIndex - 1
    # Use insertion sort for small subarrays
    insertionSort(array, low, high)

# Partition the array around a pivot element
def partition(array, low, high):
    pivot = array[high] # Choose the last element as the pivot
    i = low - 1 # Pointer for the smaller element
    # Rearrange the array based on the pivot
    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            swap(array, i, j) # Swap elements to partition the array
    # Place the pivot in its correct position
    swap(array, i + 1, high)
    return i + 1 # Return the pivot index

# Insertion sort algorithm for sorting a small subarray
def insertionSort(array, low, high):
    # Iterate through the subarray and insert elements in sorted order
    for i in range(low + 1, high + 1):
        key = array[i]
        j = i - 1
        # Move elements that are greater than key to one position ahead
        while j >= low and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key # Insert the key at its correct position

# Heapsort algorithm for sorting a subarray
def heapSort(array, low, high):
    n = high - low + 1 # Calculate the size of the heap
    # Build a max heap
    for i in range((n // 2) - 1, -1, -1):
        heapify(array, i, n, low)
    # Extract elements from the heap one by one
    for i in range(high, low - 1, -1):
        swap(array, low, i) # Move the current root to the end
        heapify(array, 0, i - low, low) # Heapify the reduced heap

# Helper method to maintain the heap property
def heapify(array, i, n, low):
    left = 2 * i + 1 # Left child index
    right = 2 * i + 2 # Right child index
    largest = i # Initialize largest as root
    # Check if left child is larger than root
    if left < n and array[low + left] > array[low + largest]:
        largest = left
    # Check if right child is larger than largest so far
    if right < n and array[low + right] > array[low + largest]:
        largest = right
    # If largest is not root, swap and continue heapifying
    if largest!= i:
        swap(array, low + i, low + largest)
        heapify(array, largest, n, low) # Recursively heapify the affected sub-tree

# Helper method to swap two elements in the array
def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

if __name__ == "__main__":
    main()

# 