
import sys

# Taking input from user for the size of the array
a = int(input("Enter the size of the array: "))

# Initializing array with user input
ar = [int(x) for x in input("Enter the elements of the array separated by space: ").split()]

# Initializing variables for storing maximum and minimum differences
max = 0
min = 0

# Finding maximum and minimum differences between consecutive elements in the array
for i in range(len(ar)):
    # Finding maximum difference between current element and first element
    max = max(ar[i] - ar[0], ar[-1] - ar[i])

    # Finding minimum difference between current element and previous element
    if i == 0:
        min = ar[i + 1] - ar[i]  # For the first element, minimum difference is between current and next element
    elif i == len(ar) - 1:
        min = ar[i] - ar[i - 1]  # For the last element, minimum difference is between current and previous element
    else:
        min = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])  # For other elements, minimum difference is between current and previous or next element, whichever is smaller

    # Printing minimum and maximum differences for each pair of consecutive elements
    print(min, max)

