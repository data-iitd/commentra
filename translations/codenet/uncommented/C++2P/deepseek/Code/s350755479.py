import sys
from typing import List, Tuple

class Node:
    def __init__(self, x: int, y: int, id: int):
        self.x = x
        self.y = y
        self.id = id

class Edge:
    def __init__(self, u: int, v: int, val: int):
        self.u = u
        self.v = v
        self.val = val

    def __lt__(self, other: 'Edge'):
        return self.val < other.val

def cmp1(a: Node, b: Node) -> bool:
    return a.x < b.x

def cmp2(a: Node, b: Node) -> bool:
    return a.y < b.y

def findpar(par: List[int], x: int) -> int:
    if par[x] == x:
        return x
    par[x] = findpar(par, par[x])
    return par[x]

def unite(par: List[int], x: int, y: int):
    x = findpar(par, x)
    y = findpar(par, y)
    if x == y:
        return
    par[x] = y

def main():
    n = int(input())
    nodes = [Node(0, 0, i) for i in range(n + 1)]
    edges = []
    par = [i for i in range(n + 1)]

    for i in range(1, n + 1):
        x, y = map(int, sys.stdin.readline().split())
        nodes[i].x = x
        nodes[i].y = y
        nodes[i].id = i

    nodes.sort(key=lambda node: node.x, reverse=False)

    for i in range(2, n + 1):
        edges.append(Edge(nodes[i - 1].id, nodes[i].id, nodes[i].x - nodes[i - 1].x))

    nodes.sort(key=lambda node: node.y, reverse=False)

    for i in range(2, n + 1):
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
