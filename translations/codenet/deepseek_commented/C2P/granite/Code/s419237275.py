
import sys

# Function prototypes
def aaaaa():
    pass

def bbbbb(k):
    pass

# Read the number of nodes
n = int(input())

# Initialize the adjacency matrix to zero
A = [[0 for _ in range(n)] for _ in range(n)]

# Read the edges for each node and update the adjacency matrix
for _ in range(n):
    u, k = map(int, input().split())
    u -= 1  # Adjust for 0-based indexing
    for _ in range(k):
        v = int(input()) - 1  # Adjust for 0-based indexing
        A[u][v] = 1

# Perform DFS and print the results
aaaaa()

# Print the discovery and finish times for each node
for i in range(n):
    print(f"{i + 1} {d[i]} {f[i]}")

