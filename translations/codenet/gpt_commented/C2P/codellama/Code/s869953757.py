#include<stdio.h>

#define M 100 # Maximum number of vertices in the graph
#define whi 0 # Color code for white (unvisited)
#define gra 1 # Color code for gray (visited but not fully explored)
#define bla 2 # Color code for black (fully explored)

n = 0 # Number of vertices in the graph
T = [[0 for x in range(M)] for y in range(M)] # Adjacency matrix to represent the graph
color = [0 for x in range(M)] # Arrays to store the color and distance of each vertex
d = [0 for x in range(M)]
Q = [0 for x in range(M)]
head = 0
tail = 0

# Function to add an element to the queue
def enqueue(x):
  Q[tail] = x # Add element x to the queue
  tail = (tail+1)%M # Update tail index in a circular manner

# Function to remove and return an element from the queue
def dequeue():
  x = Q[head] # Get the front element of the queue
  head = (head+1)%M # Update head index in a circular manner
  return x # Return the dequeued element

# Function to perform Breadth-First Search (BFS) starting from vertex s
def bfs(s):
  i, u, v = 0, 0, 0

  # Initialize all vertices as unvisited and set their distances to a large value
  for i in range(n):
    color[i] = whi # Set color to white (unvisited)
    d[i] = 1000000 # Set distance to a large number (infinity)

  # Start BFS from the source vertex s
  color[s] = gra # Mark the source vertex as gray (visited)
  d[s] = 0 # Distance to source vertex is 0
  enqueue(s) # Enqueue the source vertex

  # Continue BFS until the queue is empty
  while head != tail:
    u = dequeue() # Dequeue a vertex from the queue
    # Explore all adjacent vertices of u
    for v in range(n):
      # If there is an edge from u to v and v is unvisited
      if T[u][v] == 1 and color[v] == whi:
        color[v] = gra # Mark v as gray (visited)
        d[v] = d[u]+1 # Update distance to v
        enqueue(v) # Enqueue vertex v for further exploration
    color[u] = bla # Mark u as black (fully explored)

# Main function
def main():
  i, j = 0, 0
  u, k, v = 0, 0, 0

  # Read the number of vertices
  scanf("%d", &n)

  # Initialize the adjacency matrix to zero (no edges)
  for i in range(n):
    for j in range(n):
      T[i][j] = 0 # No edge between vertices i and j

  # Read the edges of the graph
  for i in range(n):
    scanf("%d %d", &u, &k) # Read vertex u and number of edges k
    u-- # Convert to zero-based index
    for j in range(k):
      scanf("%d", &v) # Read each adjacent vertex v
      v-- # Convert to zero-based index
      T[u][v] = 1 # Set the edge from u to v in the adjacency matrix

  # Perform BFS starting from vertex 0
  bfs(0)

  # Output the distance from the source vertex to each vertex
  for i in range(n):
    if d[i] == 1000000: d[i] = -1 # If distance is still infinity, set it to -1
    printf("%d %d\n", i+1, d[i]) # Print vertex number and its distance

  return 0 # Return success

