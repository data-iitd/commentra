MAX = 101  # Define the maximum number of vertices
WHITE = 0  # Color constant for unvisited nodes
BLACK = 2  # Color constant for fully explored nodes
GRAY = 1   # Color constant for nodes currently being explored

time = 0
n = 0
g = [[0] * MAX for _ in range(MAX)]  # Adjacency matrix
d = [0] * MAX  # Discovery times
f = [0] * MAX  # Finish times
color = [WHITE] * MAX  # Colors of nodes

# Function to perform DFS visit on a node
def visit(u):
    global time
    color[u] = GRAY  # Mark the node as being explored
    time += 1
    d[u] = time  # Set the discovery time for the node

    # Explore all adjacent nodes
    for i in range(n):
        if g[u][i] == 0:  # If there is no edge to node i, skip
            continue
        if color[i] == WHITE:  # If the adjacent node is unvisited
            visit(i)  # Recursively visit the adjacent node

    color[u] = BLACK  # Mark the node as fully explored
    time += 1
    f[u] = time  # Set the finish time for the node

# Function to perform Depth-First Search on the graph
def dfs():
    global time
    time = 0  # Initialize time counter

    # Visit all nodes in the graph
    for i in range(n):
        if color[i] == WHITE:  # If the node is unvisited
            visit(i)  # Start a DFS visit

    # Print the discovery and finish times for each node
    for i in range(n):
        print(i + 1, d[i], f[i])  # Output: node index, discovery time, finish time

if __name__ == "__main__":
    # Read the number of vertices
    n = int(input())

    # Read the graph edges
    for i in range(n):
        x, y = map(int, input().split())  # Read the node and the number of edges
        for j in range(y):
            z = int(input())  # Read each adjacent node
            g[x - 1][z - 1] = 1  # Update the adjacency matrix

    # Perform DFS on the graph
    dfs()

# <END-OF-CODE>
