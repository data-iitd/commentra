
import math

def introspective_sort(array, low, high, depth):
    # Continue sorting until the size of the subarray is less than the threshold
    while high - low > INSERTION_SORT_THRESHOLD:
        # If the depth limit is reached, switch to heapsort
        if depth == 0:
            heap_sort(array, low, high)
            return
        # Partition the array and get the pivot index
        pivot_index = partition(array, low, high)
        # Recursively sort the right subarray
        introspective_sort(array, pivot_index + 1, high, depth - 1)
        # Update high to sort the left subarray
        high = pivot_index - 1
    # Use insertion sort for small subarrays
    insertion_sort(array, low, high)

def partition(array, low, high):
    pivot = array[high] # Choose the last element as the pivot
    i = low - 1 # Pointer for the smaller element
    # Rearrange the array based on the pivot
    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            array[i], array[j] = array[j], array[i] # Swap elements to partition the array
    array[i + 1], array[high] = array[high], array[i + 1] # Place the pivot in its correct position
    return i + 1 # Return the pivot index

def insertion_sort(array, low, high):
    # Iterate through the subarray and insert elements in sorted order
    for i in range(low + 1, high + 1):
        key = array[i]
        j = i - 1
        # Move elements that are greater than key to one position ahead
        while j >= low and array[j] > key:
            array[j + 1], array[j] = array[j], array[j + 1]
            j -= 1
        array[j + 1] = key # Insert the key at its correct position

def heap_sort(array, low, high):
    n = high - low + 1 # Calculate the size of the heap
    # Build a max heap
    for i in range((n / 2) - 1, -1, -1):
        heapify(array, i, n, low)
    # Extract elements from the heap one by one
    for i in range(high, low - 1, -1):
        array[low], array[i] = array[i], array[low] # Move the current root to the end
        heapify(array, 0, i - low, low) # Heapify the reduced heap

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
    if largest != i:
        array[low + i], array[low + largest] = array[low + largest], array[low + i]
        heapify(array, largest, n, low) # Recursively heapify the affected sub-tree

def main():
    # Create a scanner object to read input from the user
    scanner = Scanner(System.in)
    
    # Read the number of elements to be sorted
    n = scanner.nextInt()
    array = [None] * n
    
    # Read the elements into the array
    for i in range(n):
        array[i] = scanner.nextInt()
    
    # Perform introspective sort on the array
    introspective_sort(array, 0, n - 1, 2 * int(math.log(n) / math.log(2)))
    
    # Print the sorted array
    for num in array:
        print(num, end=" ")
    
    # Close the scanner to prevent resource leaks
    scanner.close()

if __name__ == "__main__":
    main()

