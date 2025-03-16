from collections import Counter, defaultdict, deque
from heapq import heappop, heappush, heapify
import sys, bisect, math, itertools, pprint, fractions

# Set the recursion limit to a high value to handle deep recursions
sys.setrecursionlimit(10 ** 8)

# Define a large prime number for modular arithmetic
mod = 10 ** 9 + 7

# Define infinity for comparison purposes
INF = float('inf')

# Function to read a single integer from input
def inp(): 
    return int(sys.stdin.readline())

# Function to read a list of integers from input
def inpl(): 
    return list(map(int, sys.stdin.readline().split()))

# Read the number of nodes and the starting points for ta and ao
n, ta, ao = inpl()
ta -= 1  # Adjusting to zero-based index
ao -= 1  # Adjusting to zero-based index

# Initialize the graph as an adjacency list
g = [[] for i in range(n)]

# Read the edges of the graph and populate the adjacency list
for i in range(n - 1):
    a, b = inpl()
    g[a - 1].append(b - 1)  # Adjusting to zero-based index
    g[b - 1].append(a - 1)  # Adjusting to zero-based index

# Initialize distance arrays for ta and ao
ta_dist = [None] * n
ta_dist[ta] = 0  # Distance to itself is 0
ao_dist = [None] * n
ao_dist[ao] = 0  # Distance to itself is 0

# Depth-first search (DFS) function to calculate distances from ta
def ta_dfs(node):
    for v in g[node]:
        if ta_dist[v] is not None: 
            continue  # Skip if already visited
        ta_dist[v] = ta_dist[node] + 1  # Update distance
        ta_dfs(v)  # Recursive DFS call

# Depth-first search (DFS) function to calculate distances from ao
def ao_dfs(node):
    for v in g[node]:
        if ao_dist[v] is not None: 
            continue  # Skip if already visited
        ao_dist[v] = ao_dist[node] + 1  # Update distance
        ao_dfs(v)  # Recursive DFS call

# Perform DFS from ao to calculate distances
ao_dfs(ao)

# Perform DFS from ta to calculate distances
ta_dfs(ta)

# Initialize result variable to track the maximum distance
res = 0

# Calculate the maximum distance where ta's distance is less than or equal to ao's distance
for i in range(n):
    if ta_dist[i] > ao_dist[i]: 
        continue  # Skip if ta is further away than ao
    res = max(res, ao_dist[i])  # Update result with the maximum distance

# Print the result, subtracting 1 to adjust for zero-based indexing
print(res - 1)
