import sys
from collections import defaultdict

# Number of nodes in the graph
n = int(input().strip())

# Adjacency list representation of the graph, where each node points to a list of edges
g = defaultdict(list)

# List to store the answer for each edge
ans = []

# Read edges and populate the adjacency list
for i in range(n - 1):
    # Read the two endpoints of the edge, adjusting for 0-based indexing
    a, b = map(int, input().strip().split())
    # Add the edge to both endpoints' adjacency lists
    g[a - 1].append((i, b - 1))
    g[b - 1].append((i, a - 1))

# Initialize the answer array to store results for each edge
ans = [0] * (n - 1)

# Perform a depth-first search starting from node 0
def dfs(to, color, parents):
    k = 1
    for e in g[to]:
        # Skip the edge leading back to the parent node
        if e[1] == parents:
            continue
        # If the current color is the same as the edge color, increment it
        if k == color:
            k += 1
        # Assign the color to the edge
        ans[e[0]] = k
        # Recursively call dfs for the connected node
        dfs(e[1], k, to)
        k += 1  # Increment color for the next edge

dfs(0, -1, -1)

# Find the maximum value in the ans array
max_val = max(ans)

# Output the maximum value found
print(max_val)

# Output the results for each edge
for c in ans:
    print(c)
