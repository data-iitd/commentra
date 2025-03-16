
import sys

# Define the adjacency matrix of the graph
G = [
    [0, 1, 2, 3, 4],
    [1, 0, 5, 6, 7],
    [2, 5, 0, 8, 9],
    [3, 6, 8, 0, 10],
    [4, 7, 9, 10, 0]
]

# Function to find the Minimum Spanning Tree (MST) using Prim's algorithm
def prim():
    n = len(G) # Number of vertices in the graph
    d = [float('inf')] * n # Array to store the minimum distance from the tree to each vertex
    pi = [None] * n # Array to store the parent of each vertex in the MST
    color = [False] * n # Array to keep track of the color of each vertex (WHITE, GRAY, BLACK)
    sum = 0 # Variable to store the sum of MST weights

    # Initialize all distances to infinity, parents to NIL, and colors to WHITE
    for i in range(n):
        d[i] = float('inf')
        pi[i] = None
        color[i] = False

    # Distance of the first vertex is set to 0
    d[0] = 0

    # Continue until all vertices are processed
    while True:
        min = float('inf')
        u = None
        # Find the vertex with the minimum distance that is not BLACK
        for i in range(n):
            if not color[i] and d[i] < min:
                min = d[i]
                u = i
        # If no such vertex is found, break the loop
        if u is None:
            break
        # Mark the selected vertex as BLACK
        color[u] = True
        # Update the distances and parents of adjacent vertices
        for v in range(n):
            if not color[v] and G[u][v]!= float('inf'):
                if d[v] > G[u][v]:
                    d[v] = G[u][v]
                    pi[v] = u
                    color[v] = True
    # Calculate the sum of the weights of the edges in the MST
    for i in range(n):
        if pi[i] is not None:
            sum += G[i][pi[i]]
    # Print the sum of the weights of the MST
    print(sum)

# Main function to read the graph and call Prim's algorithm
def main():
    n = int(input()) # Read the number of vertices

    # Read the adjacency matrix of the graph
    for i in range(n):
        G[i] = list(map(int, input().split()))

    prim() # Call Prim's algorithm to find and print the sum of the MST

if __name__ == "__main__":
    main()

