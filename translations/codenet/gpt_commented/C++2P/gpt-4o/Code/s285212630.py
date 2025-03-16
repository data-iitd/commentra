import sys
from collections import defaultdict

# Constants for maximum levels
MAX_L = 22

# Global variables
N = 0  # Number of nodes in the tree
G = defaultdict(list)  # Adjacency list representation of the tree
U = [[-1] * 100000 for _ in range(MAX_L)]  # U for storing ancestors
R = [0] * 100000  # R for depth
L = [0] * 100000  # L for storing the distance from the root

# Depth-first search to initialize ancestor and depth information
def dfs(x, p, r, l):
    U[0][x] = p  # Set the parent of the current node
    R[x] = r  # Set the depth of the current node
    L[x] = l  # Set the distance from the root to the current node
    for t, weight in G[x]:  # Iterate through all adjacent nodes
        if t == p:
            continue  # Skip the parent node to avoid cycles
        dfs(t, x, r + 1, l + weight)  # Recursive DFS call for the child node

# Function to find the lowest common ancestor (LCA) of two nodes
def lca(a, b):
    if R[a] > R[b]:
        a, b = b, a  # Ensure a is the deeper node
    for k in range(MAX_L):  # Adjust b to the same depth as a
        if (R[a] - R[b]) >> k & 1:
            b = U[k][b]
    if a == b:
        return a  # If both nodes are the same, return a
    for k in range(MAX_L - 1, -1, -1):  # Find the LCA using binary lifting
        if U[k][a] != U[k][b]:
            a = U[k][a]
            b = U[k][b]
    return U[0][a]  # Return the parent of a, which is the LCA

# Function to calculate the distance between two nodes
def dist(x, y):
    g = lca(x, y)  # Find the LCA of x and y
    return L[x] + L[y] - 2 * L[g]  # Calculate the distance using LCA

def main():
    global N
    input = sys.stdin.read
    data = input().splitlines()
    
    N = int(data[0])  # Read the number of nodes
    for i in range(1, N):  # Read the edges of the tree
        a, b, c = map(int, data[i].split())  # Read nodes and weight
        a -= 1  # Convert to 0-based indexing
        b -= 1  # Convert to 0-based indexing
        G[a].append((b, c))  # Add edge to the adjacency list
        G[b].append((a, c))  # Add the reverse edge

    # Perform DFS from the root to fill ancestor and depth information
    dfs(0, -1, 0, 0)

    # Precompute ancestors for binary lifting
    for i in range(MAX_L - 1):
        for v in range(N):
            if U[i][v] != -1:
                U[i + 1][v] = U[i][U[i][v]]  # Set the 2^(i+1) ancestor

    Q, K = map(int, data[N].split())  # Read number of queries and node K
    K -= 1  # Convert K to 0-based indexing

    # Process each query
    results = []
    for i in range(N + 1, N + 1 + Q):
        x, y = map(int, data[i].split())  # Read the nodes
        x -= 1  # Convert to 0-based indexing
        y -= 1  # Convert to 0-based indexing
        # Output the total distance from x to K and K to y
        results.append(str(dist(x, K) + dist(K, y)))

    print("\n".join(results))  # Print all results

if __name__ == "__main__":
    main()

# <END-OF-CODE>
