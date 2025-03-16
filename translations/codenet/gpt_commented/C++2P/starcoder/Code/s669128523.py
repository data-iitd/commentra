# Depth First Search (DFS) implementation
# This implementation does not use recursion stack.

# Define constants for maximum number of nodes and colors
N = 100 # Maximum number of nodes
WHITE = 0 # Color for unvisited nodes
GRAY = 1 # Color for nodes being visited
BLACK = 2 # Color for fully visited nodes

# Adjacency matrix to represent the graph, number of nodes, and arrays for DFS
M = [[0 for i in range(N)] for j in range(N)] # M is the adjacency matrix, n is the number of nodes
color = [WHITE for i in range(N)] # Array to store colors
d = [0 for i in range(N)] # Array to store discovery times
f = [0 for i in range(N)] # Array to store finish times
tt = 0 # Time counter

# Function to visit nodes in DFS
def dfs_visit(u):
    global tt
    v = 0 # Initialize the adjacent node to zero
    # Mark the current node as being visited
    color[u] = GRAY
    # Set the discovery time for the current node
    d[u] = tt = tt + 1

    # Explore all adjacent nodes
    for v in range(n):
        # Skip if there is no edge from u to v
        if M[u][v] == 0:
            continue
        # If the adjacent node is unvisited, recursively visit it
        if color[v] == WHITE:
            dfs_visit(v)
    # Mark the current node as fully visited
    color[u] = BLACK
    # Set the finish time for the current node
    f[u] = tt = tt + 1

# Function to perform DFS on the graph
def dfs():
    global n
    u = 0 # Initialize the node to zero
    # Initialize all nodes as unvisited
    for i in range(n):
        color[i] = WHITE
    tt = 0 # Reset the time counter

    # Perform DFS for each unvisited node
    for u in range(n):
        if color[u] == WHITE:
            dfs_visit(u)

    # Output the discovery and finish times for each node
    for i in range(n):
        print(i+1, d[i], f[i])

# Read the number of nodes
n = int(input())
# Initialize the adjacency matrix to zero
for i in range(n):
    for j in range(n):
        M[i][j] = 0
# Read the graph edges
for i in range(n):
    u, k = map(int, input().split()) # Read the node and number of edges
    u -= 1 # Convert to zero-based index
    for j in range(k):
        v = int(input()) - 1 # Read each adjacent node
        v -= 1 # Convert to zero-based index
        M[u][v] = 1 # Mark the edge in the adjacency matrix

# Perform DFS on the graph
dfs()    

# 