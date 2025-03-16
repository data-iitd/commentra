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

    def __lt__(self, other):
        return self.val < other.val

def cmp1(a, b):
    return a.x < b.x

def cmp2(a, b):
    return a.y < b.y

def findpar(par, x):
    if par[x] != x:
        par[x] = findpar(par, par[x])
    return par[x]

def unite(par, x, y):
    x = findpar(par, x)
    y = findpar(par, y)
    if x == y:
        return
    par[x] = y

def main():
    n = int(input())
    node = [None] * (n + 1)
    par = [i for i in range(n + 1)]
    edges = []

    for i in range(1, n + 1):
        x, y = map(int, sys.stdin.readline().split())
        node[i] = Node(x, y, i)

    node[1:] = sorted(node[1:], key=lambda n: n.x)
    for i in range(1, n):
        edges.append(Edge(node[i].id, node[i + 1].id, node[i + 1].x - node[i].x))

    node[1:] = sorted(node[1:], key=lambda n: n.y)
    for i in range(1, n):
        edges.append(Edge(node[i].id, node[i + 1].id, node[i + 1].y - node[i].y))

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
