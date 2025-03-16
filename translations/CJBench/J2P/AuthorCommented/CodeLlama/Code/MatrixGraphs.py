
import sys

# Read number of vertices and edges
vertices, edges = map(int, sys.stdin.readline().split())

# Read edges
edges_list = []
for i in range(edges):
    edges_list.append(list(map(int, sys.stdin.readline().split())))

# Read starting vertices for DFS and BFS
dfs_start_vertex, bfs_start_vertex = map(int, sys.stdin.readline().split())

# Output the results
print("The graph matrix:")
print(edges_list)
print("Depth First Order:")
print(depth_first_order(edges_list, dfs_start_vertex))
print("Breadth First Order:")
print(breadth_first_order(edges_list, bfs_start_vertex))

# END-OF-CODE