
import sys
sys.setrecursionlimit(10**6)

# Number of nodes in the graph
n = int(input())

# Adjacency list representation of the graph, where each node points to a list of edges
g = [[] for _ in range(n)]

# Array to store the answer for each edge
ans = [0] * (n - 1)

# Read edges and populate the adjacency list
for i in range(n - 1):
    # Read the two endpoints of the edge, adjusting for 0-based indexing
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    # Add the edge to both endpoints' adjacency lists
    g[a].append((i, b))
    g[b].append((i, a))

# Perform a depth-first search starting from node 0
def dfs(to, color, parents):
    k = 1  # Start coloring with color 1
    for i, e in enumerate(g[to]):
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

