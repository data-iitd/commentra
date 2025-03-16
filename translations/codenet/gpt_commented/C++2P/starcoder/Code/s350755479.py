
# Define a constant for the maximum number of nodes
maxn = 1e5 + 5

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
    # Overloading the less-than operator for sorting edges based on their weight
    def __lt__(self, rhs):
        return self.val < rhs.val

# Array to store the parent of each node for union-find
par = [0] * maxn
n = 0 # Number of nodes

# Comparison function to sort nodes based on their x-coordinate
def cmp1(a, b):
    return a.x < b.x

# Comparison function to sort nodes based on their y-coordinate
def cmp2(a, b):
    return a.y < b.y

# Function to initialize the union-find structure
def init():
    for i in range(n + 1):
        par[i] = i # Each node is its own parent initially

# Function to find the representative parent of a node
def findpar(x):
    return par[x] = (par[x] == x? x : findpar(par[x])) # Path compression

# Function to unite two nodes in the union-find structure
def unite(x, y):
    x = findpar(x), y = findpar(y) # Find the parents of both nodes
    if x == y: return # If they are already in the same set, do nothing
    par[x] = y # Union the sets by making one parent of the other

# Read the number of nodes
n = int(input())

# Initialize the union-find structure
init()

# Read the coordinates of each node and assign an ID
for i in range(1, n + 1):
    x, y = map(int, input().split())
    node[i] = Node(x, y, i) # Assign ID to the node

# Sort nodes based on their x-coordinate
node.sort(key = cmp_to_key(cmp1))

cnt = 0 # Counter for edges
# Create edges based on x-coordinates
for i in range(2, n + 1):
    e[cnt] = Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x)
    cnt += 1

# Sort nodes based on their y-coordinate
node.sort(key = cmp_to_key(cmp2))
# Create edges based on y-coordinates
for i in range(2, n + 1):
    e[cnt] = Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y)
    cnt += 1

# Sort edges based on their weight
e.sort()

ans = 0 # Variable to store the total weight of the minimum spanning tree
# Process each edge in sorted order
for i in range(cnt):
    u = e[i].u
    v = e[i].v
    val = e[i].val
    # If u and v are already connected, skip this edge
    if findpar(u) == findpar(v): continue
    unite(u, v) # Union the two nodes
    ans += val # Add the weight of this edge to the total

# Output the total weight of the minimum spanning tree
print(ans)

