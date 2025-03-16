class Edge:
    def __init__(self, id, to):
        self.id = id
        self.to = to

def dfs(to, color, parents, g, ans):
    k = 1
    for e in g[to]:
        if e.to == parents:
            continue
        if k == color:
            k += 1
        ans[e.id] = k
        dfs(e.to, k, to, g, ans)
        k += 1

n = int(input())
g = [[] for _ in range(n)]
ans = [0] * (n - 1)

for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(Edge(i, b))
    g[b].append(Edge(i, a))

dfs(0, -1, -1, g, ans)

max_ans = 0
for temp in ans:
    max_ans = max(max_ans, temp)

print(max_ans)
for c in ans:
    print(c)

