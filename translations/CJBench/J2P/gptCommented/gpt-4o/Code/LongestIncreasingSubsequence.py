class Main:
    @staticmethod
    def upper_bound(ar, l, r, key):
        # Perform binary search to find the upper bound
        while l < r - 1:
            m = (l + r) // 2  # Calculate mid-point
            if ar[m] >= key:
                r = m  # Move right if mid is greater than or equal to key
            else:
                l = m  # Move left otherwise
        return r  # Return the upper bound index

    @staticmethod
    def lis(array):
        length = len(array)  # Get the length of the input array
        if length == 0:
            return 0  # Return 0 if the array is empty
        
        tail = [0] * length  # Array to store the smallest tail of all increasing subsequences
        length_lis = 1  # Initialize length of LIS
        tail[0] = array[0]  # Start with the first element

        # Iterate through the array to build the LIS
        for i in range(1, length):
            if array[i] < tail[0]:
                tail[0] = array[i]  # Update the smallest element
            elif array[i] > tail[length_lis - 1]:
                tail[length_lis] = array[i]  # Extend the LIS
                length_lis += 1
            else:
                # Find the position to replace in the tail array
                tail[Main.upper_bound(tail, -1, length_lis - 1, array[i])] = array[i]
        return length_lis  # Return the length of the LIS

    @staticmethod
    def find_lis_len(a):
        size = len(a)  # Get the size of the input array
        if size == 0:
            return 0  # Return 0 if the array is empty
        
        arr = [0] * size  # Array to store the smallest tail of increasing subsequences
        arr[0] = a[0]  # Initialize the first element
        lis = 1  # Initialize length of LIS

        # Iterate through the array to compute LIS length
        for i in range(1, size):
            # Find the position to insert the current element
            index = Main.binary_search_between(arr, lis - 1, a[i])
            arr[index] = a[i]  # Update the tail array
            if index == lis:
                lis += 1  # Increase the length of LIS if a new longer subsequence is found
        return lis  # Return the length of the LIS

    @staticmethod
    def binary_search_between(t, end, key):
        left = 0  # Initialize left pointer
        right = end  # Initialize right pointer
        
        # Check if the key is less than the smallest element
        if key < t[0]:
            return 0  # Return 0 if key is the smallest
        # Check if the key is greater than the largest element
        if key > t[end]:
            return end + 1  # Return end + 1 if key is the largest
        
        # Perform binary search to find the correct position
        while left < right - 1:
            middle = (left + right) // 2  # Calculate mid-point
            if t[middle] < key:
                left = middle  # Move left pointer if middle is less than key
            else:
                right = middle  # Move right pointer otherwise
        return right  # Return the position to insert the key

# Main execution
if __name__ == "__main__":
    n = int(input())  # Read the number of elements
    array = list(map(int, input().split()))  # Read each element into the array
    method = int(input())  # Read the method choice (1 or 2)
    
    # Determine which method to use based on user input
    if method == 1:
        result = Main.lis(array)  # Call the first method
    else:
        result = Main.find_lis_len(array)  # Call the second method
    
    # Output the result
    print("The length of the longest increasing subsequence is:", result)

# <END-OF-CODE>
