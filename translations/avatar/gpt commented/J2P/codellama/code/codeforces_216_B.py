import sys

# Variable to count the number of nodes in the current DFS traversal
count = 0
# Array to track which nodes have been visited
seen = [False] * (int(sys.stdin.readline()) + 1)
# Constants to represent the state of the traversal
path = 0
cycle = 1
# Adjacency list representation of the graph
graph = [[] for _ in range(int(sys.stdin.readline()) + 1)]

# Depth-First Search (DFS) method to explore the graph
def dfs(child, par):
    # If the current node has already been seen, return cycle indicator
    if seen[child]:
        return cycle
    # Mark the current node as seen
    seen[child] = True
    
    # Iterate through all adjacent nodes of the current node
    for i in graph[child]:
        # Avoid going back to the parent node
        if i != par:
            global count
            count += 1 # Increment the count of nodes visited
            # Recursively call DFS on the adjacent node
            if dfs(i, child) == cycle: # Check for cycles
                return cycle
    # Return path indicator if no cycle is found
    return path

# Read the number of nodes (m) and edges (n)
m, n = map(int, sys.stdin.readline().split())

# Read the edges and populate the graph
for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    # Add the edge in both directions (undirected graph)
    graph[x].append(y)
    graph[y].append(x)

# Variable to count the number of nodes to remove
toremove = 0

# Iterate through all nodes to check for unvisited nodes
for i in range(1, m + 1):
    # If the node has not been seen, perform DFS
    if not seen[i]:
        count = 0 # Reset count for the new component
        # Check if the DFS from this node finds a cycle
        if dfs(i, 0) == cycle:
            # If a cycle is found and the count of nodes is odd, increment toremove
            if count % 2 == 1:
                toremove += 1

# Adjust the number of nodes to remove if the remaining nodes are odd
if (m - toremove) % 2 == 1:
    toremove += 1

# Output the result: number of nodes to remove
print(toremove)

