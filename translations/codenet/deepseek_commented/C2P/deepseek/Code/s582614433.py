import sys

# Define a long long integer type for convenience
# Define a macro for a simple loop
# Define a macro for a loop with a step
# Define a large number to represent infinity
# Define a macro to get the maximum of two values
# Define a macro to get the minimum of two values
# Define a macro to check if a bit is set in a number
# Function to sort in ascending order
# Function to sort in descending order
# Function to sort an array of long long values in ascending order using qsort
# Function to sort an array of long long values in descending order using qsort
# Function to perform modular exponentiation
# Define a modulo value
# Function to compute the modular multiplicative inverse
# Define a structure to hold edge information
# Function to sort edges based on the string and then by the long long value
# Array to hold edge data
# Variables to hold the number of edges
# Main function

n = int(input())
data = []

# Read each edge's string and long long value, and store the index
for i in range(n):
    s, p = input().split()
    p = int(p)
    data.append((s, p, i))

# Sort the edges based on the string and then by the long long value
data.sort(key=lambda x: (x[0], -x[1]))

# Print the indices of the edges in the sorted order
for item in data:
    print(item[2] + 1)

