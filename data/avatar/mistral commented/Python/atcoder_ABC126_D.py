
import sys

# Set the maximum recursion depth to 10^5
sys.setrecursionlimit(10 ** 5)

# Define a Node class
class Node:
    def __init__(self):
        # Initialize node attributes
        self.val = None
        self.color = None
        self.adjacencies = []

    # Initialize the root node
    def __init__(self):
        super().__init__()
        self.val = 0
        self.color = True

# Read input and initialize nodes
n = int(input())
nodes = [Node() for _ in range(n)]

# Read edges and add adjacencies to nodes
for _ in range(n - 1):
    u, v, w = map(int, input().split())
    node_u = nodes[u - 1]
    node_v = nodes[v - 1]
    node_u.val = u
    node_v.val = v
    node_u.adjacencies.append([node_v, w])
    node_v.adjacencies.append([node_u, w])

# Set the root node and color it
root = nodes[0]
root.color = True

# Traverse the graph and color nodes based on their distance from the root
def traverse(node, distance):
    # Check if node has already been visited
    if node in visited:
        return
    # Mark node as visited
    visited.add(node)
    # Color node based on its distance from the root
    for adj in node.adjacencies:
        adj_node = adj[0]
        adj_distance = adj[1]
        if (distance + adj_distance) % 2 == 0:
            adj_node.color = root.color
        else:
            adj_node.color = not root.color
        traverse(adj_node, distance + adj_distance)

# Traverse the graph starting from the root
visited = set()
traverse(root, 0)

# Print the color of each node
for node in nodes:
    if node.color:
        print(1)
    else:
        print(0)