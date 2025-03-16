import numpy as np

# Read the height (h) and width (w) of the graph from input
h, w = map(int, input().split())

# Initialize the graph: 
# Replace '#' with 0 (indicating an obstacle) and other characters with infinity (indicating unvisited cells)
graph = [[0 if i == '#' else float('inf') for i in list(input())] for _ in range(h)]
graph = np.array(graph)

# Update the graph by calculating the minimum distance from the left side
for x in range(w - 1):
    # For each column, update the distance from the previous column
    graph[:, x + 1] = np.minimum(graph[:, x] + 1, graph[:, x + 1])

# Update the graph by calculating the minimum distance from the right side
for x in range(w - 1, 0, -1):
    # For each column, update the distance from the next column
    graph[:, x - 1] = np.minimum(graph[:, x] + 1, graph[:, x - 1])

# Update the graph by calculating the minimum distance from the top side
for y in range(h - 1):
    # For each row, update the distance from the previous row
    graph[y + 1, :] = np.minimum(graph[y, :] + 1, graph[y + 1, :])

# Update the graph by calculating the minimum distance from the bottom side
for y in range(h - 1, 0, -1):
    # For each row, update the distance from the next row
    graph[y - 1, :] = np.minimum(graph[y, :] + 1, graph[y - 1, :])

# Print the maximum distance found in the graph, which represents the farthest distance from an obstacle
print(int(np.max(graph)))
