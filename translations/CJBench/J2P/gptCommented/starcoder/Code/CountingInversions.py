# <START-OF-CODE>

# Method to count the number of inversions in the array
def countInversions(arr):
    return mergeSortAndCount(arr, 0, len(arr) - 1)

# Recursive method to perform merge sort and count inversions
def mergeSortAndCount(arr, left, right):
    # Base case: if the left index is greater than or equal to the right index
    if left >= right:
        return 0 # No inversions

    # Calculate the middle index
    mid = left + (right - left) / 2
    inversions = 0

    # Recursively count inversions in the left half
    inversions += mergeSortAndCount(arr, left, mid)
    # Recursively count inversions in the right half
    inversions += mergeSortAndCount(arr, mid + 1, right)
    # Count inversions while merging the two halves
    inversions += mergeAndCount(arr, left, mid, right)

    return inversions # Return total inversions

# Method to merge two halves and count inversions
def mergeAndCount(arr, left, mid, right):
    # Create temporary arrays for left and right halves
    leftArr = [0] * (mid - left + 1)
    rightArr = [0] * (right - mid)

    # Copy data to temporary arrays
    for i in range(mid - left + 1):
        leftArr[i] = arr[left + i]
    for j in range(right - mid):
        rightArr[j] = arr[mid + 1 + j]

    # Initialize pointers for left, right, and merged array
    i = 0 # Pointer for leftArr
    j = 0 # Pointer for rightArr
    k = left # Pointer for the main array
    inversions = 0 # Count of inversions

    # Merge the two halves while counting inversions
    while i < len(leftArr) and j < len(rightArr):
        if leftArr[i] <= rightArr[j]:
            arr[k] = leftArr[i] # No inversion, copy element from leftArr
            i += 1
        else:
            arr[k] = rightArr[j] # Inversion found, copy element from rightArr
            # Count inversions: all remaining elements in leftArr are greater
            inversions += len(leftArr) - i

        k += 1

    # Copy remaining elements of leftArr, if any
    while i < len(leftArr):
        arr[k] = leftArr[i]
        i += 1
        k += 1

    # Copy remaining elements of rightArr, if any
    while j < len(rightArr):
        arr[k] = rightArr[j]
        j += 1
        k += 1

    return inversions # Return the count of inversions

# Main method to execute the program
def main():
    # Read the number of elements in the array
    n = int(input())
    arr = [0] * n

    # Read the elements of the array
    for i in range(n):
        arr[i] = int(input())

    # Count inversions in the array and store the result
    result = countInversions(arr)
    # Output the number of inversions
    print("Number of inversions: " + str(result))

# Entry point of the program
if __name__ == '__main__':
    main()

# 