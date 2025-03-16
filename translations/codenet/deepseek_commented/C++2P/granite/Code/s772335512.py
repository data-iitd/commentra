
import sys
sys.setrecursionlimit(10**6)

# Step 2: Define global variables
# G is a dictionary representing the graph.
G = {}
# used is a boolean array to keep track of visited nodes.
used = [False]*100000
# grundy is an array to store the Grundy number of each node.
grundy = [0]*100000

# Step 3: Define the dfs function
# The function dfs is used to perform a depth-first search on the graph.
def dfs(v):
    # It marks the current node as visited.
    used[v] = True
    # It iterates through all the neighbors of the current node.
    for u in G[v]:
        # If a neighbor has not been visited, it recursively calls dfs on that neighbor.
        if not used[u]:
            dfs(u)
            # It updates the Grundy number of the current node by performing the XOR operation with (grundy[u] + 1).
            grundy[v] ^= (grundy[u]+1)

# Step 4: Main function
if __name__ == "__main__":
    # It reads the number of nodes N.
    N = int(input())
    # It reads the edges of the graph and constructs the adjacency list.
    for _ in range(N-1):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        if x not in G:
            G[x] = []
        if y not in G:
            G[y] = []
        G[x].append(y)
        G[y].append(x)
    # It calls the dfs function starting from node 0.
    dfs(0)
    # It checks the Grundy number of the root node (node 0).
    if grundy[0]!= 0:
        # It prints "Alice" if the Grundy number is not 0, otherwise it prints "Bob".
        print("Alice")
    else:
        print("Bob")

