#include <stdio.h>

#define N 200          # Maximum number of nodes
#define SHIRO 0       # Color constant for unvisited nodes
#define HAI 1         # Color constant for visiting nodes
#define KURO 2        # Color constant for visited nodes

# Function prototypes
def aaaaa():         # Function to perform depth-first search (DFS) and print discovery and finishing times
    int u, k, v      # Variables for input: u = node, k = number of edges, v = adjacent node
    int i, j        # Loop counters

    # Read the number of nodes
    scanf("%d", &n)

    # Initialize the adjacency matrix to zero (no edges)
    for i in range(n):
        for j in range(n):
            A[i][j] = 0

    # Read the edges for each node
    for i in range(n):
        scanf("%d %d", &u, &k) # Read node u and number of edges k
        u-- # Convert to zero-based index
        for j in range(k):
            scanf("%d", &v) # Read each adjacent node v
            v-- # Convert to zero-based index
            A[u][v] = 1 # Mark the edge in the adjacency matrix

    # Call the DFS function to process the graph
    aaaaa()

    return 0 # Exit the program

# Function to perform DFS and initialize variables
def aaaaa():
    int u, i

    # Initialize all nodes to unvisited (SHIRO)
    for i in range(n):
        color[i] = SHIRO

    TT = 0 # Reset the time counter

    # Perform DFS for each unvisited node
    for u in range(n):
        if color[u] == SHIRO:
            bbbbb(u) # Call DFS for the unvisited node

    # Print the discovery and finishing times for each node
    for i in range(n):
        printf("%d %d %d\n", i + 1, d[i], f[i]) # Output format: node index, discovery time, finishing time

# Recursive function to visit nodes in DFS
def bbbbb(k):
    int v
    color[k] = HAI # Mark the current node as visiting (HAI)
    TT++ # Increment the time counter
    d[k] = TT # Set the discovery time for the current node

    # Visit all adjacent nodes
    for v in range(n):
        if A[k][v] == 0: continue # Skip if there is no edge
        if color[v] == SHIRO: # If the adjacent node is unvisited
            bbbbb(v) # Recursively visit the adjacent node

    color[k] = KURO # Mark the current node as visited (KURO)
    f[k] = ++TT # Set the finishing time for the current node


