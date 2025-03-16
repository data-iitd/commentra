# Importing necessary libraries
from collections import defaultdict

# Step 2: Define global variables
# G is a dictionary representing the graph.
G = defaultdict(list)
# used is a list to keep track of visited nodes.
used = []
# grundy is a list to store the Grundy number of each node.
grundy = []

# Step 3: Define the dfs function
# The function dfs is used to perform a depth-first search on the graph.
def dfs(v):
    # It marks the current node as visited.
    used[v] = True
    # It initializes the Grundy number of the current node to 0.
    grundy[v] = 0
    # It iterates through all the neighbors of the current node.
    for neighbor in G[v]:
        # If a neighbor has not been visited, it recursively calls dfs on that neighbor.
        if not used[neighbor]:
            dfs(neighbor)
            # It updates the Grundy number of the current node by performing the XOR operation with (grundy[neighbor] + 1).
            grundy[v] ^= (grundy[neighbor] + 1)

# Step 4: Main function
if __name__ == "__main__":
    # It reads the number of nodes N.
    N = int(input())
    # It initializes the used and grundy lists.
    global used, grundy
    used = [False] * N
    grundy = [0] * N
    
    # It reads the edges of the graph and constructs the adjacency list.
    for _ in range(N - 1):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        G[x].append(y)
        G[y].append(x)
    
    # It calls the dfs function starting from node 0.
    dfs(0)
    # It checks the Grundy number of the root node (node 0).
    if grundy[0] != 0:
        # It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
        print("Alice")
    else:
        print("Bob")

# <END-OF-CODE>
