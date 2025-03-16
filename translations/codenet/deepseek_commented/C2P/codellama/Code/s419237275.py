#include <stdio.h>

#define N 200  # Maximum number of nodes in the graph
#define SHIRO 0  # Color representing unvisited nodes
#define HAI 1  # Color representing nodes currently in the recursion stack
#define KURO 2  # Color representing nodes fully processed

# Function prototypes
def aaaaa():
    pass

def bbbbb(k):
    pass

n = 0  # n: number of nodes, A: adjacency matrix
A = [[0 for i in range(N)] for j in range(N)]  # Initialize the adjacency matrix to zero
color = [SHIRO for i in range(N)]  # color: color of each node, d: discovery time, f: finish time
d = [0 for i in range(N)]
f = [0 for i in range(N)]
TT = 0  # Time counter

# Read the number of nodes
n = int(input())

# Read the edges for each node and update the adjacency matrix
for i in range(n):
    u, k = map(int, input().split())
    u -= 1  # Adjust for 0-based indexing
    for j in range(k):
        v = int(input()) - 1  # Adjust for 0-based indexing
        A[u][v] = 1

# Perform DFS and print the results
aaaaa()

# Depth-First Search (DFS) function
def aaaaa():
    # Initialize all nodes to "SHIRO" (unvisited)
    for i in range(n):
        color[i] = SHIRO

    # Set the time counter to zero
    TT = 0

    # Iterate over all nodes and perform DFS if the node is "SHIRO"
    for u in range(n):
        if color[u] == SHIRO:
            bbbbb(u)

    # Print the discovery and finish times for each node
    for i in range(n):
        print(i + 1, d[i], f[i])

# Recursive DFS function
def bbbbb(k):
    # Set the current node's color to "HAI" (currently in the recursion stack)
    color[k] = HAI
    # Increment the time counter and record the discovery time
    TT += 1
    d[k] = TT

    # Iterate over all nodes and perform DFS recursively if an adjacent node is "SHIRO"
    for v in range(n):
        if A[k][v] == 0:
            continue  # Skip if no edge between k and v
        if color[v] == SHIRO:
            bbbbb(v)

    # Set the current node's color to "KURO" (fully processed)
    color[k] = KURO
    # Record the finish time
    f[k] = TT + 1


