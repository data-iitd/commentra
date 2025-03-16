import sys

MAX = 100
INF = 999999
NIL = -1
WHITE = 0
BLACK = 2

def prim(n, G):  # Function to implement Prim's Algorithm
    u = 0
    mincost = 0
    d = [INF] * n
    pi = [NIL] * n
    color = [WHITE] * n
    sum = 0

    d[0] = 0  # Set the initial distance of the first vertex to 0

    while True:  # The main loop of Prim's Algorithm
        mincost = INF

        for i in range(n):  # Find the unvisited vertex with the minimum distance
            if color[i] != BLACK and d[i] < mincost:
                mincost = d[i]
                u = i

        if mincost == INF:  # If all vertices have been visited, break the loop
            break

        color[u] = BLACK  # Mark the current vertex as visited

        for v in range(n):  # Update the distances of adjacent vertices
            if color[v] != BLACK and G[u][v] < d[v] and G[u][v] != -1:
                pi[v] = u
                d[v] = G[u][v]

    for i in range(n):  # Calculate and print the total weight of the MST
        if d[i] != INF:
            sum += d[i]

    return sum

if __name__ == "__main__":
    n = int(input())  # Read the number of vertices from the user
    G = []

    for i in range(n):  # Initialize the 2D array G with input values
        row = list(map(int, input().split()))
        G.append(row)

    print(prim(n, G))  # Call the prim function and print the result

# <END-OF-CODE>
