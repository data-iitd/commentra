import numpy as np
from collections import deque
import heapq

# Read the number of nodes (N) and edges (M) from input
N, M = map(int, input().split())

# Initialize adjacency list for edges, degree count, parity, and visited flag
edges = [set() for _ in range(N)]
degs = [0 for i in range(N)]
parity = [0 for _ in range(N)]
flag = [False for _ in range(N)]

# Read edges and populate the adjacency list and degree counts
for _ in range(M):
    a, b = map(int, input().split())
    edges[a - 1].add(b - 1)  # Add edge from a to b
    edges[b - 1].add(a - 1)  # Add edge from b to a
    degs[a - 1] += 1          # Increment degree of node a
    degs[b - 1] += 1          # Increment degree of node b

# If the number of edges is odd, it's impossible to pair them
if M % 2 != 0:
    print(-1)
    exit()

# Initialize a priority queue with degrees of nodes
Q = []
for i, d in enumerate(degs):
    Q.append((d, i))  # Append degree and node index to the queue
heapq.heapify(Q)     # Transform the list into a heap

# Process the nodes in the priority queue
while len(Q) > 0:
    _, u = Q[0]        # Get the node with the smallest degree
    heapq.heappop(Q)  # Remove it from the queue

    # If the node has already been processed, skip it
    if flag[u]:
        continue

    flag[u] = True  # Mark the node as processed

    # Iterate through the neighbors of the current node
    for i, v in enumerate(edges[u]):
        edges[v].remove(u)  # Remove the edge from v to u
        # Check the parity to determine the output format
        if parity[u] != 0 and i == 0:
            print(u + 1, v + 1)  # Print the edge in one format
            parity[u] = 1 - parity[u]  # Toggle parity for u
        else:
            print(v + 1, u + 1)  # Print the edge in the alternate format
            parity[v] = 1 - parity[v]  # Toggle parity for v
        
        degs[v] -= 1  # Decrement the degree of neighbor v
        heapq.heappush(Q, (degs[v], v))  # Push updated degree back to the queue
