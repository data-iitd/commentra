INF = 100000
MAX = 101
NIL = -6
WHITE = 0
GRAY = 1
BLACK = 2

G = [[0] * MAX for _ in range(MAX)]  # 2D list to represent the graph
n = 0  # Number of vertices in the graph

# Prim's algorithm to find the Minimum Spanning Tree (MST)
def prim():
    global n
    d = [INF] * MAX  # Array to store the minimum distance from the tree to each vertex
    pi = [NIL] * MAX  # Array to store the parent of each vertex in the MST
    color = [WHITE] * MAX  # Array to keep track of the color of each vertex (WHITE, GRAY, BLACK)
    sum_mst = 0  # Variable to store the sum of MST weights

    # Distance of the first vertex is set to 0
    d[0] = 0

    # Continue until all vertices are processed
    while True:
        min_dist = INF
        u = NIL
        # Find the vertex with the minimum distance that is not BLACK
        for i in range(n):
            if color[i] != BLACK and d[i] < min_dist:
                min_dist = d[i]
                u = i
        # If no such vertex is found, break the loop
        if u == NIL:
            break
        # Mark the selected vertex as BLACK
        color[u] = BLACK
        # Update the distances and parents of adjacent vertices
        for v in range(n):
            if color[v] != BLACK and G[u][v] != INF:
                if d[v] > G[u][v]:
                    d[v] = G[u][v]
                    pi[v] = u
                    color[v] = GRAY

    # Calculate the sum of the weights of the edges in the MST
    for i in range(n):
        if pi[i] != NIL:
            sum_mst += G[i][pi[i]]
    # Print the sum of the weights of the MST
    print(sum_mst)

# Main function to read the graph and call Prim's algorithm
if __name__ == "__main__":
    n = int(input())  # Read the number of vertices

    # Read the adjacency matrix of the graph
    for i in range(n):
        for j in range(n):
            e = int(input())
            if e == -1:
                G[i][j] = INF  # If no edge, set weight to INF
            else:
                G[i][j] = e  # Otherwise, set the weight of the edge

    prim()  # Call Prim's algorithm to find and print the sum of the MST
# <END-OF-CODE>
