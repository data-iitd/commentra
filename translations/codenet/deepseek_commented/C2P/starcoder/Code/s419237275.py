#include <stdio.h>

#define N 200  # Maximum number of nodes in the graph
#define SHIRO 0  # Color representing unvisited nodes
#define HAI 1  # Color representing nodes currently in the recursion stack
#define KURO 2  # Color representing nodes fully processed

# Function prototypes
def aaaaa():
def bbbbb(k):

n, A = int(input()), []  # n: number of nodes, A: adjacency matrix
for i in range(n):
    A.append([0] * n)

# Read the edges for each node and update the adjacency matrix
for i in range(n):
    u, k = map(int, input().split())
    u -= 1  # Adjust for 0-based indexing
    for j in range(k):
        v = int(input())
        v -= 1  # Adjust for 0-based indexing
        A[u][v] = 1

# Initialize all nodes to "SHIRO" (unvisited)
color = [SHIRO] * n

# Set the time counter to zero
TT = 0

# Iterate over all nodes and perform DFS if the node is "SHIRO"
for u in range(n):
    if color[u] == SHIRO:
        bbbbb(u)

# Print the discovery and finish times for each node
for i in range(n):
    print(i + 1, d[i], f[i])

# Depth-First Search (DFS) function
def aaaaa():

# Recursive DFS function
def bbbbb(k):

# Iterate over all nodes and perform DFS recursively if an adjacent node is "SHIRO"
for v in range(n):
    if A[k][v] == 0: continue  # Skip if no edge between k and v
    if color[v] == SHIRO:
        bbbbb(v)

# Set the current node's color to "KURO" (fully processed)
color[k] = KURO
# Record the finish time
f[k] = ++TT

# 