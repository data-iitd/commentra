
import sys

# Read the number of nodes
n = int(input())

# Initialize the union-find structure
par = [i for i in range(n + 1)]

# Define a class to represent a node with coordinates and an ID
class Node:
    def __init__(self, x, y, id):
        self.x = x
        self.y = y
        self.id = id

# Define a class to represent an edge with two nodes and a weight
class Edge:
    def __init__(self, u, v, val):
        self.u = u
        self.v = v
        self.val = val
    # Overloading the less-than operator for sorting edges based on their weight
    def __lt__(self, other):
        return self.val < other.val

# Array to store the nodes
nodes = []
# Read the coordinates of each node and assign an ID
for i in range(1, n + 1):
    x, y = map(int, input().split())
    nodes.append(Node(x, y, i))

# Sort nodes based on their x-coordinate
nodes.sort(key=lambda x: x.x)

cnt = 0 # Counter for edges
# Create edges based on x-coordinates
edges = []
for i in range(1, n):
    edges.append(Edge(nodes[i - 1].id, nodes[i].id, nodes[i].x - nodes[i - 1].x))

# Sort nodes based on their y-coordinate
nodes.sort(key=lambda x: x.y)
# Create edges based on y-coordinates
for i in range(1, n):
    edges.append(Edge(nodes[i - 1].id, nodes[i].id, nodes[i].y - nodes[i - 1].y))

# Sort edges based on their weight
edges.sort()

ans = 0 # Variable to store the total weight of the minimum spanning tree
# Process each edge in sorted order
for edge in edges:
    u, v, val = edge.u, edge.v, edge.val
    # If u and v are already connected, skip this edge
    if findpar(u) == findpar(v): continue
    unite(u, v) # Union the two nodes
    ans += val # Add the weight of this edge to the total

# Output the total weight of the minimum spanning tree
print(ans)

# Function to find the representative parent of a node
def findpar(x):
    if par[x] == x: return x # If x is the representative, return it
    par[x] = findpar(par[x]) # Find the representative of the parent of x
    return par[x]

# Function to unite two nodes in the union-find structure
def unite(x, y):
    x = findpar(x)
    y = findpar(y)
    if x == y: return # If they are already in the same set, do nothing
    par[x] = y # Union the sets by making one parent of the other

# End of the program
print("