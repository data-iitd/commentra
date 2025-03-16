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

    def __lt__(self, other):
        return self.val < other.val

def init(n):
    return list(range(n + 1))

def findpar(par, x):
    if par[x] != x:
        par[x] = findpar(par, par[x])
    return par[x]

def unite(par, x, y):
    x = findpar(par, x)
    y = findpar(par, y)
    if x != y:
        par[x] = y

def main():
    n = int(input())
    par = init(n)

    nodes = []
    for i in range(1, n + 1):
        x, y = map(int, input().split())
        nodes.append(Node(x, y, i))

    edges = []
    
    # Sort by x coordinate
    nodes.sort(key=lambda node: node.x)
    for i in range(1, n):
        edges.append(Edge(nodes[i - 1].id, nodes[i].id, nodes[i].x - nodes[i - 1].x))

    # Sort by y coordinate
    nodes.sort(key=lambda node: node.y)
    for i in range(1, n):
        edges.append(Edge(nodes[i - 1].id, nodes[i].id, nodes[i].y - nodes[i - 1].y))

    edges.sort()

    ans = 0
    for edge in edges:
        u, v, val = edge.u, edge.v, edge.val
        if findpar(par, u) == findpar(par, v):
            continue
        unite(par, u, v)
        ans += val

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
