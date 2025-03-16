import sys

maxn = int(1e5 + 5)  # Define a constant for the maximum number of nodes

class Node:
    def __init__(self, x, y, id):
        self.x = x  # x coordinate
        self.y = y  # y coordinate
        self.id = id  # node id

class Edge:
    def __init__(self, u, v, val):
        self.u = u  # first node
        self.v = v  # second node
        self.val = val  # edge value

    def __lt__(self, other):
        return self.val < other.val  # for sorting edges by value

node = [None] * maxn  # Define a list for nodes
e = []  # Define a list for edges
par = list(range(maxn))  # Define a list for storing the parent of each node

def init(n):
    global par
    par = list(range(n + 1))  # Initialize the parent array

def findpar(x):
    if par[x] != x:
        par[x] = findpar(par[x])  # Path compression
    return par[x]

def unite(x, y):
    x = findpar(x)
    y = findpar(y)
    if x != y:
        par[x] = y  # Merge two sets

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of nodes
    init(n)  # Initialize the parent array

    for i in range(1, n + 1):
        x, y = map(int, sys.stdin.readline().strip().split())  # Read the coordinates of each node
        node[i] = Node(x, y, i)  # Create a Node instance

    # Sort nodes by x coordinate and create edges based on x differences
    node[1:n + 1] = sorted(node[1:n + 1], key=lambda n: n.x)
    cnt = 0  # Initialize a counter for edges
    for i in range(2, n + 1):
        e.append(Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x))  # Create edges based on x differences

    # Sort nodes by y coordinate and create edges based on y differences
    node[1:n + 1] = sorted(node[1:n + 1], key=lambda n: n.y)
    for i in range(2, n + 1):
        e.append(Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y))  # Create edges based on y differences

    e.sort()  # Sort all edges by their values

    ans = 0  # Initialize a variable to store the total weight of the minimum spanning tree
    for edge in e:
        u, v, val = edge.u, edge.v, edge.val
        if findpar(u) == findpar(v):
            continue  # Skip if u and v are already in the same set
        unite(u, v)  # Merge u and v
        ans += val  # Add the edge value to the total weight

    print(ans)  # Output the total weight of the minimum spanning tree

if __name__ == "__main__":
    main()

# <END-OF-CODE>
