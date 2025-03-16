import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)

class Edge:
    def __init__(self, id, to):
        self.id = id
        self.to = to

def dfs(to, color, parent, graph, ans):
    k = 1
    for e in graph[to]:
        if e.to == parent:
            continue
        if k == color:
            k += 1
        ans[e.id] = k
        dfs(e.to, k, to, graph, ans)
        k += 1

n = int(input())
graph = defaultdict(list)
edges = []

for _ in range(n - 1):
    a, b = map(int, input().split())
    edges.append(Edge(len(edges), a - 1))
    edges.append(Edge(len(edges), b - 1))
    graph[a - 1].append(edges[-1])
    graph[b - 1].append(edges[-2])

ans = [-1] * (n - 1)
dfs(0, -1, -1, graph, ans)

max_color = max(ans)
print(max_color)
for c in ans:
    print(c)

