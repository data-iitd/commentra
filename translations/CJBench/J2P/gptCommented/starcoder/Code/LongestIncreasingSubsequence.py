import sys

# Function to find the upper bound index for a key in a sorted array
def upperBound(ar, l, r, key):
    # Perform binary search to find the upper bound
    while l < r - 1:
        m = (l + r) // 2 # Calculate mid-point
        if ar[m] >= key:
            r = m # Move right if mid is greater than or equal to key
        else:
            l = m # Move left otherwise
    return r # Return the upper bound index

# Function to compute the length of the longest increasing subsequence (LIS)
def lis(array):
    len = len(array) # Get the length of the input array
    if len == 0:
        return 0 # Return 0 if the array is empty
    
    tail = [0] * len # Array to store the smallest tail of all increasing subsequences
    length = 1 # Initialize length of LIS
    tail[0] = array[0] # Start with the first element

    # Iterate through the array to build the LIS
    for i in range(1, len):
        if array[i] < tail[0]:
            tail[0] = array[i] # Update the smallest element
        elif array[i] > tail[length - 1]:
            tail[length] = array[i] # Extend the LIS
            length += 1 # Increase the length of LIS
        else:
            # Find the position to replace in the tail array
            tail[upperBound(tail, -1, length - 1, array[i])] = array[i]
    return length # Return the length of the LIS

# Function to find the length of the longest increasing subsequence using a different approach
def findLISLen(a):
    size = len(a) # Get the size of the input array
    if size == 0:
        return 0 # Return 0 if the array is empty
    
    arr = [0] * size # Array to store the smallest tail of increasing subsequences
    arr[0] = a[0] # Initialize the first element
    lis = 1 # Initialize length of LIS

    # Iterate through the array to compute LIS length
    for i in range(1, size):
        # Find the position to insert the current element
        index = binarySearchBetween(arr, lis - 1, a[i])
        arr[index] = a[i] # Update the tail array
        if index == lis:
            lis += 1 # Increase the length of LIS if a new longer subsequence is found
    return lis # Return the length of the LIS

# Function to perform binary search to find the correct position for the key
def binarySearchBetween(t, end, key):
    left = 0 # Initialize left pointer
    right = end # Initialize right pointer
    
    # Check if the key is less than the smallest element
    if key < t[0]:
        return 0 # Return 0 if key is the smallest
    # Check if the key is greater than the largest element
    if key > t[end]:
        return end + 1 # Return end + 1 if key is the largest
    
    # Perform binary search to find the correct position
    while left < right - 1:
        middle = (left + right) // 2 # Calculate mid-point
        if t[middle] < key:
            left = middle # Move left pointer if middle is less than key
        else:
            right = middle # Move right pointer otherwise
    return right # Return the position to insert the key

# Main method to execute the program
def main():
    n = int(input()) # Read the number of elements
    array = [0] * n # Initialize the array
    for i in range(n):
        array[i] = int(input()) # Read each element into the array
    method = int(input()) # Read the method choice (1 or 2)
    result = 0 # Variable to store the result
    
    # Determine which method to use based on user input
    if method == 1:
        result = lis(array) # Call the first method
    else:
        result = findLISLen(array) # Call the second method
    
    # Output the result
    print("The length of the longest increasing subsequence is: " + str(result))

if __name__ == "__main__":
    main()

