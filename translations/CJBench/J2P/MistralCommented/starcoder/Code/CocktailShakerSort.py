
import sys

class Main:
    def __init__(self):
        # Read the number of elements in the array from the user input
        self.n = int(input())

        # Allocate memory for an array of Integer type with the given size
        self.array = [0] * self.n

        # Read each element of the array from the user input
        for i in range(self.n):
            self.array[i] = int(input())

    # A method to sort an array of Comparable type using the bubble sort algorithm
    def sort(self):
        # Base case: if the array is empty, return without doing anything
        if self.n == 0:
            return

        # Initialize two pointers, one at the beginning and another at the end of the array
        left = 0
        right = self.n - 1

        # Repeat the following steps until the array is sorted
        while left < right:
            # Perform a forward pass to swap elements if they are in the wrong order
            right = self.performForwardPass(left, right)

            # Perform a backward pass to swap elements if they are in the wrong order
            left = self.performBackwardPass(left, right)

    # A helper method to perform a forward pass in the bubble sort algorithm
    def performForwardPass(self, left, right):
        # Initialize a variable to keep track of the last index where a swap occurred
        lastSwappedIndex = left

        # Iterate through the array from the left pointer to the right pointer - 1
        for i in range(left, right):
            # If the current element is greater than the next element, swap them
            if self.array[i] > self.array[i + 1]:
                self.swap(i, i + 1)
                lastSwappedIndex = i

        # Return the last index where a swap occurred
        return lastSwappedIndex

    # A helper method to perform a backward pass in the bubble sort algorithm
    def performBackwardPass(self, left, right):
        # Initialize a variable to keep track of the last index where a swap occurred
        lastSwappedIndex = right

        # Iterate through the array from the right pointer to the left pointer + 1
        for i in range(right, left, -1):
            # If the current element is smaller than the previous element, swap them
            if self.array[i] < self.array[i - 1]:
                self.swap(i - 1, i)
                lastSwappedIndex = i

        # Return the last index where a swap occurred
        return lastSwappedIndex

    # A helper method to swap two elements in the array
    def swap(self, i, j):
        # Swap the elements at the given indices
        temp = self.array[i]
        self.array[i] = self.array[j]
        self.array[j] = temp

# Read the number of elements in the array from the user input
n = int(input())

# Allocate memory for an array of Integer type with the given size
array = [0] * n

# Read each element of the array from the user input
for i in range(n):
    array[i] = int(input())

# Create an instance of the Main class and call the sort method to sort the array
sorter = Main()
sorter.sort()

# Print each element of the sorted array to the console
for num in array:
    print(num, end=" ")

# 