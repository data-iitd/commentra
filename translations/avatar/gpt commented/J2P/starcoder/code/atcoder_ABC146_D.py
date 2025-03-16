import sys

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
    g[a].append(b)
    g[b].append(a)

# Perform a depth-first search starting from node 0
dfs(0, -1, -1)

# Find the maximum value in the ans array
max = 0
for temp in ans:
    max = max if max > temp else temp

# Output the maximum value found
print(max)

# Output the results for each edge
for c in ans:
    print(c)

# 