import sys

# Define a constant for the maximum number of nodes
maxn = 100005

# Structure to represent a node with coordinates and an ID
class Node:
    def __init__(self, x, y, id):
        self.x = x
        self.y = y
        self.id = id

# Structure to represent an edge with two nodes and a weight
class Edge:
    def __init__(self, u, v, val):
        self.u = u
        self.v = v
        self.val = val

    def __lt__(self, other):
        return self.val < other.val

# Array to store the parent of each node for union-find
par = [0] * maxn
n = 0  # Number of nodes

# List to store nodes
nodes = []

# List to store edges
edges = []

# Function to initialize the union-find structure
def init():
    for i in range(n + 1):
        par[i] = i  # Each node is its own parent initially

# Function to find the representative parent of a node
def findpar(x):
    if par[x] == x:
        return x
    par[x] = findpar(par[x])
    return par[x]

# Function to unite two nodes in the union-find structure
def unite(x, y):
    x = findpar(x)
    y = findpar(y)
    if x == y:
        return
    par[x] = y

# Read the number of nodes
n = int(input())

# Initialize the union-find structure
init()

# Read the coordinates of each node and assign an ID
for i in range(1, n + 1):
    x, y = map(int, sys.stdin.readline().split())
    nodes.append(Node(x, y, i))

# Sort nodes based on their x-coordinate
nodes.sort(key=lambda node: node.x)

# Create edges based on x-coordinates
for i in range(1, n):
    edges.append(Edge(nodes[i - 1].id, nodes[i].id, nodes[i].x - nodes[i - 1].x))

# Sort nodes based on their y-coordinate
nodes.sort(key=lambda node: node.y)

# Create edges based on y-coordinates
for i in range(1, n):
    edges.append(Edge(nodes[i - 1].id, nodes[i].id, nodes[i].y - nodes[i - 1].y))

# Sort edges based on their weight
edges.sort()

ans = 0  # Variable to store the total weight of the minimum spanning tree

# Process each edge in sorted order
for edge in edges:
    u, v, val = edge.u, edge.v, edge.val
    # If u and v are already connected, skip this edge
    if findpar(u) == findpar(v):
        continue
    unite(u, v)  # Union the two nodes
    ans += val  # Add the weight of this edge to the total

# Output the total weight of the minimum spanning tree
print(ans)

# End-of-code
