import sys
from collections import defaultdict

class Edge:
    def __init__(self, s, g, c):
        self.s = s
        self.g = g
        self.c = c

class Graph:
    def __init__(self):
        self.vcnt = 0
        self.ecnt = 0
        self.e = []
        self.id = []

def read_graph():
    g = Graph()
    n = int(sys.stdin.readline().strip())
    for _ in range(n - 1):
        x, y, c = map(int, sys.stdin.readline().strip().split())
        g.e.append(Edge(x, y, c))
        g.e.append(Edge(y, x, c))
    g.vcnt = n
    g.ecnt = 2 * n - 2
    g.e.sort(key=lambda edge: (edge.s, edge.g))

    p = 0
    g.id = [0] * (n + 1)
    for i in range(n):
        while p < g.ecnt and g.e[p].s < i:
            p += 1
        g.id[i] = p
    g.id[g.vcnt] = g.ecnt  # Sentinel
    return g

def tyokkei(g):
    tyokkeitemp = [0] * (g.vcnt + 10)
    tyokkeitemp[0] = 1

    def tyokkeidfs(s):
        for i in range(g.id[s], g.id[s + 1]):
            if tyokkeitemp[g.e[i].g] == 0:
                tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
                tyokkeidfs(g.e[i].g)

    tyokkeidfs(0)
    M = 0
    Mi = 0
    for i in range(g.vcnt):
        if tyokkeitemp[i] > M:
            M = tyokkeitemp[i]
            Mi = i

    tyokkeitemp = [0] * (g.vcnt + 10)
    tyokkeitemp[Mi] = 1
    tyokkeidfs(Mi)

    for i in range(g.vcnt):
        M = max(M, tyokkeitemp[i])

    return M - 1

if __name__ == "__main__":
    g = read_graph()
    print(tyokkei(g))

# <END-OF-CODE>
