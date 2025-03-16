
# <START-OF-CODE>

# The visit function performs a depth-first search on the graph.
def visit(u):
  global time
  color[u] = GRAY  # Set the color of the current node to gray.
  d[u] = time = time + 1  # Record the discovery time.

  for i in range(n):
    if g[u][i] == 0:
      continue  # Skip if there is no edge between u and i.
    if color[i] == WHITE:
      visit(i)  # Recursively visit adjacent white nodes.

  color[u] = BLACK  # Set the color of the current node to black.
  f[u] = time = time + 1  # Record the finishing time.


# The dfs function initializes the time and iterates through all nodes.
def dfs():
  global time
  time = 0  # Initialize the time.

  for i in range(n):
    if color[i] == WHITE:
      visit(i)  # Call visit for any white node.

  for i in range(n):
    print(i + 1, d[i], f[i])  # Print the discovery and finishing times of each node.


n = int(input())  # Read the number of nodes.

d = [0] * n
f = [0] * n
color = [0] * n

for i in range(n):
  x, y = map(int, input().split())
  for j in range(y):
    z = int(input())
    g[x - 1][z - 1] = 1  # Populate the adjacency matrix.

dfs()  # Call the dfs function to compute and print the discovery and finishing times.

# 