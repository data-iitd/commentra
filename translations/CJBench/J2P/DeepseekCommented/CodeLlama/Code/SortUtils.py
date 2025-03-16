
import sys

# Initialize Scanner to read input
scanner = sys.stdin

# Read the number of elements
n = int(scanner.readline().strip())

# Create an array to hold the integers
array = []

# Read the integers into the array
for i in range(n):
    array.append(int(scanner.readline().strip()))

# Read the indices for swapping
i, j = map(int, scanner.readline().strip().split())

# Swap the elements at indices i and j
swap(array, i, j)

# Print the array before and after swapping
print(array)

# Check if the array is sorted and print the result
sorted = isSorted(array)
print(sorted)

# Read the indices for flipping
left, right = map(int, scanner.readline().strip().split())

# Flip the subarray between the given indices
flip(array, left, right)

# Print the array after flipping
print(array)

# Close the Scanner
scanner.close()

# Generic method to swap elements in an array
def swap(array, i, j):
    if i != j:
        temp = array[i]
        array[i] = array[j]
        array[j] = temp

# Generic method to check if the first element is less than the second
def less(firstElement, secondElement):
    return firstElement < secondElement

# Generic method to check if the first element is greater than the second
def greater(firstElement, secondElement):
    return firstElement > secondElement

# Generic method to check if the first element is greater than or equal to the second
def greaterOrEqual(firstElement, secondElement):
    return firstElement >= secondElement

# Method to print elements of a list
def print(listToPrint):
    result = " ".join(map(str, listToPrint))
    print(result)

# Method to print elements of an array
def print(array):
    print(" ".join(map(str, array)))

# Method to flip a subarray in the array
def flip(array, left, right):
    while left <= right:
        swap(array, left, right)
        left += 1
        right -= 1

# Method to check if an array is sorted
def isSorted(array):
    for i in range(1, len(array)):
        if less(array[i], array[i - 1]):
            return False
    return True

# Method to check if a list is sorted
def isSorted(list):
    for i in range(1, len(list)):
        if less(list[i], list[i - 1]):
            return False
    return True

