
# Define a constant for the maximum number of nodes
maxn = 1e5 + 5

# Define a structure for nodes with x, y coordinates and an id
class Node:
    def __init__(self, x, y, id):
        self.x = x
        self.y = y
        self.id = id

# Define a structure for edges with u, v nodes and a value
class Edge:
    def __init__(self, u, v, val):
        self.u = u
        self.v = v
        self.val = val
    def __lt__(self, rhs):
        return self.val < rhs.val

# Define an array for edges with a size of up to 2*maxn
e = [Edge(0, 0, 0) for i in range(2 * maxn)]

# Define an array for storing the parent of each node
par = [0 for i in range(maxn)]

# Define an integer for the number of nodes
n = 0

# Define a comparison function to sort nodes by x coordinate
def cmp1(a, b):
    return a.x < b.x

# Define a comparison function to sort nodes by y coordinate
def cmp2(a, b):
    return a.y < b.y

# Define a function to initialize the parent array
def init():
    for i in range(n + 1):
        par[i] = i

# Define a function to find the root of a node using path compression
def findpar(x):
    return par[x] = (par[x] == x and x or findpar(par[x]))

# Define a function to merge two sets
def unite(x, y):
    x = findpar(x)
    y = findpar(y)
    if x == y: return
    par[x] = y

# Define a function to read the number of nodes
def read_n():
    global n
    n = int(input())

# Define a function to read the coordinates of each node
def read_node():
    for i in range(1, n + 1):
        x, y = map(int, input().split())
        node[i] = Node(x, y, i)

# Define a function to sort nodes by x coordinate and create edges based on x differences
def create_edge_x():
    cnt = 0
    for i in range(2, n + 1):
        e[cnt] = Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x)
        cnt += 1

# Define a function to sort nodes by y coordinate and create edges based on y differences
def create_edge_y():
    cnt = 0
    for i in range(2, n + 1):
        e[cnt] = Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y)
        cnt += 1

# Define a function to sort all edges by their values
def sort_edge():
    e.sort()

# Define a function to read the number of nodes
read_n()

# Define a function to initialize the parent array
init()

# Define a function to read the coordinates of each node
read_node()

# Define a function to sort nodes by x coordinate and create edges based on x differences
create_edge_x()

# Define a function to sort nodes by y coordinate and create edges based on y differences
create_edge_y()

# Define a function to sort all edges by their values
sort_edge()

# Define a variable to store the total weight of the minimum spanning tree
ans = 0

# Define a function to merge two sets
for i in range(len(e)):
    u = e[i].u
    v = e[i].v
    val = e[i].val
    if findpar(u) == findpar(v): continue
    unite(u, v)
    ans += val

# Define a function to output the total weight of the minimum spanning tree
print(ans)

