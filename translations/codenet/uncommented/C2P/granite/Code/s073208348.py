
import sys

# Define the structure for edges
class Edge:
    def __init__(self, s, g, c):
        self.s = s
        self.g = g
        self.c = c

# Define the structure for the graph
class Graph:
    def __init__(self, vcnt, ecnt, e, id):
        self.vcnt = vcnt
        self.ecnt = ecnt
        self.e = e
        self.id = id

# Read the graph from input
def readgraph():
    n = int(input())
    e = [Edge(0, 0, 0)] * (2 * n - 2)
    for i in range(n):
        x, y, c = map(int, input().split())
        e[2 * i] = Edge(x, y, c)
        e[2 * i + 1] = Edge(y, x, c)
    vcnt = n
    ecnt = 2 * n - 2
    e.sort(key=lambda x: (x.s, x.g))
    id = [0] * (n + 1)
    p = 0
    for i in range(n):
        while p < ecnt and e[p].s < i:
            p += 1
        id[i] = p
    id[n] = ecnt  # 番兵
    return Graph(vcnt, ecnt, e, id)

# Calculate the diameter of the tree
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

# Main function
def main():
    g = readgraph()
    print(tyokkei(g))

if __name__ == "__main__":
    main()

