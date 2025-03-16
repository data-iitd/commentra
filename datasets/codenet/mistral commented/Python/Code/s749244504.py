# Import necessary libraries
from itertools import chain
import numpy as np
import networkx as nx

# Read input file line by line
X = iter(open(0).readlines())

# Read first line to get dimensions h and w
h, w = map(int, next(X).split())

# Initialize 10x10 2D numpy array C with zeros
C = np.zeros((10, 10), dtype=int)

# Iterate through each row and column of C to read its values from input file
for i in range(10):
    for j, c in enumerate(map(int, next(X).split())):
        # Set the value of C[i, j] to the read integer value
        C[i, j] = c

# Initialize hxwx 2D numpy array A with zeros
A = np.zeros((h, w), dtype=int)

# Iterate through each row and column of A to read its values from input file
for i in range(h):
    for j, a in enumerate(map(int, next(X).split())):
        # Set the value of A[i, j] to the read integer value
        A[i, j] = a

# Create a directed graph G from the adjacency matrix C
G = nx.DiGraph(C)

# Initialize dictionary d to store shortest path lengths from node 1 to all other nodes
d = {}

# Iterate through all nodes except node 1 to calculate their shortest path lengths
for i in range(1, 10):
    # Calculate shortest path length from node 1 to node i using Dijkstra's algorithm
    d[i] = nx.shortest_path_length(G, i, 1, weight='weight')

# Initialize variable s to store the sum of shortest path lengths from all nodes in A to node 1
s = 0

# Iterate through all elements in A to calculate their shortest path lengths to node 1 and add them to variable s
for a in chain.from_iterable(A):
    # If a is -1 or 1, skip it as it doesn't represent a valid node
    if a == -1 or a == 1:
        continue
    # Calculate shortest path length from node a to node 1 and add it to variable s
    s += d[a]

# Print the final result, which is the sum of shortest path lengths from all nodes in A to node 1
print(s)