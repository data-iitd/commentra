
class Main:
    def __init__(self):
        pass

    def sort(self, array):
        # If the array is empty, there's nothing to sort
        if len(array) == 0:
            return

        # Initialize left and right pointers for the sorting process
        left = 0
        right = len(array) - 1

        # Continue sorting until the left pointer meets the right pointer
        while left < right:
            # Perform a forward pass to bubble up the largest element
            right = self.performForwardPass(array, left, right)
            # Perform a backward pass to bubble down the smallest element
            left = self.performBackwardPass(array, left, right)

    # Method to perform a forward pass in the sorting process
    def performForwardPass(self, array, left, right):
        # Track the last index where a swap occurred
        lastSwappedIndex = left

        # Iterate from the left to the right, comparing adjacent elements
        for i in range(left, right):
            # If the current element is greater than the next, swap them
            if array[i] > array[i + 1]:
                self.swap(array, i, i + 1)
                lastSwappedIndex = i  # Update the last swapped index

        # Return the last index where a swap occurred
        return lastSwappedIndex

    # Method to perform a backward pass in the sorting process
    def performBackwardPass(self, array, left, right):
        # Track the last index where a swap occurred
        lastSwappedIndex = right

        # Iterate from the right to the left, comparing adjacent elements
        for i in range(right, left, -1):
            # If the current element is less than the previous, swap them
            if array[i] < array[i - 1]:
                self.swap(array, i - 1, i)
                lastSwappedIndex = i  # Update the last swapped index

        # Return the last index where a swap occurred
        return lastSwappedIndex

    # Method to swap two elements in the array
    def swap(self, array, i, j):
        # Store the element at index i in a temporary variable
        temp = array[i]
        # Swap the elements at index i and j
        array[i] = array[j]
        array[j] = temp

# Create a Main object
sorter = Main()

# Read the number of elements to be sorted
n = int(input())

# Initialize an array to hold the input integers
array = []

# Read n integers from the console and store them in the array
for i in range(n):
    array.append(int(input()))

# Sort the array using the custom sort method
sorter.sort(array)

# Print the sorted array to the console
for num in array:
    print(num, end=" ")

# 