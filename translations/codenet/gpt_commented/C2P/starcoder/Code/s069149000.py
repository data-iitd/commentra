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
  d = [INF] * MAX # Array to store the minimum distance to each vertex
  pi = [NIL] * MAX # Array to store the parent of each vertex in the MST
  color = [WHITE] * MAX # Array to track the state of each vertex (WHITE, GRAY, BLACK)
  min, u, v, sum = INF, NIL, NIL, 0 # Variables for minimum distance, current vertex, and total weight of MST

  # Initialize the arrays
  for i in range(n):
    d[i] = INF   # Set all distances to infinity
    pi[i] = NIL  # Set all parents to NIL
    color[i] = WHITE # Set all vertices to unvisited
  d[0] = 0 # Start from the first vertex, set its distance to 0

  # Main loop of Prim's algorithm
  while True:
    min = INF # Initialize minimum distance
    u = NIL   # Initialize current vertex

    # Find the vertex with the minimum distance that hasn't been visited
    for i in range(n):
      if color[i]!= BLACK and d[i] < min:
        min = d[i]
        u = i # Update the current vertex
    if u == NIL:
      break # If no vertex is found, break out of the loop

    color[u] = BLACK # Mark the current vertex as visited

    # Update the distances and parents for adjacent vertices
    for v in range(n):
      if color[v]!= BLACK and G[u][v]!= INF:
        # If the edge weight is less than the current known distance
        if d[v] > G[u][v]:
          d[v] = G[u][v] # Update the distance
          pi[v] = u      # Update the parent
          color[v] = GRAY # Mark the vertex as being visited
    # Calculate the total weight of the MST
    for i in range(n):
      if pi[i]!= NIL: sum += G[i][pi[i]] # Add the weight of the edges in the MST
  # Print the total weight of the Minimum Spanning Tree
  print(sum)

# Main function to read input and execute Prim's algorithm
n = int(input()) # Read the number of vertices
G = [[INF] * MAX for i in range(MAX)] # Initialize the adjacency matrix
for i in range(n):
  for j in range(n):
    e = int(input()) # Read the edge weight
    if e == -1:
      G[i][j] = INF # If input is -1, set the edge weight to infinity
    else:
      G[i][j] = e   # Otherwise, set the edge weight to the input value
prim() # Call the Prim's algorithm function to find the MST

