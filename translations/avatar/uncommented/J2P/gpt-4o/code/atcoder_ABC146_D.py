class Edge:
    def __init__(self, id, to):
        self.id = id
        self.to = to

def dfs(to, color, parents):
    global k
    k = 1
    for e in g[to]:
        if e.to == parents:
            continue
        if k == color:
            k += 1
        ans[e.id] = k
        dfs(e.to, k, to)
        k += 1

n = int(input())
g = [[] for _ in range(n)]
for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(Edge(i, b))
    g[b].append(Edge(i, a))

ans = [0] * (n - 1)
k = 1
dfs(0, -1, -1)

max_value = max(ans)
print(max_value)
for c in ans:
    print(c)

# <END-OF-CODE>
