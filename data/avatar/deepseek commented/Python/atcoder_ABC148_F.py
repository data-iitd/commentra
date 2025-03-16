from collections import Counter, defaultdict, deque
from heapq import heappop, heappush, heapify
import sys, bisect, math, itertools, pprint, fractions
sys.setrecursionlimit(10 ** 8)
mod = 10 ** 9 + 7
INF = float('inf')

# Function to read an integer from standard input
def inp():
    return int(sys.stdin.readline())

# Function to read a list of integers from standard input
def inpl():
    return list(map(int, sys.stdin.readline().split()))

# Read the number of nodes, starting node for Ta, and starting node for Ao
n, ta, ao = inpl()

# Adjust indices to be zero-based
ta -= 1
ao -= 1

# Initialize the graph as a list of lists, each representing adjacency list of a node
g = [[] for i in range(n)]

# Read edges to construct the graph
for i in range(n - 1):
    a, b = inpl()
    g[a - 1].append(b - 1)  # Append the zero-based index of the neighbor
    g[b - 1].append(a - 1)  # Append the zero-based index of the neighbor

# Initialize distance arrays to None, will be populated during DFS
ta_dist = [None] * n
ta_dist[ta] = 0  # Distance from Ta to Ta is 0
ao_dist = [None] * n
ao_dist[ao] = 0  # Distance from Ao to Ao is 0

# Depth-First Search (DFS) function to compute distances from Ta
def ta_dfs(node):
    for v in g[node]:
        if ta_dist[v] is not None:  # If already visited, skip
            continue
        ta_dist[v] = ta_dist[node] + 1  # Update distance
        ta_dfs(v)  # Recursively visit neighbors

# Depth-First Search (DFS) function to compute distances from Ao
def ao_dfs(node):
    for v in g[node]:
        if ao_dist[v] is not None:  # If already visited, skip
            continue
        ao_dist[v] = ao_dist[node] + 1  # Update distance
        ao_dfs(v)  # Recursively visit neighbors

# Start DFS from Ao to compute distances
ao_dfs(ao)

# Start DFS from Ta to compute distances
ta_dfs(ta)

# Initialize result variable
res = 0

# Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
for i in range(n):
    if ta_dist[i] > ao_dist[i]:  # Skip if Ta's distance is greater
        continue
    res = max(res, ao_dist[i])  # Update result with the maximum distance

# Print the result, which is the maximum distance minus one
print(res - 1)
