

import sys

# Define constants
M = 100
whi = 0
gra = 1
bla = 2

# Read the number of nodes
n = int(input())

# Initialize the adjacency matrix with zeros
T = [[0 for _ in range(n)] for _ in range(n)]

# Read the edges and construct the adjacency matrix
for i in range(n):
  u, k = map(int, input().split())
  u -= 1  # Convert to 0-based index
  for j in range(k):
    v = int(input())
    v -= 1  # Convert to 0-based index
    T[u][v] = 1  # Set the edge in the adjacency matrix

# Function to enqueue an element into the queue
def enqueue(x):
  global Q, head, tail
  Q[tail] = x
  tail = (tail + 1) % M

# Function to dequeue an element from the queue
def dequeue():
  global Q, head, tail
  x = Q[head]
  head = (head + 1) % M
  return x

# Initialize all nodes to white, set distance to infinity
color = [whi] * n
d = [1000000] * n

# Set the color and distance of the source node
color[0] = gra
d[0] = 0
enqueue(0)

# Continue BFS until the queue is empty
while head!= tail:
  u = dequeue()  # Dequeue the front node
  # Explore all adjacent nodes
  for v in range(n):
    if T[u][v] == 1 and color[v] == whi:
      color[v] = gra  # Mark as gray
      d[v] = d[u] + 1  # Update distance
      enqueue(v)  # Enqueue the node
  color[u] = bla  # Mark as black

# Print the distances from the source node to all other nodes
for i in range(n):
  if d[i] == 1000000:
    d[i] = -1  # If unreachable, set distance to -1
  print(f"{i + 1} {d[i]}")  # Print node number and distance

