from itertools import chain
import numpy as np
import networkx as nx

# Read input data from standard input
X = iter(open(0).readlines())

# Parse the dimensions of the grid (height and width)
h, w = map(int, next(X).split())

# Initialize a 10x10 matrix to store weights (costs) for the graph
C = np.zeros((10, 10), dtype=int)

# Fill the cost matrix C with values from the input
for i in range(10):
    for j, c in enumerate(map(int, next(X).split())):
        C[i, j] = c

# Initialize a matrix A to represent the grid of values
A = np.zeros((h, w), dtype=int)

# Fill the grid A with values from the input
for i in range(h):
    for j, a in enumerate(map(int, next(X).split())):
        A[i, j] = a

# Create a directed graph G from the cost matrix C
G = nx.DiGraph(C)

# Dictionary to store shortest path lengths from each node to node 1
d = {}
for i in range(10):
    if i == 1:  # Skip node 1 as we are calculating distances to it
        continue
    # Calculate the shortest path length from node i to node 1
    d[i] = nx.shortest_path_length(G, i, 1, weight='weight')

# Initialize a variable to accumulate the total cost
s = 0

# Iterate through all values in the grid A
for a in chain.from_iterable(A):
    # Skip values that are -1 or 1 as they are not considered in the sum
    if a == -1 or a == 1:
        continue
    # Add the shortest path length for the current value a to the total cost
    s += d[a]

# Print the total accumulated cost
print(s)
