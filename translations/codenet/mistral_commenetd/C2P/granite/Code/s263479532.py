

# Python code to implement Prim's Algorithm

def prim(): # Function to implement Prim's Algorithm
    n = int(input("Enter the number of vertices: ")) # Read the number of vertices from the user
    G = [[int(input(f"Enter the weight of edge between vertex {i} and vertex {j}: ")) for j in range(n)] for i in range(n)] # Initialize the adjacency matrix G with input values
    d = [float('inf')] * n # Initialize the array d with initial values
    pi = [None] * n # Initialize the array pi with initial values
    color = [0] * n # Initialize the array color with initial values
    d[0] = 0 # Set the initial distance of the first vertex to 0
    while True: # The main loop of Prim's Algorithm
        mincost = float('inf') # Initialize mincost to the maximum possible value
        for i in range(n): # Find the unvisited vertex with the minimum distance
            if color[i]!= 2 and d[i] < mincost:
                mincost = d[i]
                u = i
        if mincost == float('inf'): break # If all vertices have been visited, break the loop
        color[u] = 2 # Mark the current vertex as visited
        for v in range(n): # Update the distances of adjacent vertices
            if color[v]!= 2 and G[u][v] < d[v] and G[u][v]!= -1:
                pi[v] = u
                d[v] = G[u][v]
    sum = 0 # Initialize the variable sum to 0
    for i in range(n): # Calculate and print the total weight of the MST
        if d[i]!= float('inf'): sum += d[i]
    return sum # Return the total weight of the MST

print(prim()) # Call the prim function and print the result

