

def sort(array):
    # Base case: if the array is empty, return without doing anything
    if len(array) == 0:
        return

    # Initialize two pointers, one at the beginning and another at the end of the array
    left = 0
    right = len(array) - 1

    # Repeat the following steps until the array is sorted
    while left < right:
        # Perform a forward pass to swap elements if they are in the wrong order
        right = perform_forward_pass(array, left, right)

        # Perform a backward pass to swap elements if they are in the wrong order
        left = perform_backward_pass(array, left, right)

def perform_forward_pass(array, left, right):
    # Initialize a variable to keep track of the last index where a swap occurred
    last_swapped_index = left

    # Iterate through the array from the left pointer to the right pointer - 1
    for i in range(left, right):
        # If the current element is greater than the next element, swap them
        if array[i] > array[i + 1]:
            array[i], array[i + 1] = array[i + 1], array[i]
            last_swapped_index = i

    # Return the last index where a swap occurred
    return last_swapped_index

def perform_backward_pass(array, left, right):
    # Initialize a variable to keep track of the last index where a swap occurred
    last_swapped_index = right

    # Iterate through the array from the right pointer to the left pointer + 1
    for i in range(right, left, -1):
        # If the current element is smaller than the previous element, swap them
        if array[i] < array[i - 1]:
            array[i - 1], array[i] = array[i], array[i - 1]
            last_swapped_index = i

    # Return the last index where a swap occurred
    return last_swapped_index

# Read the number of elements in the array from the user input
n = int(input("Enter the number of elements in the array: "))

# Allocate memory for an array of Integer type with the given size
array = [None] * n

# Read each element of the array from the user input
for i in range(n):
    array[i] = int(input(f"Enter element {i + 1}: "))

# Call the sort method to sort the array
sort(array)

# Print each element of the sorted array to the console
print("Sorted array:", array)

# Translate the above Python code to Java and end with comment "