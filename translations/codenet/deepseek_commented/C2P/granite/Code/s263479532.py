
import sys

# Include the standard input-output library for input and output operations.

# Define constants for maximum size of the graph, infinity, nil, white, and black respectively.

def prim():
    # Implement Prim's algorithm for finding the Minimum Spanning Tree.

    n = int(input())
    # Read the number of vertices from the input.

    G = [[int(x) for x in input().split()] for _ in range(n)]
    # Read the adjacency matrix representing the graph from the input.

    d = [float('inf')] * n
    pi = [None] * n
    color = [0] * n
    sum = 0

    for u in range(n):
        d[u] = 0
        # Set the distance of the first vertex to 0.

        while True:
            mincost = float('inf')

            for i in range(n):
                if color[i]!= 2 and d[i] < mincost:
                    mincost = d[i]
                    u = i

            if mincost == float('inf'):
                break

            color[u] = 2
            # Mark the current vertex as black.

            for v in range(n):
                if color[v]!= 2 and G[u][v] < d[v] and G[u][v]!= -1:
                    pi[v] = u
                    d[v] = G[u][v]
            # Update the distances and predecessors for the neighboring vertices that are not black and have a valid edge weight.

    for i in range(n):
        if d[i]!= float('inf'):
            sum += d[i]
    # Calculate the total cost of the Minimum Spanning Tree by summing up the distances of all vertices.

    return sum

# Main function to execute the program.

if __name__ == "__main__":
    print(prim())
    # Call the prim function and print the result.

