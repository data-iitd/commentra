#include <iostream>
#include <vector>

using namespace std;

# Declare a graph represented as an adjacency list
G = [[] for _ in range(100000)]
# Array to track visited nodes during DFS
used = [False] * 100000
# Array to store the Grundy values for each node
grundy = [0] * 100000

# Depth-First Search (DFS) function to compute Grundy values
def dfs(v):
    # Mark the current node as visited
    used[v] = True
    # Initialize the Grundy value for the current node
    grundy[v] = 0
    
    # Iterate through all adjacent nodes
    for i in range(len(G[v])):
        # If the adjacent node has not been visited
        if not used[G[v][i]]:
            # Recursively perform DFS on the adjacent node
            dfs(G[v][i])
            # Update the Grundy value using the Grundy value of the child node
            grundy[v] ^= (grundy[G[v][i]] + 1)

# Read the number of nodes in the graph
N = int(input())

# Read the edges of the graph
for i in range(N-1):
    x, y = map(int, input().split())
    # Convert to zero-based indexing
    x -= 1
    y -= 1
    # Add the edge to the adjacency list
    G[x].append(y)
    G[y].append(x)

# Start DFS from the root node (node 0)
dfs(0)

# Determine the winner based on the Grundy value of the root node
if grundy[0] != 0:
    print("Alice") # Alice wins if Grundy value is non-zero
else:
    print("Bob")   # Bob wins if Grundy value is zero

