import sys

# Private method to prevent instantiation
def __init__(self):
    pass

# Main method
def main():
    # Read input from stdin
    n = int(raw_input().strip())
    arr = [int(raw_input().strip()) for _ in range(n)]
    k = int(raw_input().strip())

    # Get the k smallest numbers from the array
    result = getMinKNumsByMain(arr, k)

    # Print the result
    for num in result:
        print num,
    print

# Method to get the k smallest numbers from the array
def getMinKNumsByMain(arr, k):
    # Check if k is within valid range
    if k < 1 or k > len(arr):
        return None # Return null if k is invalid
    # Find the k-th smallest number
    minKth = getMinKthByMain(arr, k)
    res = [0] * k # Array to hold the k smallest numbers
    index = 0
    # Populate the result array with numbers smaller than the k-th smallest
    for value in arr:
        if value < minKth:
            res[index] = value
            index += 1
    # Fill the remaining slots in the result array with the k-th smallest number
    for i in range(index, k):
        res[i] = minKth
    return res # Return the array of k smallest numbers

# Method to find the k-th smallest number in the array
def getMinKthByMain(arr, k):
    copyArr = copyArray(arr) # Create a copy of the original array
    return bfprt(copyArr, 0, len(copyArr) - 1, k - 1) # Use Main algorithm to find the k-th smallest

# Method to create a copy of the array
def copyArray(arr):
    copyArr = [0] * len(arr)
    for i in range(len(arr)):
        copyArr[i] = arr[i] # Copy elements from original array
    return copyArr # Return the copied array

# Main algorithm to find the i-th smallest number
def bfprt(arr, begin, end, i):
    # Base case: if the range has only one element
    if begin == end:
        return arr[begin] # Return that element
    # Find the pivot using the median of medians method
    pivot = medianOfMedians(arr, begin, end)
    pivotRange = partition(arr, begin, end, pivot) # Partition the array around the pivot
    # Check if the i-th smallest is in the pivot range
    if i >= pivotRange[0] and i <= pivotRange[1]:
        return arr[i] # Return the i-th smallest number
    elif i < pivotRange[0]:
        return bfprt(arr, begin, pivotRange[0] - 1, i) # Search in the left partition
    else:
        return bfprt(arr, pivotRange[1] + 1, end, i) # Search in the right partition

# Method to find the median of medians
def medianOfMedians(arr, begin, end):
    num = end - begin + 1 # Number of elements in the range
    offset = num % 5 == 0? 0 : 1 # Determine if there's an extra group
    mArr = [0] * (num / 5 + offset) # Array to hold medians
    # Calculate the median of each group of 5
    for i in range(len(mArr)):
        mArr[i] = getMedian(arr, begin + i * 5, min(end, begin + i * 5 + 4))
    # Recursively find the median of the medians
    return bfprt(mArr, 0, len(mArr) - 1, len(mArr) / 2)

# Method to partition the array around a pivot
def partition(arr, begin, end, num):
    small = begin - 1 # Pointer for smaller elements
    cur = begin # Current pointer
    big = end + 1 # Pointer for larger elements
    # Partitioning logic
    while cur!= big:
        if arr[cur] < num:
            swap(arr, small + 1, cur) # Move smaller elements to the left
            small += 1
            cur += 1
        elif arr[cur] > num:
            swap(arr, big - 1, cur) # Move larger elements to the right
            big -= 1
        else:
            cur += 1 # Move current pointer forward
    return [small + 1, big - 1] # Return the range of the pivot

# Method to find the median of a subarray
def getMedian(arr, begin, end):
    insertionSort(arr, begin, end) # Sort the subarray
    sum = begin + end # Calculate the sum of indices
    mid = sum / 2 + (sum % 2) # Find the middle index
    return arr[mid] # Return the median value

# Insertion sort algorithm for sorting a subarray
def insertionSort(arr, begin, end):
    if arr == None or len(arr) < 2:
        return # Return if the array is null or has less than 2 elements
    # Insertion sort logic
    for i in range(begin + 1, end + 1):
        for j in range(i, begin, -1):
            if arr[j - 1] > arr[j]:
                swap(arr, j - 1, j) # Swap elements to sort
            else:
                break # Break if the order is correct

# Method to swap two elements in the array
def swap(arr, i, j):
    temp = arr[i] # Store the value at index i
    arr[i] = arr[j] # Assign the value at index j to index i
    arr[j] = temp # Assign the stored value to index j

# Main method
if __name__ == "__main__":
    main()

# 