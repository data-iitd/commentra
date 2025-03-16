
import sys

def dfs(to, color, parents):
    k = 1
    for e in g[to]:
        if e.to == parents:
            continue
        if k == color:
            k += 1
        ans[e.id] = k
        dfs(e.to, k, to)
        k += 1

n = int(sys.stdin.readline())
g = [[] for _ in range(n)]
for i in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    g[a - 1].append(Edge(i, b - 1))
    g[b - 1].append(Edge(i, a - 1))

ans = [0] * (n - 1)
dfs(0, -1, -1)

max = 0
for temp in ans:
    max = max(max, temp)

print(max)
for c in ans:
    print(c)

class Edge:
    def __init__(self, id, to):
        self.id = id
        self.to = to

