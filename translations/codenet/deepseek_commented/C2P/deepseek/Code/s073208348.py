import sys
from collections import defaultdict

# Define the structure for edges
class Edge:
    def __init__(self, s, g, c):
        self.s = s
        self.g = g
        self.c = c

# Define the structure for the graph
class Graph:
    def __init__(self, vcnt, ecnt):
        self.vcnt = vcnt
        self.ecnt = ecnt
        self.edges = []
        self.id = [0] * (vcnt + 1)

# Function to sort edges
def esort(a, b):
    p = a[0]
    q = b[0]
    if p.s < q.s:
        return -1
    if p.s > q.s:
        return 1
    if p.g < q.g:
        return -1
    return 1

# Function to read the graph
def readgraph():
    n = int(sys.stdin.readline().strip())
    g = Graph(n, 2 * n - 2)
    edges = []
    for _ in range(n - 1):
        x, y, c = map(int, sys.stdin.readline().strip().split())
        edges.append(Edge(x, y, c))
        edges.append(Edge(y, x, c))
    g.edges = edges
    g.edges.sort(key=lambda edge: (edge.s, edge.g))

    p = 0
    for i in range(n):
        while p < len(g.edges) and g.edges[p].s < i:
            p += 1
        g.id[i] = p
    g.id[n] = len(g.edges)
    return g

# Function to perform DFS and update distances
def tyokkeidfs(s, temp):
    for i in range(g.id[s], g.id[s + 1]):
        if temp[g.edges[i].g] == 0:
            temp[g.edges[i].g] = temp[s] + g.edges[i].c
            tyokkeidfs(g.edges[i].g, temp)

# Function to find the diameter of the tree
def tyokkei():
    temp = [0] * (g.vcnt + 10)
    temp[0] = 1
    tyokkeidfs(0, temp)
    M = 0
    Mi = 0
    for i in range(g.vcnt):
        if temp[i] > M:
            M = temp[i]
            Mi = i
    temp = [0] * (g.vcnt + 10)
    temp[Mi] = 1
    tyokkeidfs(Mi, temp)
    for i in range(g.vcnt):
        M = max(M, temp[i])
    return M - 1

# Main function
g = readgraph()
print(tyokkei())
