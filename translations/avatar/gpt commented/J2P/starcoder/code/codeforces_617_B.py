import sys

# Reading an integer n from user input, which represents the number of elements
n = int(input())

# Initializing a list to store the indices of elements that are equal to 1
arr = []

# Looping through the input values to find indices of elements equal to 1
for i in range(n):
    # If the input value is 1, add the current index to the list
    if int(input()) == 1:
        arr.append(i)

# Checking if the list of indices is empty
if len(arr) == 0:
    # If the list is empty, print 0
    print(0)
else:
    # If the list is not empty, initialize a result variable to 1
    result = 1

    # Calculate the product of the differences between consecutive indices
    for i in range(1, len(arr)):
        result *= arr[i] - arr[i - 1]

    # Print the final result
    print(result)

# 