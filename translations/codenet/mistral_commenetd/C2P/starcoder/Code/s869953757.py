
#include<stdio.h>

#define M 100
#define whi 0
#define gra 1
#define bla 2

n = 0
T = [[0 for i in range(M)] for j in range(M)]
color = [0 for i in range(M)]
d = [0 for i in range(M)]
Q = [0 for i in range(M)]
head = 0
tail = 0

# Function to add an element to the queue
def enqueue(x):
  Q[tail] = x
  tail = (tail+1)%M

# Function to remove an element from the queue
def dequeue():
  x = Q[head]
  head = (head+1)%M
  return x

# Breadth First Search Algorithm
def bfs(s):
  i = 0
  u = 0
  v = 0 # i is a counter, u and v are vertices

  # Initialize all vertices with white color and infinite distance
  for i in range(n):
    color[i] = whi
    d[i] = 1000000

  # Initialize source vertex with gray color and zero distance
  color[s] = gra
  d[s] = 0
  enqueue(s) # Enqueue source vertex

  # Traverse the queue until it is empty
  while(head!= tail):
    u = dequeue() # Dequeue a vertex
    for v in range(n): # Iterate through all adjacent vertices
      if(T[u][v] == 1 and color[v] == whi): # If the adjacent vertex is unvisited
	color[v] = gra # Mark it as visited
	d[v] = d[u]+1 # Update its distance
	enqueue(v) # Enqueue the adjacent vertex
    color[u] = bla # Mark the current vertex as black

# Main function
def main():
  i = 0
  j = 0 # i and j are counters
  u = 0
  k = 0
  v = 0 # u is a vertex, k is the number of neighbors, and v is a neighbor

  # Read the number of vertices
  n = int(input())

  # Initialize the adjacency matrix with zeros
  for i in range(n):
    for j in range(n):
      T[i][j] = 0

  # Read the edges and add them to the adjacency matrix
  for i in range(n):
    u,k = map(int,input().split())
    u -= 1 # Decrease the index of the source vertex by 1
    for j in range(k):
      v = int(input())
      v -= 1 # Decrease the index of the neighbor vertex by 1
      T[u][v] = 1 # Add an edge between the vertices

  # Perform BFS algorithm starting from the source vertex 0
  bfs(0)

  # Print the results
  for i in range(n):
    if(d[i] == 1000000) d[i] = -1 # Set the distance to -1 if it is unreachable
    print(i+1,d[i]) # Print the vertex index and its distance from the source

main()

