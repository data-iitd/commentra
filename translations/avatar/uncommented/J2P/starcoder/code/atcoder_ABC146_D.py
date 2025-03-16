
# <START-OF-CODE>
n = int(input())
g = [[] for _ in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)
ans = [-1 for _ in range(n-1)]
def dfs(to, color, parents):
    k = 1
    for e in g[to]:
        if e == parents: continue
        if k == color: k += 1
        ans[e] = k
        dfs(e, k, to)
        k += 1
dfs(0, -1, -1)
max = 0
for temp in ans:
    max = max(max, temp)
print(max)
for c in ans:
    print(c)
# 