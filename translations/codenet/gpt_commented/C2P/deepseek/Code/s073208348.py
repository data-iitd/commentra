import sys

# Structure to hold edge information
class Edge:
    def __init__(self, s, g, c):
        self.s = s
        self.g = g
        self.c = c

# Structure to represent the graph
class Graph:
    def __init__(self, vcnt, ecnt):
        self.vcnt = vcnt
        self.ecnt = ecnt
        self.e = []
        self.id = [0] * (vcnt + 1)

# Function to read the graph from input
def readgraph():
    n = int(sys.stdin.readline().strip())
    g = Graph(n, 2 * n - 2)
    for _ in range(n - 1):
        x, y, c = map(int, sys.stdin.readline().strip().split())
        g.e.append(Edge(x, y, c))
        g.e.append(Edge(y, x, c))
    g.ecnt = len(g.e)
    g.e.sort(key=lambda edge: (edge.s, edge.g))

    p = 0
    for i in range(g.vcnt):
        while p < g.ecnt and g.e[p].s < i:
            p += 1
        g.id[i] = p
    g.id[g.vcnt] = g.ecnt
    return g

# Function to perform DFS and find the diameter of the tree
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

    M = 0
    for i in range(g.vcnt):
        M = max(M, tyokkeitemp[i])
    return M - 1

# Main function
if __name__ == "__main__":
    g = readgraph()
    print(tyokkei(g))
