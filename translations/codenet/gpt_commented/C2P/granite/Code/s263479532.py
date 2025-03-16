
import sys

# Function prototype for Prim's algorithm
def prim():
    n = int(input())
    G = [[int(x) for x in input().split()] for _ in range(n)]
    d = [float('inf')] * n
    pi = [None] * n
    color = [0] * n
    sum = 0

    # Initialize arrays for distance, parent, and color of each vertex
    for u in range(n):
        d[u] = 0
        pi[u] = None
        color[u] = 0

    # Main loop to find the minimum spanning tree
    while True:
        mincost = float('inf')

        # Find the vertex with the minimum cost edge that is not yet included in the MST
        for i in range(n):
            if color[i]!= 2 and d[i] < mincost:
                mincost = d[i]
                u = i  # Update the vertex to be included in the MST

        # If no vertex is found, break the loop
        if mincost == float('inf'):
            break

        # Mark the selected vertex as BLACK (included in the MST)
        color[u] = 2

        # Update the distances and parents for the adjacent vertices
        for v in range(n):
            # If the vertex is not yet included in the MST and the edge weight is less than the current known distance
            if color[v]!= 2 and G[u][v] < d[v] and G[u][v]!= -1:
                pi[v] = u  # Update the parent of vertex v
                d[v] = G[u][v]  # Update the distance to vertex v

    # Calculate the total weight of the minimum spanning tree
    for i in range(n):
        if d[i]!= float('inf'):
            sum += d[i]  # Sum up the distances of included vertices

    # Return the total weight of the minimum spanning tree
    return sum

# Read the number of vertices in the graph
n = int(input())

# Read the adjacency matrix representation of the graph
G = [[int(x) for x in input().split()] for _ in range(n)]

# Call Prim's algorithm and print the total weight of the minimum spanning tree
print(prim())

