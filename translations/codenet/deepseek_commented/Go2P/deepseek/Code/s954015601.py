import sys
from collections import defaultdict

# genid generates a unique identifier for an edge between two nodes.
def genid(a, b):
    if b < a:
        a, b = b, a
    return a * 100000 + b

# Read the number of nodes from standard input.
N = int(sys.stdin.readline().strip())

# Initialize a dictionary to store edges and an adjacency list for the graph.
edges = defaultdict(list)
ab = []
for _ in range(N - 1):
    # Read edge information and populate the adjacency list.
    a, b = map(int, sys.stdin.readline().strip().split())
    a -= 1
    b -= 1
    ab.append((a, b))
    edges[a].append(b)
    edges[b].append(a)

# Initialize a dictionary to store the color of each edge and a stack for DFS traversal.
colors = {}
stack = [(0, -1, -1)]
while stack:
    # Pop the last element from the stack for DFS traversal.
    current_node, used_color, parent_node = stack[-1]
    stack.pop()
    color = 1
    for child_node in edges[current_node]:
        if child_node == parent_node:
            continue
        if color == used_color:
            color += 1
        colors[genid(current_node, child_node)] = color
        stack.append((child_node, color, current_node))
        color += 1

# Determine the maximum degree of any node in the graph.
K = max(len(neighbors) for neighbors in edges.values())
print(K)

# Output the colors of the edges.
for a, b in ab:
    print(colors[genid(a, b)])

