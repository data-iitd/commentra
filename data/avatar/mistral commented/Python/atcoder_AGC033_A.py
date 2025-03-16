# Importing the NumPy library for numerical computations
import numpy as np

# Taking input dimensions of the graph
h, w = map(int, input().split())

# Initializing the graph as a 2D NumPy array with initial values
graph = np.array([[0 if i == '#' else float('inf') for i in list(input())] for _ in range(h)])

# Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
for x in range(w - 1):
    graph = np.minimum(graph[:, x] + 1, graph[:, x + 1])

# Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
for x in range(w - 1, 0, -1):
    graph = np.minimum(graph[:, x] + 1, graph[:, x - 1])

# Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
for y in range(h - 1):
    graph = np.minimum(graph[y, :] + 1, graph[y + 1, :])

# Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
for y in range(h - 1, 0, -1):
    graph = np.minimum(graph[y, :] + 1, graph[y - 1, :])

# Finding and printing the maximum shortest path distance in the graph
print(int(np.max(graph)))
