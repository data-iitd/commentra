#include<stdio.h>
#define INF 100000  # Define a constant for infinity
#define MAX 101     # Define the maximum number of vertices
#define NIL -6      # Define a constant for a non-existent parent
#define WHITE 0     # Define color for unvisited nodes
#define GRAY 1      # Define color for nodes being visited
#define BLACK 2     # Define color for visited nodes

G = [[0 for i in range(MAX)] for j in range(MAX)] # Adjacency matrix to represent the graph
n = 0 # Number of vertices in the graph

# Function to implement Prim's algorithm for finding the Minimum Spanning Tree (MST)
def prim():
  d = [INF for i in range(MAX)] # Array to store the minimum distance to each vertex
  pi = [NIL for i in range(MAX)] # Array to store the parent of each vertex in the MST
  color = [WHITE for i in range(MAX)] # Array to track the state of each vertex (WHITE, GRAY, BLACK)
  min = INF # Variable for minimum distance
  u = NIL # Variable for current vertex
  sum = 0 # Variable for total weight of MST

  # Initialize the arrays
  d[0] = 0 # Start from the first vertex, set its distance to 0

  # Main loop of Prim's algorithm
  while True:
    min = INF # Initialize minimum distance
    u = NIL # Initialize current vertex

    # Find the vertex with the minimum distance that hasn't been visited
    for i in range(n):
      if color[i] != BLACK and d[i] < min:
        min = d[i]
        u = i # Update the current vertex

    # If no vertex is found, break out of the loop
    if u == NIL:
      break

    color[u] = BLACK # Mark the current vertex as visited

    # Update the distances and parents for adjacent vertices
    for v in range(n):
      if color[v] != BLACK and G[u][v] != INF:
        # If the edge weight is less than the current known distance
        if d[v] > G[u][v]:
          d[v] = G[u][v] # Update the distance
          pi[v] = u # Update the parent
          color[v] = GRAY # Mark the vertex as being visited

  # Calculate the total weight of the MST
  for i in range(n):
    if pi[i] != NIL:
      sum += G[i][pi[i]] # Add the weight of the edges in the MST

  # Print the total weight of the Minimum Spanning Tree
  print(sum)

# Main function to read input and execute Prim's algorithm
def main():
  e = 0 # Variable to store edge weights
  i = 0
  j = 0

  # Read the number of vertices
  n = int(input())

  # Read the adjacency matrix representation of the graph
  for i in range(n):
    for j in range(n):
      e = int(input())
      if e == -1:
        G[i][j] = INF # If input is -1, set the edge weight to infinity
      else:
        G[i][j] = e # Otherwise, set the edge weight to the input value

  # Call the Prim's algorithm function to find the MST
  prim()

# Main function to read input and execute Prim's algorithm
if __name__ == "__main__":
  main()

