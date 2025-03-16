
import sys

# Define a constant for infinity
INF = 100000

# Define the maximum number of vertices
MAX = 101

# Define a constant for a non-existent parent
NIL = -6

# Define color for unvisited nodes
WHITE = 0

# Define color for nodes being visited
GRAY = 1

# Define color for visited nodes
BLACK = 2

# Function to implement Prim's algorithm for finding the Minimum Spanning Tree (MST)
def prim():
    n = int(input("Enter the number of vertices: "))
    G = [[INF for _ in range(MAX)] for _ in range(MAX)]
    for i in range(n):
        for j in range(n):
            G[i][j] = int(input(f"Enter the weight of edge between vertex {i} and vertex {j}: "))
    d = [INF for _ in range(MAX)]
    pi = [NIL for _ in range(MAX)]
    color = [WHITE for _ in range(MAX)]
    d[0] = 0
    while True:
        min = INF
        u = NIL
        for i in range(n):
            if color[i]!= BLACK and d[i] < min:
                min = d[i]
                u = i
        if u == NIL:
            break
        color[u] = BLACK
        for v in range(n):
            if color[v]!= BLACK and G[u][v]!= INF:
                if d[v] > G[u][v]:
                    d[v] = G[u][v]
                    pi[v] = u
                    color[v] = GRAY
    sum = 0
    for i in range(n):
        if pi[i]!= NIL:
            sum += G[i][pi[i]]
    print(sum)

# Main function to read input and execute Prim's algorithm
def main():
    prim()

if __name__ == "__main__":
    main()

