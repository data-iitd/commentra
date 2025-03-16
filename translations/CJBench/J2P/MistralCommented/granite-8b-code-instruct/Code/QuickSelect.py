
import random

# This function provides a method to select the n-th smallest element from a list of comparable elements.
def select(list, n):
    if list is None: # Check if the list is None.
        raise ValueError("The list of elements must not be None.")
    if len(list) == 0: # Check if the list is empty.
        raise ValueError("The list of elements must not be empty.")
    if n < 0 or n >= len(list): # Check if the index is within the bounds of the list.
        raise IndexError("The index must be between 0 and the size of the list - 1.")
    # Find the index of the n-th smallest element using the select_index function.
    index = select_index(list, n)
    # Return the n-th smallest element.
    return list[index]

# Recursive helper function to find the index of the n-th smallest element.
def select_index(list, n):
    return select_index_helper(list, 0, len(list) - 1, n)

# Recursive helper function to find the index of the n-th smallest element using partitioning.
def select_index_helper(list, left, right, n):
    while True:
        pivot_index = pivot(list, left, right) # Find the pivot index.
        pivot_index_partitioned = partition(list, left, right, pivot_index, n) # Partition the list around the pivot.
        if n == pivot_index_partitioned: # If n is the pivot index, return it.
            return n
        elif n < pivot_index_partitioned: # If n is to the left of the pivot index, search in the left subarray.
            right = pivot_index_partitioned - 1
        else: # If n is to the right of the pivot index, search in the right subarray.
            left = pivot_index_partitioned + 1

# Helper function to partition the list around a randomly chosen pivot.
def partition(list, left, right, pivot_index, n):
    pivot_value = list[pivot_index] # Get the value of the pivot element.
    list[pivot_index], list[right] = list[right], list[pivot_index] # Swap the pivot element with the last element.
    store_index = left # Initialize the index of the first element in the sorted subarray.
    for i in range(left, right): # Iterate through the elements in the subarray.
        if list[i] < pivot_value: # If the element is smaller than the pivot, swap it with the first element in the sorted subarray and increment the index.
            list[i], list[store_index] = list[store_index], list[i]
            store_index += 1
    store_index_eq = store_index # Initialize the index of the first equal element in the sorted subarray.
    for i in range(store_index, right): # Iterate through the equal elements in the subarray.
        if list[i] == pivot_value: # If the element is equal to the pivot, swap it with the last equal element in the sorted subarray and increment the index.
            list[i], list[store_index_eq] = list[store_index_eq], list[i]
            store_index_eq += 1
    list[right], list[store_index_eq] = list[store_index_eq], list[right] # Swap the last equal element with the last element in the subarray.
    return (n < store_index) and store_index or min(n, store_index_eq) # Return the index of n in the sorted subarray.

# Helper function to find a good pivot index using the median of five elements.
def pivot(list, left, right):
    if right - left < 5: # If the subarray has fewer than five elements, use the simple partitioning method.
        return partition_5(list, left, right)
    for i in range(left, right, 5): # Iterate through the subarray in steps of five elements.
        sub_right = min(i + 4, right) # Determine the index of the last element in the current subarray of five elements.
        median_5 = partition_5(list, i, sub_right) # Find the median of the current subarray of five elements.
        list[median_5], list[left + (i - left) // 5] = list[left + (i - left) // 5], list[median_5] # Swap the median with the pivot position.
    mid = left + (right - left) // 10 + 1 # Determine the middle index of the subarray.
    right_index = left + (right - left) // 5 # Determine the index of the fifth element from the left in the subarray.
    return select_index(list, left, right_index, mid) # Find the index of the pivot using the select_index function.

# Helper function to partition the list around a simple pivot (the middle element).
def partition_5(list, left, right):
    sublist = list[left:right + 1] # Create a sublist of the current subarray.
    sublist.sort() # Sort the sublist.
    return left + (right - left) // 2 # Return the index of the middle element in the sorted sublist.

# Main function to read input and test the select function.
def main():
    n = int(input("Enter the number of elements in the list: ")) # Read the number of elements in the list.
    list = [] # Create an empty list to store the elements.
    for i in range(n): # Iterate through the input and add each element to the list.
        list.append(int(input("Enter element " + str(i) + ": ")))
    index = int(input("Enter the index of the desired element: ")) # Read the index of the desired element.
    try: # Begin a try block to handle exceptions.
        result = select(list, index) # Call the select function to find the desired element.
        print("The " + str(index) + "-th smallest element is: " + str(result)) # Print the result if successful.
    except Exception as e: # Catch any exceptions thrown by the select function.
        print(str(e)) # Print the error message if an exception occurs.

if __name__ == "__main__": # Call the main function if the script is executed directly.
    main()

