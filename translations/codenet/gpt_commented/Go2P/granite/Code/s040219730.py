

import sys

# Read the number of elements and queries
n, q = map(int, input().split())
C = list(map(int, input().split())) # Read the slice of integers

# Initialize the position array with -1 (indicating unvisited)
P = [-1] * (n + 1)

# Read each query and store it in the Q slice
Q = []
for _ in range(q):
    l, r = map(int, input().split()) # Read the left and right bounds of the query
    Q.append((l, r)) # Append the query to the list

# Sort the queries based on the right bound
Q.sort(key=lambda x: x[1])

# Initialize a Fenwick Tree for range queries
ft = [0] * (n + 1) # Create the data array

k = 0 # Pointer to track the current position in the input array
# Process each query
for l, r in Q:
    # Update the Fenwick Tree for all elements up to the right bound of the current query
    for i in range(k, r):
        if P[C[i]]!= -1: # If the current value has been seen before
            ft[P[C[i]]] -= 1 # Decrease its previous occurrence in the Fenwick Tree
        P[C[i]] = i # Update the last position of the current value
        ft[i] += 1 # Add the current value to the Fenwick Tree

    # Calculate the answer for the current query using the Fenwick Tree
    ans = ft[r-1] - ft[l-2]
    print(ans) # Output the answer to stdout

    k = r # Move to the next position

