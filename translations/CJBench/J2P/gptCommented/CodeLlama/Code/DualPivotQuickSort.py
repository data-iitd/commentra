
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
        array[left], array[right] = array[right], array[left]
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
            array[low], array[pivot1End] = array[pivot1End], array[low] # Swap to the left of pivot1
            pivot1End += 1
        # If the current element is greater than or equal to the second pivot
        elif array[low] >= pivot2:
            # Move high pointer to find an element less than pivot2
            while low < high and array[high] >= pivot2:
                high -= 1
            array[low], array[high] = array[high], array[low] # Swap the current element with the high pointer
            high -= 1 # Move high pointer left
            # Check if the swapped element is less than pivot1
            if array[low] < pivot1:
                array[low], array[pivot1End] = array[pivot1End], array[low] # Swap to the left of pivot1
                pivot1End += 1
        low += 1 # Move to the next element

    # Final adjustments to place the pivots in their correct positions
    pivot1End -= 1
    high += 1
    array[left], array[pivot1End] = array[pivot1End], array[left] # Place pivot1 in its final position
    array[right], array[high] = array[high], array[right] # Place pivot2 in its final position

    # Return the indices of the two pivots
    return [pivot1End, high]

# Main method to execute the program
def main():
    n = int(input()) # Read the number of elements
    array = [int(input()) for _ in range(n)] # Read the elements into the array
    # Sort the array using the sort method
    sort(array)
    # Print the sorted array
    for num in array:
        print(num, end=" ")

if __name__ == "__main__":
    main()

