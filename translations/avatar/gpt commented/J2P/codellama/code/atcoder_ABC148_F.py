import sys

def main():
    # Initialize the scanner to read input
    sc = sys.stdin

    # Read the number of nodes (N) and the two specific nodes (u and v)
    N = int(sc.readline())
    u = int(sc.readline()) - 1 # Convert to zero-based index
    v = int(sc.readline()) - 1 # Convert to zero-based index

    # Create an adjacency list to represent the edges of the graph
    edges = [[] for i in range(N)]

    # Read the edges and populate the adjacency list
    for i in range(N - 1):
        a, b = map(int, sc.readline().split())
        a -= 1 # Convert to zero-based index
        b -= 1 # Convert to zero-based index
        edges[a].append(b) # Add edge from a to b
        edges[b].append(a) # Add edge from b to a (undirected graph)

    # Initialize distance array for the first node (u)
    d = [float('inf') for i in range(N)]
    d[u] = 0 # Distance to itself is 0

    # Perform DFS from node u to calculate distances
    dfs(u, d, edges)

    # Initialize distance array for the second node (v)
    e = [float('inf') for i in range(N)]
    e[v] = 0 # Distance to itself is 0

    # Perform DFS from node v to calculate distances
    dfs(v, e, edges)

    # Find the maximum distance from node u to any node that is closer to v
    q = -1
    for i in range(N):
        if d[i] < e[i]: # Check if node i is closer to u than to v
            if e[i] > q: # Update q if the distance to v is greater
                q = e[i]

    # Output the result based on the maximum distance found
    if q <= 0:
        print(0) # If no valid distance found, print 0
    else:
        print(q - 1) # Print the maximum distance minus 1

# Depth-first search (DFS) to calculate distances from a given node
def dfs(u, d, edges):
    for nu in edges[u]:
        if d[nu] == float('inf'): # If the node has not been visited
            d[nu] = d[u] + 1 # Update the distance
            dfs(nu, d, edges) # Recursively visit the next node

if __name__ == '__main__':
    main()
