
import sys
from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def dfs(self, v, par):
        self.seen[v] = True
        for i in self.graph[v]:
            if i != par:
                self.count += 1
                if self.dfs(i, v) == 1:
                    return 1
        return 0

if __name__ == "__main__":
    m = int(sys.stdin.readline().strip())
    n = int(sys.stdin.readline().strip())
    g = Graph()
    g.seen = [False] * (m + 1)
    for i in range(n):
        u, v = map(int, sys.stdin.readline().strip().split())
        g.addEdge(u, v)
        g.addEdge(v, u)

    toremove = 0
    for i in range(1, m + 1):
        if not g.seen[i]:
            g.count = 0
            if g.dfs(i, 0) == 1:
                if g.count % 2 == 1:
                    toremove += 1
            else:
                if (m - toremove) % 2 == 1:
                    toremove += 1

    print(toremove)

