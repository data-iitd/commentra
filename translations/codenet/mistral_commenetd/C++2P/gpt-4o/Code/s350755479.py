class Node:
    def __init__(self, x, y, id):
        self.x = x
        self.y = y
        self.id = id

class Edge:
    def __init__(self, u, v, val):
        self.u = u
        self.v = v
        self.val = val

def cmp1(node):
    return node.x

def cmp2(node):
    return node.y

def init(n):
    return list(range(n + 1))  # each node initially belongs to its own set

def findpar(par, x):
    if par[x] != x:
        par[x] = findpar(par, par[x])  # path compression
    return par[x]

def unite(par, x, y):
    x = findpar(par, x)
    y = findpar(par, y)
    if x != y:
        par[x] = y  # merge by making the root of set y as the parent of the root of set x

def main():
    n = int(input())  # read the number of nodes in the graph
    par = init(n)  # initialize the disjoint set data structure

    nodes = []
    for i in range(1, n + 1):
        x, y = map(int, input().split())
        nodes.append(Node(x, y, i))  # read the coordinates and assign an id

    # Sort the nodes based on their x-coordinates
    nodes.sort(key=cmp1)

    edges = []
    # Create edges between adjacent nodes based on their x-coordinates
    for i in range(1, n):
        edges.append(Edge(nodes[i - 1].id, nodes[i].id, nodes[i].x - nodes[i - 1].x))

    # Sort the nodes based on their y-coordinates
    nodes.sort(key=cmp2)
    # Create edges between adjacent nodes based on their y-coordinates
    for i in range(1, n):
        edges.append(Edge(nodes[i - 1].id, nodes[i].id, nodes[i].y - nodes[i - 1].y))

    # Sort the edges based on their values
    edges.sort(key=lambda e: e.val)

    ans = 0  # initialize the answer to 0
    # Process each edge in the sorted order
    for edge in edges:
        u, v, val = edge.u, edge.v, edge.val
        # Skip if the nodes are already in the same set
        if findpar(par, u) == findpar(par, v):
            continue
        # Merge the sets of the nodes and add the value of the edge to the answer
        unite(par, u, v)
        ans += val

    print(ans)  # print the final answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
