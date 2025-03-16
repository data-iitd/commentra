
import sys

def main():
    # Read the size of the array
    n = int(input())
    arr = list(map(int, input().split()))
    
    # Read the value of k
    k = int(input())
    
    # Get the k smallest numbers from the array
    result = get_min_k_nums_by_main(arr, k)
    
    # Print the result
    print(" ".join(map(str, result)))

def get_min_k_nums_by_main(arr, k):
    # Check if k is within valid range
    if k < 1 or k > len(arr):
        return None # Return None if k is invalid
    
    # Find the k-th smallest number
    min_kth = get_min_kth_by_main(arr, k)
    res = [0] * k # Array to hold the k smallest numbers
    index = 0
    
    # Populate the result array with numbers smaller than the k-th smallest
    for value in arr:
        if value < min_kth:
            res[index] = value
            index += 1
    
    # Fill the remaining slots in the result array with the k-th smallest number
    while index!= len(res):
        res[index] = min_kth
        index += 1
    
    return res # Return the array of k smallest numbers

def get_min_kth_by_main(arr, k):
    copy_arr = arr[:] # Create a copy of the original array
    return bfprt(copy_arr, 0, len(copy_arr) - 1, k - 1) # Use Main algorithm to find the k-th smallest

def bfprt(arr, begin, end, i):
    # Base case: if the range has only one element
    if begin == end:
        return arr[begin] # Return that element
    
    # Find the pivot using the median of medians method
    pivot = median_of_medians(arr, begin, end)
    pivot_range = partition(arr, begin, end, pivot) # Partition the array around the pivot
    
    # Check if the i-th smallest is in the pivot range
    if i >= pivot_range[0] and i <= pivot_range[1]:
        return arr[i] # Return the i-th smallest number
    elif i < pivot_range[0]:
        return bfprt(arr, begin, pivot_range[0] - 1, i) # Search in the left partition
    else:
        return bfprt(arr, pivot_range[1] + 1, end, i) # Search in the right partition

def median_of_medians(arr, begin, end):
    num = end - begin + 1 # Number of elements in the range
    offset = 0 if num % 5 == 0 else 1 # Determine if there's an extra group
    m_arr = [0] * (num // 5 + offset) # Array to hold medians
    
    # Calculate the median of each group of 5
    for i in range(len(m_arr)):
        m_arr[i] = get_median(arr, begin + i * 5, min(end, begin + i * 5 + 4))
    
    # Recursively find the median of the medians
    return bfprt(m_arr, 0, len(m_arr) - 1, len(m_arr) // 2)

def partition(arr, begin, end, num):
    small = begin - 1 # Pointer for smaller elements
    cur = begin # Current pointer
    big = end + 1 # Pointer for larger elements
    
    # Partitioning logic
    while cur!= big:
        if arr[cur] < num:
            small += 1 # Move smaller elements to the left
            arr[small], arr[cur] = arr[cur], arr[small] # Swap elements
            cur += 1
        elif arr[cur] > num:
            big -= 1 # Move larger elements to the right
            arr[big], arr[cur] = arr[cur], arr[big] # Swap elements
        else:
            cur += 1
    
    return [small + 1, big - 1] # Return the range of the pivot

def get_median(arr, begin, end):
    insertion_sort(arr, begin, end) # Sort the subarray
    sum = begin + end # Calculate the sum of indices
    mid = sum // 2 + (sum % 2) # Find the middle index
    return arr[mid] # Return the median value

def insertion_sort(arr, begin, end):
    if arr is None or len(arr) < 2:
        return # Return if the array is None or has less than 2 elements
    
    # Insertion sort logic
    for i in range(begin + 1, end + 1):
        for j in range(i, begin, -1):
            if arr[j - 1] > arr[j]:
                arr[j - 1], arr[j] = arr[j], arr[j - 1] # Swap elements to sort
            else:
                break # Break if the order is correct

if __name__ == "__main__":
    main()

