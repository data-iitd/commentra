# Import necessary modules
import sys
from collections import deque

# Function to read input
input = sys.stdin.buffer.readline

# Define number of vertices in the graph
N = int(input())

# Initialize adjacency list with empty lists for each vertex
adj = [ [ ] for _ in range(N + 1) ]

# Read edges and add them to the adjacency list
for _ in range(N - 1):
    a, b = map(int, input().split())
    # Add edge between vertices a and b in both directions
    adj[a].append(b)
    adj[b].append(a)

# Initialize empty deque for BFS traversal
que = deque()

# Mark starting vertex as visited and add it to the queue
que.append(1)

# Initialize lists to store parent, seen, and child count for each vertex
seen = [0] * (N + 1)
par = [0] * (N + 1)
child_num = [0] * (N + 1)

# BFS traversal starting from the starting vertex
while que:
    v = que.popleft()
    # Iterate through neighbors of the current vertex
    for u in adj[v]:
        # If neighbor is not yet visited, mark it as visited, update parent and child count
        if seen[u] == 0:
            seen[u] = 1
            par[u] = v
            child_num[v] += 1
            que.append(u)

# Initialize empty deque for storing vertices in topological order
seq = deque()

# Find vertices with no incoming edges and add them to the sequence
for i in range(1, N + 1):
    if child_num[i] == 0:
        seq.append(i)

# Topological sort using the sequence of vertices with no incoming edges
while seq:
    c = seq.pop()
    # If parent of the current vertex is not yet processed, print "First" and exit
    if seen[par[c]] == 0:
        print("First")
        exit()
    # Mark parent as not visited and update child count of its parent
    seen[par[c]] = 0
    child_num[par[par[c]]] -= 1
    # If the parent of the parent has no children, add it to the sequence
    if child_num[par[par[c]]] == 0:
        seq.append(par[par[c]])

# Print "Second" if all vertices have been processed
print("Second")
