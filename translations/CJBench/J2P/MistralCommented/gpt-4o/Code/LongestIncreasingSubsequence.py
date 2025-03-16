class Main:
    @staticmethod
    def upper_bound(ar, l, r, key):
        # Binary search algorithm to find the index of the last occurrence of key in the subarray ar[l..r]
        while l < r - 1:
            m = (l + r) // 2  # Calculate the middle index
            if ar[m] >= key:  # If the middle element is greater than or equal to key
                r = m  # Update the right index
            else:
                l = m  # Otherwise, update the left index
        return r  # Return the index of the last occurrence of key

    @staticmethod
    def lis(array):
        # Length of the Longest Increasing Subsequence in the given array
        length = len(array)
        if length == 0:
            return 0  # Base case: empty array has no LIS
        tail = [0] * length  # Array to store the last element of each LIS
        length_lis = 1  # Length of the current LIS
        tail[0] = array[0]  # Initialize the first element of tail array
        for i in range(1, length):
            if array[i] < tail[0]:  # If the current element is smaller than the first element of tail array
                tail[0] = array[i]  # Update the first element of tail array
            elif array[i] > tail[length_lis - 1]:  # If the current element is greater than the last element of the current LIS
                tail[length_lis] = array[i]  # Add the current element to the tail array
                length_lis += 1  # Increment the length of LIS
            else:  # If the current element can be added to an existing LIS
                tail[Main.upper_bound(tail, -1, length_lis - 1, array[i])] = array[i]  # Update the last element of the LIS that contains the current element
        return length_lis  # Return the length of the Longest Increasing Subsequence

    @staticmethod
    def find_lis_len(a):
        # Length of the Longest Increasing Subsequence using binary search
        size = len(a)
        if size == 0:
            return 0  # Base case: empty array has no LIS
        arr = [0] * size  # Array to store the last occurrence of each element in the sorted array
        arr[0] = a[0]
        lis = 1
        for i in range(1, size):
            index = Main.binary_search_between(arr, lis - 1, a[i])  # Binary search to find the index where a[i] should be inserted in arr
            arr[index] = a[i]  # Update the array with the current element
            if index == lis:  # If the index is equal to the length of LIS
                lis += 1  # Increment the length of LIS
        return lis  # Return the length of the Longest Increasing Subsequence

    @staticmethod
    def binary_search_between(t, end, key):
        # Binary search algorithm to find the index where key should be inserted in the sorted subarray t[0..end]
        left = 0
        right = end
        if key < t[0]:  # If key is smaller than the first element of the subarray
            return 0  # Return 0 as the index
        if key > t[end]:  # If key is greater than the last element of the subarray
            return end + 1  # Return end+1 as the index
        while left < right - 1:  # Iterate until the search space is reduced to one element
            middle = (left + right) // 2  # Calculate the middle index
            if t[middle] < key:  # If the middle element is smaller than key
                left = middle  # Update the left index
            else:
                right = middle  # Otherwise, update the right index
        return right  # Return the index where key should be inserted

if __name__ == "__main__":
    n = int(input())  # Read the number of elements in the array from the console
    array = list(map(int, input().split()))  # Create an array of size n to store the input elements
    method = int(input())  # Read the method number from the console
    if method == 1:  # If the method number is 1, call the lis() method to find the length of the LIS
        result = Main.lis(array)
    else:  # Otherwise, call the find_lis_len() method to find the length of the LIS using binary search
        result = Main.find_lis_len(array)
    print("The length of the longest increasing subsequence is:", result)  # Print the result to the console

# <END-OF-CODE>
