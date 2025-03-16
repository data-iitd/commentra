
import sys

def main():
    # Read the number of elements to be sorted
    n = int(input())
    
    # Initialize a list to hold the input integers
    array = []
    
    # Read n integers from the console and store them in the list
    for _ in range(n):
        array.append(int(input()))
    
    # Sort the array using the custom sort method
    sort(array)
    
    # Print the sorted array to the console
    for num in array:
        print(num, end=" ")

# Generic method to sort an array of comparable elements
def sort(array):
    # If the array is empty, there's nothing to sort
    if len(array) == 0:
        return
    
    # Initialize left and right pointers for the sorting process
    left = 0
    right = len(array) - 1
    
    # Continue sorting until the left pointer meets the right pointer
    while left < right:
        # Perform a forward pass to bubble up the largest element
        right = perform_forward_pass(array, left, right)
        # Perform a backward pass to bubble down the smallest element
        left = perform_backward_pass(array, left, right)

# Method to perform a forward pass in the sorting process
def perform_forward_pass(array, left, right):
    # Track the last index where a swap occurred
    last_swapped_index = left
    
    # Iterate from the left to the right, comparing adjacent elements
    for i in range(left, right):
        # If the current element is greater than the next, swap them
        if array[i] > array[i + 1]:
            array[i], array[i + 1] = array[i + 1], array[i]
            last_swapped_index = i # Update the last swapped index
    
    # Return the last index where a swap occurred
    return last_swapped_index

# Method to perform a backward pass in the sorting process
def perform_backward_pass(array, left, right):
    # Track the last index where a swap occurred
    last_swapped_index = right
    
    # Iterate from the right to the left, comparing adjacent elements
    for i in range(right, left, -1):
        # If the current element is less than the previous, swap them
        if array[i] < array[i - 1]:
            array[i - 1], array[i] = array[i], array[i - 1]
            last_swapped_index = i # Update the last swapped index
    
    # Return the last index where a swap occurred
    return last_swapped_index

if __name__ == "__main__":
    main()

