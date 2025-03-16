from itertools import *  # Import all functions from the itertools module

# Read an integer input from the user
N = int(input())

# Initialize a variable x to 1
x = 1

# Create a list of integers from 2 to N+1 (inclusive)
N_list = [x + 1 for x in range(N)]

# Generate the Cartesian product of N_list with itself 3 times
n = list(product(N_list, repeat=3))

# Calculate the length of the resulting Cartesian product
m = len(n)

# Print the number of combinations generated
print(m)
