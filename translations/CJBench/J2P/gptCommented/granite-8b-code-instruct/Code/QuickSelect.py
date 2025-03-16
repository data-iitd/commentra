
import random

def select(list, n):
    # Ensure the list is not null
    if list is None:
        raise ValueError("The list of elements must not be null.")
    
    # Check if the list is empty
    if len(list) == 0:
        raise ValueError("The list of elements must not be empty.")
    
    # Validate the index n
    if n < 0 or n >= len(list):
        raise IndexError("The index must be between 0 and the size of the list - 1.")
    
    # Get the index of the n-th smallest element
    index = select_index(list, n)
    return list[index] # Return the n-th smallest element

def select_index(list, n):
    return select_index_helper(list, 0, len(list) - 1, n)

def select_index_helper(list, left, right, n):
    while True:
        # If the left and right pointers converge, return the left index
        if left == right:
            return left
        
        # Choose a pivot index for partitioning
        pivot_index = pivot(list, left, right)
        # Partition the list around the pivot and get the new pivot index
        pivot_index = partition(list, left, right, pivot_index, n)
        
        # Check if the pivot index is the desired index
        if n == pivot_index:
            return n # Found the n-th smallest element
        elif n < pivot_index:
            right = pivot_index - 1 # Search in the left part
        else:
            left = pivot_index + 1 # Search in the right part

def partition(list, left, right, pivot_index, n):
    pivot_value = list[pivot_index] # Get the pivot value
    list[pivot_index], list[right] = list[right], list[pivot_index] # Move pivot to the end
    store_index = left # Pointer for the next position to swap
    
    # Partition the list into elements less than the pivot
    for i in range(left, right):
        if list[i] < pivot_value:
            list[store_index], list[i] = list[i], list[store_index]
            store_index += 1
    
    # Handle elements equal to the pivot
    store_index_eq = store_index
    for i in range(store_index, right):
        if list[i] == pivot_value:
            list[store_index_eq], list[i] = list[i], list[store_index_eq]
            store_index_eq += 1
    
    # Move the pivot to its final place
    list[right], list[store_index_eq] = list[store_index_eq], list[right]
    # Return the appropriate index based on the n value
    return (n < store_index) and store_index or min(n, store_index_eq)

def pivot(list, left, right):
    # If the range is small, use a simple partitioning method
    if right - left < 5:
        return partition_5(list, left, right)
    
    # Group elements into sublists of 5 and find their medians
    for i in range(left, right, 5):
        sub_right = min(i + 4, right)
        median_5 = partition_5(list, i, sub_right)
        list[median_5], list[left + (i - left) // 5] = list[left + (i - left) // 5], list[median_5] # Move median to the front
    
    # Recursively select the median of the medians
    mid = left + (right - left) // 10 + 1
    right_index = left + (right - left) // 5
    return select_index_helper(list, left, right_index, mid)

def partition_5(list, left, right):
    sublist = list[left:right + 1] # Create a sublist
    sublist.sort() # Sort the sublist
    return left + (right - left) // 2 # Return the median index

if __name__ == "__main__":
    n = int(input("Enter the number of elements: ")) # Read the number of elements
    list = [int(input("Enter element " + str(i) + ": ")) for i in range(n)] # Read the elements into the list
    
    index = int(input("Enter the index of the desired smallest element: ")) # Read the index of the desired smallest element
    try:
        # Attempt to select the n-th smallest element
        result = select(list, index)
        print("The " + str(index) + "-th smallest element is: " + str(result))
    except Exception as e:
        # Print any exceptions that occur
        print(str(e))