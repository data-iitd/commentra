import sys
from collections import defaultdict

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

def main():
    input = sys.stdin.readline
    n = int(input().strip())
    g = defaultdict(list)
    edges = []
    for _ in range(n - 1):
        a, b = map(int, input().strip().split())
        a -= 1
        b -= 1
        edges.append(Edge(len(_), a))
        edges.append(Edge(len(_), b))
        g[a].append(edges[-1])
        g[b].append(edges[-2])
    ans = [0] * (n - 1)
    dfs(0, -1, -1, g, ans)
    max_color = max(ans)
    print(max_color)
    for c in ans:
        print(c)

if __name__ == "__main__":
    main()
