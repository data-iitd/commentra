
# Import the required modules
import sys

# Create a list to store the elements
array = []

# Get the size of the array
n = int(input())

# Populate the array with user input
for i in range(n):
    array.append(int(input()))

# Get the indices to swap in the array
i, j = map(int, input().split())

# Swap the elements at the specified indices
array[i], array[j] = array[j], array[i]

# Print the array after the swap operation
print(*array)

# Check if the array is sorted and print the result
sorted = True
for i in range(1, len(array)):
    if array[i] < array[i - 1]:
        sorted = False
        break
print(sorted)

# Get the indices for the flip operation
left, right = map(int, input().split())

# Flip the elements in the array between the specified indices
array[left:right + 1] = array[left:right + 1][::-1]

# Print the array after the flip operation
print(*array)

# End of code
