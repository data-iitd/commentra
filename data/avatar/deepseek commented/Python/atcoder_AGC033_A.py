
import numpy as np

# Read the dimensions of the grid
h, w = map(int, input().split())

# Initialize the grid with 0 for '.' and inf for '#'
graph = [[0 if i == '#' else float('inf') for i in list(input())] for _ in range(h)]
graph = np.array(graph)

# Calculate the minimum distance to any '#' for each cell in the grid
# Processing in the left to right direction
for x in range(w - 1):
    graph[:, x + 1] = np.minimum(graph[:, x] + 1, graph[:, x + 1])

# Processing in the right to left direction
for x in range(w - 1, 0, -1):
    graph[:, x - 1] = np.minimum(graph[:, x] + 1, graph[:, x - 1])

# Processing in the top to bottom direction
for y in range(h - 1):
    graph[y + 1, :] = np.minimum(graph[y, :] + 1, graph[y + 1, :])

# Processing in the bottom to top direction
for y in range(h - 1, 0, -1):
    graph[y - 1, :] = np.minimum(graph[y, :] + 1, graph[y - 1, :])

# Print the maximum value in the grid, which represents the maximum distance to the nearest '#'
print(int(np.max(graph)))

