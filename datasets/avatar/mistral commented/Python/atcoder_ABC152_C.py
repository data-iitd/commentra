# Import the NumPy library for handling arrays
import numpy as np

# Get the number of elements in the array from user input
N = int(input())

# Initialize an empty NumPy array 'n' of size N
n = np.zeros(N, dtype=int)

# Get the elements of the array from user input and store them in 'n'
n = np.array([int(x) for x in input().split()])

# Initialize variables 'a' and 'pos'
a = 1
pos = 0

# Iterate through the array 'n' starting from the second element
for i in range(1, N):
    # Check if the current element is greater than the previous one
    if n[pos] > n[i]:
        # Increment the variable 'a' if the condition is true
        a += 1
        # Update the position of the previous greater element
        pos = i

# Print the value of 'a' as the output
print(a)
