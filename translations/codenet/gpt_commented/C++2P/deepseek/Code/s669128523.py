# Depth First Search (DFS) implementation
# This implementation does not use recursion stack.

# Define constants for maximum number of nodes and colors
N = 100  # Maximum number of nodes
WHITE = 0  # Color for unvisited nodes
GRAY = 1  # Color for nodes being visited
BLACK = 2  # Color for fully visited nodes

# Adjacency matrix to represent the graph, number of nodes, and arrays for DFS
n = 0  # number of nodes
M = [[0] * N for _ in range(N)]  # adjacency matrix
color = [WHITE] * N  # array to store colors
d = [0] * N  # array to store discovery times
f = [0] * N  # array to store finish times
tt = 0  # time counter

# Function to visit nodes in DFS
def dfs_visit(u):
    global tt
    # Mark the current node as being visited
    color[u] = GRAY
    # Set the discovery time for the current node
    d[u] = tt + 1
    tt += 1

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
    f[u] = tt + 1
    tt += 1

# Function to perform DFS on the graph
def dfs():
    global tt
    # Initialize all nodes as unvisited
    for i in range(n):
        color[i] = WHITE
    tt = 0  # Reset the time counter

    # Perform DFS for each unvisited node
    for u in range(n):
        if color[u] == WHITE:
            dfs_visit(u)

    # Output the discovery and finish times for each node
    for i in range(n):
        print(f"{i + 1} {d[i]} {f[i]}")

# Main function to read input and perform DFS
if __name__ == "__main__":
    # Read the number of nodes
    n = int(input())
    # Read the graph edges
    for i in range(n):
        u, k = map(int, input().split())
        u -= 1  # Convert to zero-based index
        for _ in range(k):
            v = int(input())
            v -= 1  # Convert to zero-based index
            M[u][v] = 1  # Mark the edge in the adjacency matrix

    # Perform DFS on the graph
    dfs()
