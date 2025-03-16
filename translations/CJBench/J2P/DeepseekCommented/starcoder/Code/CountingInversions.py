import sys

# Function to count the number of inversions in an array
def countInversions(arr):
    return mergeSortAndCount(arr, 0, len(arr) - 1)

# Recursive method to sort the array and count inversions
def mergeSortAndCount(arr, left, right):
    if left >= right:
        return 0 # Base case: no inversions in a single element array
    mid = left + (right - left) / 2
    inversions = 0
    inversions += mergeSortAndCount(arr, left, mid) # Count inversions in the left half
    inversions += mergeSortAndCount(arr, mid + 1, right) # Count inversions in the right half
    inversions += mergeAndCount(arr, left, mid, right) # Count inversions during merge
    return inversions

# Method to merge two halves and count inversions during merge
def mergeAndCount(arr, left, mid, right):
    leftArr = arr[left:mid + 1]
    rightArr = arr[mid + 1:right + 1]
    i = 0
    j = 0
    k = left
    inversions = 0
    while i < len(leftArr) and j < len(rightArr):
        if leftArr[i] <= rightArr[j]:
            arr[k] = leftArr[i] # No inversion, copy from leftArr
            i += 1
        else:
            arr[k] = rightArr[j] # Inversion found, copy from rightArr
            inversions += len(leftArr) - i # Count inversions
            j += 1
        k += 1
    while i < len(leftArr):
        arr[k] = leftArr[i] # Copy remaining elements from leftArr
        i += 1
        k += 1
    while j < len(rightArr):
        arr[k] = rightArr[j] # Copy remaining elements from rightArr
        j += 1
        k += 1
    return inversions

# Main method to read input, compute inversions, and print the result
if __name__ == "__main__":
    n = int(raw_input().strip()) # Read the size of the array
    arr = [int(raw_input().strip()) for _ in xrange(n)]
    result = countInversions(arr) # Compute the number of inversions
    print "Number of inversions: " + str(result) # Print the result

