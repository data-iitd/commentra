
# Generic method to sort an array of comparable elements
def sort(array):
    # Check if the array has more than one element to sort
    if len(array) > 1:
        # Call the dual pivot quicksort method to sort the array
        dualPivotQuicksort(array, 0, len(array) - 1)

# Recursive method to perform dual pivot quicksort
def dualPivotQuicksort(array, left, right):
    # Base case: if the left index is less than the right index
    if left < right:
        # Partition the array and get the pivot indices
        pivots = partition(array, left, right)
        # Recursively sort the subarrays around the pivots
        dualPivotQuicksort(array, left, pivots[0] - 1)
        dualPivotQuicksort(array, pivots[0] + 1, pivots[1] - 1)
        dualPivotQuicksort(array, pivots[1] + 1, right)

# Method to partition the array around two pivots
def partition(array, left, right):
    # Ensure the left pivot is less than the right pivot
    if array[left] > array[right]:
        swap(array, left, right)
    # Set the two pivots
    pivot1 = array[left]
    pivot2 = array[right]
    pivot1End = left + 1 # End index for the first pivot
    low = left + 1 # Current index for scanning
    high = right - 1 # High index for scanning

    # Partitioning process
    while low <= high:
        # If the current element is less than the first pivot
        if array[low] < pivot1:
            swap(array, low, pivot1End) # Swap to the left of pivot1
            pivot1End += 1
        # If the current element is greater than or equal to the second pivot
        elif array[low] >= pivot2:
            # Move high pointer to find an element less than pivot2
            while low < high and array[high] > pivot2:
                high -= 1
            swap(array, low, high) # Swap the current element with the high pointer
            high -= 1 # Move high pointer left
            # Check if the swapped element is less than pivot1
            if array[low] < pivot1:
                swap(array, low, pivot1End) # Swap to the left of pivot1
                pivot1End += 1
        low += 1 # Move to the next element

    # Final adjustments to place the pivots in their correct positions
    pivot1End -= 1
    high += 1
    swap(array, left, pivot1End) # Place pivot1 in its final position
    swap(array, right, high) # Place pivot2 in its final position

    # Return the indices of the two pivots
    return [pivot1End, high]

# Method to swap two elements in the array
def swap(array, i, j):
    temp = array[i] # Store the element at index i
    array[i] = array[j] # Move the element at index j to index i
    array[j] = temp # Place the stored element at index j

# Main method to execute the program
if __name__ == '__main__':
    scanner = Scanner(System.in) # Create a scanner for input
    n = scanner.nextInt() # Read the number of elements
    array = [0] * n # Initialize the array
    # Read the elements into the array
    for i in range(n):
        array[i] = scanner.nextInt()
    # Sort the array using the sort method
    sort(array)
    # Print the sorted array
    for num in array:
        print(num, end=" ")
    scanner.close() # Close the scanner

