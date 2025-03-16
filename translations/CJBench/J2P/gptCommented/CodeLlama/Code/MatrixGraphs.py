
import sys

# Read the number of vertices and edges from the input
vertices, edges = map(int, input().split())

# Initialize the graph using an adjacency matrix representation
graph = [[0] * vertices for _ in range(vertices)]

# Read edges from the input and add them to the graph
for _ in range(edges):
    from_, to = map(int, input().split())
    graph[from_][to] = 1
    graph[to][from_] = 1

# Read the starting vertices for DFS and BFS
dfs_start_vertex = int(input())
bfs_start_vertex = int(input())

# Print the adjacency matrix of the graph
print("The graph matrix:")
for row in graph:
    print(row)

# Perform and print the result of Depth First Search
print("Depth First Order:")
print(depth_first_order(graph, dfs_start_vertex))

# Perform and print the result of Breadth First Search
print("Breadth First Order:")
print(breadth_first_order(graph, bfs_start_vertex))

# END-OF-CODE
