#include<stdio.h>
#define MAX 100
#define INF 999999
#define NIL -1
#define WHITE 0
#define BLACK 2

# Function prototype for Prim's algorithm
def prim():
    pass

n = 0
G = [[0 for x in range(MAX)] for y in range(MAX)]

# Read the number of vertices in the graph
n = int(input())

# Read the adjacency matrix representation of the graph
for i in range(n):
    for j in range(n):
        G[i][j] = int(input())

# Call Prim's algorithm and print the total weight of the minimum spanning tree
print(prim())

def prim():
    u = 0
    i = 0
    v = 0
    mincost = INF
    d = [INF for x in range(n)]
    pi = [NIL for x in range(n)]
    color = [WHITE for x in range(n)]
    sum = 0

    # Initialize arrays for distance, parent, and color of each vertex
    for u in range(n):
        d[u] = INF
        pi[u] = NIL
        color[u] = WHITE

    # Start with the first vertex
    d[0] = 0

    # Main loop to find the minimum spanning tree
    while(1):
        mincost = INF

        # Find the vertex with the minimum cost edge that is not yet included in the MST
        for i in range(n):
            if color[i] != BLACK and d[i] < mincost:
                mincost = d[i]
                u = i
                # Update the vertex to be included in the MST

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

