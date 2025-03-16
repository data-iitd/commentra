
#include<stdio.h>
#define INF 100000
#define MAX 101
#define NIL -6
#define WHITE 0
#define GRAY 1
#define BLACK 2

G = [[INF for i in range(MAX)] for j in range(MAX)]
n = 0

# Function to perform Prim's Algorithm
def prim():
  i,j = 0,0 # Loop variables
  d = [INF for i in range(MAX)] # Array to store the shortest distance from source vertex to all other vertices
  pi = [NIL for i in range(MAX)] # Array to store the previous vertex in the shortest path tree
  color = [WHITE for i in range(MAX)] # Array to store the color of each vertex (White, Gray, or Black)
  min,u,v,sum = 0,0,0,0 # Variables used in the algorithm

  # Initialize all vertices with INF distance, NIL previous vertex, and WHITE color
  for i in range(n):
    d[i] = INF
    pi[i] = NIL
    color[i] = WHITE

  # Set the distance of the source vertex to 0
  d[0] = 0

  # While there are still unvisited vertices
  while 1:
    min = INF
    u = NIL # Initialize min and u to uninitialized values
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
# Return 0 to indicate successful execution
return 0

