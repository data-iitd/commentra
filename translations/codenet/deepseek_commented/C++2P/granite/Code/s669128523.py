
#depth first search
#not lie in stack

import sys
sys.setrecursionlimit(10000)

N = 100 # Define the maximum number of nodes
WHITE = 0 # Define WHITE color
GRAY = 1 # Define GRAY color
BLACK = 2 # Define BLACK color

M = [[0 for i in range(N)] for j in range(N)] # Declare the adjacency matrix and number of nodes
color = [WHITE for i in range(N)] # Declare color
d = [0 for i in range(N)] # Declare discovery time
f = [0 for i in range(N)] # Declare finish time
tt = 0 # Declare time counter

# Depth-first search visit function
def dfs_visit(u):
    global tt
    color[u] = GRAY # Set the color of node u to GRAY
    d[u] = tt + 1 # Record the discovery time of u
    for v in range(N):
        if M[u][v] == 0:
            continue # Skip if there is no edge from u to v
        if color[v] == WHITE: # If v is WHITE, recursively visit v
            dfs_visit(v)
    color[u] = BLACK # Set the color of node u to BLACK
    f[u] = tt + 1 # Record the finish time of u
    tt += 1

# Depth-first search function
def dfs():
    global tt
    for i in range(N):
        color[i] = WHITE # Initialize all nodes to WHITE
    tt = 0 # Reset the time counter
    
    for u in range(N):
        if color[u] == WHITE: # If u is WHITE, start a DFS from u
            dfs_visit(u)
    
    for i in range(N):
        print(i + 1, d[i], f[i]) # Print the discovery and finish times for each node

if __name__ == "__main__":
    n = int(input()) # Read the number of nodes
    for i in range(n):
        u, k = map(int, input().split()) # Read the node and the number of its neighbors
        u -= 1 # Convert to 0-based index
        for j in range(k):
            v = int(input()) - 1 # Read the neighbor
            v -= 1 # Convert to 0-based index
            M[u][v] = 1 # Set the edge in the adjacency matrix
    
    dfs() # Perform the depth-first search and print the results

