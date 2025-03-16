#include <stdio.h>

#define N 200          # Maximum number of nodes
#define SHIRO 0       # Color constant for unvisited nodes
#define HAI 1         # Color constant for visiting nodes
#define KURO 2        # Color constant for visited nodes

# Function prototypes
def aaaaa():         # Function to perform depth-first search (DFS) and print discovery and finishing times
    global n, A, color, d, f, TT
    u, k, v = 0, 0, 0 # Variables for input: u = node, k = number of edges, v = adjacent node
    i, j = 0, 0       # Loop counters

    # Read the number of nodes
    n = int(input())

    # Initialize the adjacency matrix to zero (no edges)
    for i in range(n):
        for j in range(n):
            A[i][j] = 0

    # Read the edges for each node
    for i in range(n):
        u, k = map(int, input().split()) # Read node u and number of edges k
        u -= 1 # Convert to zero-based index
        for j in range(k):
            v = int(input()) # Read each adjacent node v
            v -= 1 # Convert to zero-based index
            A[u][v] = 1 # Mark the edge in the adjacency matrix

    # Call the DFS function to process the graph
    aaaaa()

    return 0 # Exit the program

# Recursive function to visit nodes in DFS
def bbbbb(k):
    global n, A, color, d, f, TT
    v = 0

    color[k] = HAI # Mark the current node as visiting (HAI)
    TT += 1 # Increment the time counter
    d[k] = TT # Set the discovery time for the current node

    # Visit all adjacent nodes
    for v in range(n):
        if A[k][v] == 0: continue # Skip if there is no edge
        if color[v] == SHIRO: # If the adjacent node is unvisited
            bbbbb(v) # Recursively visit the adjacent node

    color[k] = KURO # Mark the current node as visited (KURO)
    f[k] = TT + 1 # Set the finishing time for the current node

if __name__ == "__main__":
    n, A, color, d, f, TT = [0] * 6 # Global variables
    aaaaa() # Call the DFS function to process the graph

