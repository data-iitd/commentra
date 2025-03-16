# Import necessary libraries
import numpy as np  # For numerical computations
from collections import deque  # For implementing a double ended queue
import heapq  # For implementing a min heap

# Take input number of vertices N and number of edges M
N, M = map(int, input().split())

# Initialize empty sets for each vertex representing its adjacent vertices
edges = [set() for _ in range(N)]

# Initialize degree array to keep track of number of edges for each vertex
degs = [0 for i in range(N)]

# Initialize parity array to keep track of parity of each vertex
parity = [0 for _ in range(N)]

# Initialize flag array to keep track of visited vertices
flag = [False for _ in range(N)]

# Read edges from input and add them to their respective sets and update their degrees
for _ in range(M):
    a, b = map(int, input().split())
    # Add edge between vertices a and b in both their sets
    edges[a-1].add(b-1)
    edges[b-1].add(a-1)
    # Update degrees of both vertices
    degs[a-1] += 1
    degs[b-1] += 1

# Check if number of edges is even, if not print -1 and exit
if M % 2 != 0:
    print(-1)
    exit()

# Initialize empty list Q to store vertices based on their degrees
Q = []

# Iterate through all vertices and add them to Q based on their degrees
for i, d in enumerate(degs):
    Q.append((d, i))

# Heapify Q to get vertices with minimum degrees first
heapq.heapify(Q)

# Iterate through Q until it is empty
while len(Q) > 0:
    # Get vertex with minimum degree from Q
    _, u = Q[0]
    heapq.heappop(Q)
    # Skip if vertex is already visited
    if flag[u]:
        continue
    # Mark vertex as visited
    flag[u] = True
    # Iterate through all adjacent vertices and print their edges and update their parity
    for i, v in enumerate(edges[u]):
        # Skip if vertex is already visited
        if flag[v]:
            continue
        # Print edge and update parity of both vertices
        if parity[u] != 0 and i == 0:
            print(u+1, v+1)
            parity[u] = 1 - parity[u]
        else:
            print(v+1, u+1)
            parity[v] = 1 - parity[v]
        # Decrease degree of adjacent vertex and add it to Q
        degs[v] -= 1
        heapq.heappush(Q, (degs[v], v))
