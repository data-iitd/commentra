import sys
from collections import defaultdict

# 辺の情報を個別に持つタイプ
class Edge:
    def __init__(self, s, g, c):
        self.s = s
        self.g = g
        self.c = c

class Graph:
    def __init__(self, vcnt, ecnt):
        self.vcnt = vcnt
        self.ecnt = ecnt
        self.edges = []
        self.ids = [0] * (vcnt + 1)

    def add_edge(self, s, g, c):
        self.edges.append(Edge(s, g, c))
        self.edges.append(Edge(g, s, c))

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

g = None

def readgraph():
    global g
    n = int(sys.stdin.readline().strip())
    g = Graph(n, 2 * n - 2)
    for i in range(n - 1):
        x, y, c = map(int, sys.stdin.readline().strip().split())
        g.add_edge(x, y, c)
    g.edges.sort(key=lambda edge: (edge.s, edge.g))

    p = 0
    for i in range(g.vcnt):
        while p < g.ecnt and g.edges[p].s < i:
            p += 1
        g.ids[i] = p
    g.ids[g.vcnt] = g.ecnt

# 木の直径を求める2回dfs
def tyokkeidfs(s, temp):
    for i in range(g.ids[s], g.ids[s + 1]):
        if temp[g.edges[i].g] == 0:
            temp[g.edges[i].g] = temp[s] + g.edges[i].c
            tyokkeidfs(g.edges[i].g, temp)

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
    M = 0
    for i in range(g.vcnt):
        M = max(M, temp[i])
    return M - 1

# メイン関数
def main():
    readgraph()
    print(tyokkei())

if __name__ == "__main__":
    main()
