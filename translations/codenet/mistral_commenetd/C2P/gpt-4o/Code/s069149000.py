INF = 100000
MAX = 101
NIL = -6
WHITE = 0
GRAY = 1
BLACK = 2

G = [[0] * MAX for _ in range(MAX)]
n = 0

# Function to perform Prim's Algorithm
def prim():
    global n
    d = [INF] * MAX  # Array to store the shortest distance from source vertex to all other vertices
    pi = [NIL] * MAX  # Array to store the previous vertex in the shortest path tree
    color = [WHITE] * MAX  # Array to store the color of each vertex (White, Gray, or Black)
    sum = 0  # Variable to store the total weight of the minimum spanning tree

    # Set the distance of the source vertex to 0
    d[0] = 0

    # While there are still unvisited vertices
    while True:
        min = INF
        u = NIL  # Initialize min and u to uninitialized values
        for i in range(n):
            # Find the unvisited vertex with the minimum distance
            if color[i] != BLACK and d[i] < min:
                min = d[i]
                u = i
        # If all vertices have been visited, break the loop
        if u == NIL:
            break
        # Mark the current vertex as visited (Black color)
        color[u] = BLACK
        # Update the distances of all adjacent vertices
        for v in range(n):
            if color[v] != BLACK and G[u][v] != INF:
                # If the distance through the current vertex is shorter than the current distance, update it
                if d[v] > G[u][v]:
                    d[v] = G[u][v]
                    pi[v] = u
                    color[v] = GRAY

    # Calculate and print the total weight of the minimum spanning tree
    for i in range(n):
        if pi[i] != NIL:
            sum += G[i][pi[i]]
    print(sum)

if __name__ == "__main__":
    # Read the number of vertices from the standard input
    n = int(input())

    # Initialize the adjacency matrix with INF for unconnected vertices and input edges with their weights
    for i in range(n):
        for j in range(n):
            e = int(input())
            if e == -1:
                G[i][j] = INF
            else:
                G[i][j] = e

    # Call the Prim's Algorithm function to find the minimum spanning tree
    prim()
# <END-OF-CODE>
