import queue

# Read the number of nodes (n) and edges (m) from input
n, m = map(int, input().split())

# Initialize visitation status and counters for isolated components, bipartite components, and non-bipartite components
vis, ci, cb, cc = [0] * (n + 1), 0, 0, 0

# Create an adjacency list to represent the graph
g = [[] for i in range(n + 1)]

# Define a depth-first search (DFS) function to check for bipartiteness
def dfs(x):
    stk, flag = queue.LifoQueue(), True  # Initialize stack for DFS and a flag for bipartiteness
    stk.put((x, 1))  # Start DFS from node x with color 1
    while not stk.empty():
        u, col = stk.get()  # Get the current node and its color
        if vis[u]:  # If the node has already been visited
            flag &= (vis[u] == col)  # Check if the color matches
            continue
        vis[u] = col  # Mark the node as visited with the current color
        for i in g[u]:  # Iterate through all adjacent nodes
            stk.put((i, 3 - col))  # Push the adjacent node with the alternate color
    return flag  # Return whether the component is bipartite

# Read edges and build the graph
for i in range(m):
    u, v = map(int, input().split())
    g[u] += [v]  # Add edge from u to v
    g[v] += [u]  # Add edge from v to u (undirected graph)

# Iterate through all nodes to count isolated and bipartite components
for i in range(1, n + 1):
    if vis[i] == 0:  # If the node has not been visited
        if len(g[i]) == 0:  # Check if the node is isolated
            ci += 1  # Increment isolated component counter
        else:
            if dfs(i):  # Perform DFS and check if the component is bipartite
                cb += 1  # Increment bipartite component counter
            else:
                cc += 1  # Increment non-bipartite component counter

# Calculate and print the final result based on the counts of components
print(ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb)
