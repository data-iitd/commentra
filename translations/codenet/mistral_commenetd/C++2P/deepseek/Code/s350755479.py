import sys

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

def cmp1(a, b):
    return a.x < b.x

def cmp2(a, b):
    return a.y < b.y

def findpar(x, par):
    if par[x] == x:
        return x
    par[x] = findpar(par[x], par)
    return par[x]

def unite(x, y, par):
    x = findpar(x, par)
    y = findpar(y, par)
    if x == y:
        return
    par[x] = y

n = int(input())
node = [Node(0, 0, 0) for _ in range(n + 1)]
par = [i for i in range(n + 1)]
edges = []

for i in range(1, n + 1):
    x, y = map(int, sys.stdin.readline().split())
    node[i] = Node(x, y, i)

node = sorted(node, key=lambda x: x.x)

cnt = 0
for i in range(2, n + 1):
    edges.append(Edge(node[i - 1].id, node[i].id, node[i].x - node[i - 1].x))

node = sorted(node, key=lambda x: x.y)

for i in range(2, n + 1):
    edges.append(Edge(node[i - 1].id, node[i].id, node[i].y - node[i - 1].y))

edges = sorted(edges, key=lambda x: x.val)

ans = 0
for edge in edges:
    u, v, val = edge.u, edge.v, edge.val
    if findpar(u, par) == findpar(v, par):
        continue
    unite(u, v, par)
    ans += val

print(ans)
