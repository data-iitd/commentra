
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#ifdef __cplusplus
#include <bits/stdc++.h>
#endif

# Function to read an integer from input
def nextint():
    c = getchar_unlocked() # Read a character
    # Skip non-digit characters until a digit or '-' is found
    while (c!= '-' and (c < '0' or '9' < c)):
        c = getchar_unlocked()
    s = False # Flag for negative numbers
    if (c == '-'): # Check for negative sign
        s = True
        c = getchar_unlocked() # Read the next character
    x = 0 # Variable to store the integer value
    # Convert characters to integer
    while ('0' <= c and c <= '9'):
        x = x * 10 + c - '0'
        c = getchar_unlocked()
    return s and -x or x # Return the integer value, negated if necessary

n = nextint() # Variable to store the number of nodes

# Function to calculate a unique identifier for a pair of nodes
def p(a, b):
    if (a < b):
        return a + b * n # Return a unique index based on the order of a and b
    else:
        return b + a * n # Return a unique index based on the order of a and b

a = [[0 for i in range(999)] for j in range(1000)] # Adjacency list representation of the graph

# Arrays to store edges and distances
e1 = [0 for i in range(1000000)]
e2 = [0 for i in range(1000000)]
d = [0 for i in range(1000000)] # Array to store computed distances
b = [False for i in range(1000000)] # Visited flag for nodes

# Recursive function to compute the maximum distance from a given node
def f(from):
    if (b[from]): return -1 # Return -1 if the node has already been visited (cycle detected)
    if (d[from]): return d[from] # Return the computed distance if already calculated
    b[from] = True # Mark the node as visited
    to = e1[from] # Get the first edge
    max = 0 # Variable to track the maximum distance
    if (to!= 0):
        now = f(to) # Recursively compute distance for the first edge
        if (now < 0): return now # Return if a cycle is detected
        if (now > max): max = now # Update max if a longer distance is found
    to = e2[from] # Get the second edge
    if (to!= 0):
        now = f(to) # Recursively compute distance for the second edge
        if (now < 0): return now # Return if a cycle is detected
        if (now > max): max = now # Update max if a longer distance is found
    b[from] = False # Unmark the node as visited for future calls
    return d[from] = max + 1 # Store and return the computed distance

ans = 0 # Variable to store the final answer
# Compute the maximum distance for each node
for i in range(n):
    from = p(i, a[i][0]) # Get unique index for the starting edge
    now = f(from) # Compute the distance
    if (now < 0):
        ans = -1 # Set answer to -1 if a cycle is detected
        break # Exit the loop
    if (now > ans): ans = now # Update the answer if a longer distance is found
print(ans) # Output the final answer

