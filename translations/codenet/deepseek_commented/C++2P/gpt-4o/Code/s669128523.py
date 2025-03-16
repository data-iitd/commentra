# Depth First Search in Python
N = 100  # Define the maximum number of nodes
WHITE = 0  # Define WHITE color
GRAY = 1  # Define GRAY color
BLACK = 2  # Define BLACK color

M = [[0] * N for _ in range(N)]  # Declare the adjacency matrix
n = int(input())  # Read the number of nodes
color = [WHITE] * N  # Initialize color array
d = [0] * N  # Discovery time
f = [0] * N  # Finish time
tt = 0  # Time counter

# Depth-first search visit function
def dfs_visit(u):
    global tt
    color[u] = GRAY  # Set the color of node u to GRAY
    tt += 1
    d[u] = tt  # Record the discovery time of u
    for v in range(n):
        if M[u][v] == 0:
            continue  # Skip if there is no edge from u to v
        if color[v] == WHITE:  # If v is WHITE, recursively visit v
            dfs_visit(v)
    color[u] = BLACK  # Set the color of node u to BLACK
    tt += 1
    f[u] = tt  # Record the finish time of u

# Depth-first search function
def dfs():
    global tt
    for i in range(n):
        color[i] = WHITE  # Initialize all nodes to WHITE
    tt = 0  # Reset the time counter

    for u in range(n):
        if color[u] == WHITE:  # If u is WHITE, start a DFS from u
            dfs_visit(u)

    for i in range(n):
        print(i + 1, d[i], f[i])  # Print the discovery and finish times for each node

# Read the adjacency matrix
for i in range(n):
    k = int(input())  # Read the number of neighbors
    for j in range(k):
        v = int(input()) - 1  # Read the neighbor and convert to 0-based index
        M[i][v] = 1  # Set the edge in the adjacency matrix

dfs()  # Perform the depth-first search and print the results

# <END-OF-CODE>
