

# Python code to implement Prim's Algorithm

# Function to perform Prim's Algorithm
def prim():
    n = int(input("Enter the number of vertices: ")) # Read the number of vertices from the user
    G = [[float('inf') for _ in range(n)] for _ in range(n)] # Initialize the adjacency matrix with INF for unconnected vertices
    for i in range(n):
        for j in range(n):
            G[i][j] = int(input(f"Enter the weight of edge between vertex {i} and vertex {j} (or -1 if unconnected): ")) # Input edges with their weights
    d = [float('inf')] * n # Array to store the shortest distance from source vertex to all other vertices
    pi = [None] * n # Array to store the previous vertex in the shortest path tree
    color = [0] * n # Array to store the color of each vertex (White, Gray, or Black)
    min = float('inf')
    u = None
    while True:
        min = float('inf')
        u = None
        for i in range(n):
            if color[i]!= 2 and d[i] < min:
                min = d[i]
                u = i
        if u is None:
            break
        color[u] = 2
        for v in range(n):
            if color[v]!= 2 and G[u][v]!= float('inf'):
                if d[v] > G[u][v]:
                    d[v] = G[u][v]
                    pi[v] = u
                    color[v] = 1
    sum = 0
    for i in range(n):
        if pi[i] is not None:
            sum += G[i][pi[i]]
    print(sum) # Print the total weight of the minimum spanning tree

# Call the prim function to find the minimum spanning tree
prim()
# End of Python code

