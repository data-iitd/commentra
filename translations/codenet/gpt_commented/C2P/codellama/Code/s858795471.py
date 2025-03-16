#include <stdio.h>

# Function to search for a key in the array A of size n
def search(A, n, key):
    i = 0 # Initialize index to 0
    A[n] = key # Sentinel value: place the key at the end of the array
    # Loop until the key is found in the array
    while A[i] != key: i += 1 # Increment index until the key is found
    # Return true if the key was found before the sentinel, false otherwise
    return i != n

# Read the number of elements in the array
n = int(input())
# Read the elements of the array
A = [int(input()) for i in range(n)]

# Read the number of queries
q = int(input())
# Process each query
for i in range(q):
    key = int(input()) # Read the key to search for
    # If the key is found in the array, increment the sum
    if search(A, n, key): sum += 1

# Output the total count of found keys
print(sum)

# 