import sys; # Importing sys for input

def upperBound(ar, l, r, key): # Helper method to find the smallest index with a value greater than or equal to key
    while l < r - 1:
        m = (l + r) // 2
        if ar[m] >= key:
            r = m
        else:
            l = m
    return r

def lis(array): # Method to calculate the length of the longest increasing subsequence
    len = len(array)
    if len == 0:
        return 0
    tail = [0] * len # Array to store the last element of each increasing subsequence
    length = 1 # Length of the LIS
    tail[0] = array[0] # Initialize the first element
    for i in range(1, len):
        if array[i] < tail[0]:
            tail[0] = array[i] # Replace the smallest element
        elif array[i] > tail[length - 1]:
            tail[length] = array[i] # Append to the LIS
        else:
            tail[upperBound(tail, -1, length - 1, array[i])] = array[i] # Replace the appropriate element
        length += 1
    return length

def findLISLen(a): # Alternative method to calculate the length of the longest increasing subsequence
    size = len(a)
    if size == 0:
        return 0
    arr = [0] * size # Array to store the LIS
    arr[0] = a[0]
    lis = 1 # Length of the LIS
    for i in range(1, size):
        index = binarySearchBetween(arr, lis - 1, a[i])
        arr[index] = a[i]
        if index == lis:
            lis += 1
    return lis

def binarySearchBetween(t, end, key): # Helper method to find the position to replace in the array for the binary search method
    left = 0
    right = end
    if key < t[0]:
        return 0
    if key > t[end]:
        return end + 1
    while left < right - 1:
        middle = (left + right) // 2
        if t[middle] < key:
            left = middle
        else:
            right = middle
    return right

if __name__ == "__main__":
    n = int(sys.stdin.readline()) # Read the number of elements
    array = [0] * n # Create an array to store the elements
    for i in range(n):
        array[i] = int(sys.stdin.readline()) # Read the elements
    method = int(sys.stdin.readline()) # Read the method choice
    result = 0
    if method == 1:
        result = lis(array) # Calculate LIS using the first method
    else:
        result = findLISLen(array) # Calculate LIS using the second method
    print("The length of the longest increasing subsequence is: " + str(result)) # Print the result

