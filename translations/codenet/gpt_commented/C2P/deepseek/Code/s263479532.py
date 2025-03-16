import sys

# Define constants
MAX = 100
INF = 999999
NIL = -1
WHITE = 0
BLACK = 2

# Function prototype for Prim's algorithm
def prim():
    u, i, v, mincost, sum = 0, 0, 0, 0, 0
    d = [INF] * n
    pi = [NIL] * n
    color = [WHITE] * n

    # Initialize arrays for distance, parent, and color of each vertex
    for u in range(n):
        d[u] = INF
        pi[u] = NIL
        color[u] = WHITE

    # Start with the first vertex
    d[0] = 0

    # Main loop to find the minimum spanning tree
    while True:
        mincost = INF

        # Find the vertex with the minimum cost edge that is not yet included in the MST
        for i in range(n):
            if color[i] != BLACK and d[i] < mincost:
                mincost = d[i]
                u = i  # Update the vertex to be included in the MST

        # If no vertex is found, break the loop
        if mincost == INF:
            break

        # Mark the selected vertex as BLACK (included in the MST)
        color[u] = BLACK

        # Update the distances and parents for the adjacent vertices
        for v in range(n):
            # If the vertex is not yet included in the MST and the edge weight is less than the current known distance
            if color[v] != BLACK and G[u][v] < d[v] and G[u][v] != -1:
                pi[v] = u
                d[v] = G[u][v]

    # Calculate the total weight of the minimum spanning tree
    for i in range(n):
        if d[i] != INF:
            sum += d[i]

    # Return the total weight of the minimum spanning tree
    return sum

# Read the number of vertices in the graph
n = int(input().strip())

# Read the adjacency matrix representation of the graph
G = [[0] * MAX for _ in range(MAX)]
for i in range(n):
    G[i] = list(map(int, input().strip().split()))

# Call Prim's algorithm and print the total weight of the minimum spanning tree
print(prim())
