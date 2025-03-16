import numpy as np
from collections import deque
import heapq

# Step 1: Input Reading and Initialization
# Read the number of nodes N and the number of edges M
N, M = map(int, input().split())

# Initialize adjacency lists for each node
edges = [set() for _ in range(N)]

# Initialize degrees for each node
degs = [0 for _ in range(N)]

# Initialize parity for each node
parity = [0 for _ in range(N)]

# Initialize flag to mark visited nodes
flag = [False for _ in range(N)]

# Step 2: Edge and Degree Calculation
# Read each edge and update adjacency lists and degree lists
for _ in range(M):
    a, b = map(int, input().split())
    edges[a - 1].add(b - 1)
    edges[b - 1].add(a - 1)
    degs[a - 1] += 1
    degs[b - 1] += 1

# If the number of edges M is odd, print -1 and exit
if M % 2 != 0:
    print(-1)
    exit()

# Step 3: Heap Initialization
# Initialize a heap Q with nodes based on their degrees
Q = []
for i, d in enumerate(degs):
    Q.append((d, i))
heapq.heapify(Q)

# Step 4: Main Loop
# Process nodes from the heap
while len(Q) > 0:
    _, u = Q[0]
    heapq.heappop(Q)
    
    # If the node has already been processed, skip to the next iteration
    if flag[u]:
        continue
    
    # Mark the node as processed
    flag[u] = True
    
    # For each neighbor of the node, update the adjacency list and degree list
    for v in edges[u]:
        edges[v].remove(u)
        
        # Print the edge in the required format, alternating the direction based on the parity
        if parity[u] != 0:
            print(u + 1, v + 1)
            parity[u] = 1 - parity[u]
        else:
            print(v + 1, u + 1)
            parity[v] = 1 - parity[v]
        
        # Update the degree and push the updated node back into the heap
        degs[v] -= 1
        heapq.heappush(Q, (degs[v], v))

# Step 5: Output
# The code prints the edges in the required format, alternating the direction based on the parity
