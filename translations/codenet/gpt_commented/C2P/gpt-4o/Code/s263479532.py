import sys

MAX = 100
INF = 999999
NIL = -1
WHITE = 0
BLACK = 2

def prim(n, G):
    u = 0
    mincost = 0
    d = [INF] * n
    pi = [NIL] * n
    color = [WHITE] * n
    sum = 0

    # Initialize the distance for the first vertex
    d[0] = 0

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
                pi[v] = u  # Update the parent of vertex v
                d[v] = G[u][v]  # Update the distance to vertex v

    # Calculate the total weight of the minimum spanning tree
    for i in range(n):
        if d[i] != INF:
            sum += d[i]  # Sum up the distances of included vertices

    return sum

if __name__ == "__main__":
    n = int(input().strip())
    G = []

    # Read the adjacency matrix representation of the graph
    for i in range(n):
        row = list(map(int, input().strip().split()))
        G.append(row)

    # Call Prim's algorithm and print the total weight of the minimum spanning tree
    print(prim(n, G))

# <END-OF-CODE>
