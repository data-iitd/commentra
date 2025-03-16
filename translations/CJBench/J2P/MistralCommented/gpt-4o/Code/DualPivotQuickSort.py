# Importing the necessary module for user input
import sys

# Method to sort a list of comparable elements using dual pivot quicksort algorithm
def sort(array):
    if len(array) > 1:  # Check if the array has more than one element to sort
        dual_pivot_quicksort(array, 0, len(array) - 1)  # Call dual_pivot_quicksort method to sort the array

# Recursive method to implement dual pivot quicksort algorithm
def dual_pivot_quicksort(array, left, right):
    if left < right:  # Check if the left index is less than the right index
        pivots = partition(array, left, right)  # Call partition method to find the pivots
        dual_pivot_quicksort(array, left, pivots[0] - 1)  # Recursively sort elements before the first pivot
        dual_pivot_quicksort(array, pivots[0] + 1, pivots[1] - 1)  # Recursively sort elements between the pivots
        dual_pivot_quicksort(array, pivots[1] + 1, right)  # Recursively sort elements after the second pivot

# Method to partition the array and find the pivots
def partition(array, left, right):
    if array[left] > array[right]:  # Swap the first and last elements if the first is greater than the last
        swap(array, left, right)
    pivot1 = array[left]  # Set the first element as the first pivot
    pivot2 = array[right]  # Set the last element as the second pivot
    pivot1_end = left + 1  # Initialize the index for the first pivot's end
    low = left + 1  # Initialize the index for the first iteration
    high = right - 1  # Initialize the index for the last iteration

    # Iterate through the array to find the correct positions for the pivots
    while low <= high:
        if array[low] < pivot1:  # If the current element is less than the first pivot
            swap(array, low, pivot1_end)  # Swap it with the element at pivot1_end
            pivot1_end += 1
        elif array[low] >= pivot2:  # If the current element is greater than or equal to the second pivot
            while low < high and array[high] > pivot2:  # If the current high element is greater than the second pivot
                swap(array, low, high)  # Swap it with the element at low
                high -= 1
            swap(array, low, high)  # Swap the current low and high elements
            high -= 1
            if array[low] < pivot1:  # If the current low element is less than the first pivot
                swap(array, low, pivot1_end)  # Swap it with the element at pivot1_end
                pivot1_end += 1
        low += 1  # Increment the low index for the next iteration

    # Swap the pivots with the elements at pivot1_end and high indices
    pivot1_end -= 1
    high += 1
    swap(array, left, pivot1_end)
    swap(array, right, high)

    # Return the indices of the pivots
    return [pivot1_end, high]

# Method to swap two elements in the array
def swap(array, i, j):
    array[i], array[j] = array[j], array[i]  # Swap elements at indices i and j

# Main method to read user input and call sort method
if __name__ == "__main__":
    n = int(input())  # Read the number of elements in the array from user input
    array = list(map(int, input().split()))  # Create a list of Integers with the given size
    sort(array)  # Call the sort method to sort the array
    print(" ".join(map(str, array)))  # Print the sorted array
# <END-OF-CODE>
