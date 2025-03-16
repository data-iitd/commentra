import sys

MAX = 100
INF = 999999
NIL = -1
WHITE = 0
BLACK = 2

def prim():
    global n, G
    u = 0
    mincost = 0
    d = [INF] * n
    pi = [NIL] * n
    color = [WHITE] * n
    sum_cost = 0

    d[0] = 0  # Set the distance of the first vertex to 0.

    while True:
        mincost = INF

        # Find the vertex with the smallest distance that is not yet black.
        for i in range(n):
            if color[i] != BLACK and d[i] < mincost:
                mincost = d[i]
                u = i

        if mincost == INF:
            break  # If no more vertices can be reached, break the loop.

        color[u] = BLACK  # Mark the current vertex as black.

        # Update the distances and predecessors for the neighboring vertices.
        for v in range(n):
            if color[v] != BLACK and G[u][v] < d[v] and G[u][v] != -1:
                pi[v] = u
                d[v] = G[u][v]

    # Calculate the total cost of the Minimum Spanning Tree.
    for i in range(n):
        if d[i] != INF:
            sum_cost += d[i]

    return sum_cost

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    G = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
    print(prim())

# <END-OF-CODE>
