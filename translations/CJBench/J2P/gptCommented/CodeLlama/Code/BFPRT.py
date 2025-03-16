
import sys

def main():
    # Read the size of the array
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    
    # Read the value of k
    k = int(sys.stdin.readline())
    
    # Get the k smallest numbers from the array
    result = get_min_k_nums(arr, k)
    
    # Print the result
    for num in result:
        print(num, end=" ")
    print()

def get_min_k_nums(arr, k):
    # Check if k is within valid range
    if k < 1 or k > len(arr):
        return None # Return null if k is invalid
    
    # Find the k-th smallest number
    min_kth = get_min_kth(arr, k)
    res = [0] * k # Array to hold the k smallest numbers
    index = 0
    
    # Populate the result array with numbers smaller than the k-th smallest
    for value in arr:
        if value < min_kth:
            res[index] = value
            index += 1
    
    # Fill the remaining slots in the result array with the k-th smallest number
    for i in range(index, len(res)):
        res[i] = min_kth
    
    return res # Return the array of k smallest numbers

def get_min_kth(arr, k):
    # Base case: if the range has only one element
    if len(arr) == 1:
        return arr[0] # Return that element
    
    # Find the pivot using the median of medians method
    pivot = median_of_medians(arr, k)
    pivot_range = partition(arr, pivot) # Partition the array around the pivot
    
    # Check if the i-th smallest is in the pivot range
    if k >= pivot_range[0] and k <= pivot_range[1]:
        return arr[k] # Return the i-th smallest number
    elif k < pivot_range[0]:
        return get_min_kth(arr[:pivot_range[0]], k) # Search in the left partition
    else:
        return get_min_kth(arr[pivot_range[1] + 1:], k) # Search in the right partition

def median_of_medians(arr, k):
    num = len(arr) # Number of elements in the range
    offset = num % 5 == 0 # Determine if there's an extra group
    m_arr = [0] * (num // 5 + offset) # Array to hold medians
    
    # Calculate the median of each group of 5
    for i in range(len(m_arr)):
        m_arr[i] = get_median(arr[i * 5:i * 5 + 5])
    
    # Recursively find the median of the medians
    return get_min_kth(m_arr, len(m_arr) // 2)

def partition(arr, num):
    small = -1 # Pointer for smaller elements
    cur = 0 # Current pointer
    big = len(arr) # Pointer for larger elements
    
    # Partitioning logic
    while cur != big:
        if arr[cur] < num:
            small += 1
            arr[cur], arr[small] = arr[small], arr[cur]
            cur += 1
        elif arr[cur] > num:
            big -= 1
            arr[cur], arr[big] = arr[big], arr[cur]
        else:
            cur += 1
    
    return small + 1, big - 1 # Return the range of the pivot

def get_median(arr):
    insertion_sort(arr) # Sort the subarray
    mid = len(arr) // 2 # Find the middle index
    return arr[mid] # Return the median value

def insertion_sort(arr):
    if len(arr) < 2:
        return # Return if the array is null or has less than 2 elements
    
    # Insertion sort logic
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            if arr[j - 1] > arr[j]:
                arr[j - 1], arr[j] = arr[j], arr[j - 1]
            else:
                break

if __name__ == "__main__":
    main()

