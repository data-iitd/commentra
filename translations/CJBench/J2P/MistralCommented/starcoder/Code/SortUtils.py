
import sys

# Initializes a Scanner object to read input from the standard input stream
scanner = sys.stdin

# Reads the number of elements in the array from the standard input
n = int(scanner.readline())

# Creates an Integer array with the given size
array = [None] * n

# Reads the elements of the array from the standard input and stores them in the array
for i in range(n):
    array[i] = int(scanner.readline())

# Reads the indices i and j of the two elements to be swapped from the standard input
i = int(scanner.readline())
j = int(scanner.readline())

# Swaps the elements at the given indices in the array
array[i], array[j] = array[j], array[i]

# Prints the swapped array
print(array)

# Checks if the array is sorted in ascending order
sorted = is_sorted(array)

# Prints whether the array is sorted or not
print(sorted)

# Reads the left and right indices of the subarray to be flipped from the standard input
left = int(scanner.readline())
right = int(scanner.readline())

# Flips the subarray from left to right in the array
flip(array, left, right)

# Prints the flipped array
print(array)

# Closes the Scanner object
scanner.close()

# Helper method to check if the first element is less than the second element
def less(first_element, second_element):
    return first_element < second_element

# Helper method to check if the first element is greater than the second element
def greater(first_element, second_element):
    return first_element > second_element

# Helper method to check if the first element is greater than or equal to the second element
def greater_or_equal(first_element, second_element):
    return first_element >= second_element

# Helper method to print the given list to the standard output, separated by a space
def print(list_to_print):
    result = " ".join(str(element) for element in list_to_print)
    print(result)

# Helper method to print the given array to the standard output, enclosed in square brackets and separated by commas
def print(array):
    print(str(array))

# Helper method to flip the subarray from left to right in the given array
def flip(array, left, right):
    while left <= right:
        # Swaps the elements at the given indices
        array[left], array[right] = array[right], array[left]
        left += 1
        right -= 1

# Helper method to check if the given array is sorted in ascending order
def is_sorted(array):
    for i in range(1, len(array)):
        # Checks if the current element is less than the previous one
        if less(array[i], array[i - 1]):
            return False
    return True

# Helper method to check if the given list is sorted in ascending order
def is_sorted(list):
    for i in range(1, len(list)):
        # Checks if the current element is less than the previous one
        if less(list[i], list[i - 1]):
            return False
    return True

