
import sys
import math

# Reading the number of elements in the array from the standard input
n = int(input())

# Creating an integer array of size 3 times the number of elements
array = [0] * (3 * n)

# Initializing the array with input values
for i in range(0, array.length):
    array[i] = int(input())

# Sorting the array in ascending order
array.sort()

head = array.length - 2  # Index of the last element to be considered in the current iteration
res = 0  # Result variable to store the sum of the last two elements in each subarray

# Calculating the sum of the last two elements in each subarray of size n and adding it to the result
for i in range(0, n):
    res += array[head]  # Adding the last element of the current subarray to the result
    head -= 2  # Decreasing the index of the last element by 2 to consider the next subarray

# Printing the result
print(res)

