from itertools import chain
import numpy as np
import networkx as nx

# Reading Input:
# The code starts by reading the dimensions h and w of the grid from the first line of the input.
h, w = map(int, next(X).split())

# It then reads the cost matrix C of size 10x10 from the next 10 lines.
C = np.zeros((10, 10), dtype=int)
for i in range(10):
    for j, c in enumerate(map(int, next(X).split())):
        C[i, j] = c

# Next, it reads the grid A of size hxw from the subsequent lines.
A = np.zeros((h, w), dtype=int)
for i in range(h):
    for j, a in enumerate(map(int, next(X).split())):
        A[i, j] = a

# Creating a Graph:
# The code creates a directed graph G using the cost matrix C.
G = nx.DiGraph(C)

# It initializes an empty dictionary d to store the shortest path lengths from each node to node 1.
d = {}

# Calculating Shortest Paths:
# The code iterates over the nodes (0 to 9) and calculates the shortest path length from each node to node 1 using nx.shortest_path_length.
# It skips node 1 in this calculation.
for i in range(10):
    if i == 1:
        continue
    d[i] = nx.shortest_path_length(G, i, 1, weight='weight')

# Summing Up Costs:
# The code initializes a sum s to 0.
s = 0

# It iterates over all elements in the grid A and skips elements that are -1 or 1.
# For each valid element, it adds the corresponding shortest path length from d to s.
for a in chain.from_iterable(A):
    if a == -1 or a == 1:
        continue
    s += d[a]

# Output:
# Finally, the code prints the sum s.
print(s)
