
import sys
sys.setrecursionlimit(10**6)

n = int(input())
g = [[] for _ in range(n)]
for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append((_, b))
    g[b].append((_, a))

ans = [0] * (n-1)
def dfs(to, color, parents):
    k = 1
    for i, e in enumerate(g[to]):
        if e[1] == parents:
            continue
        if k == color:
            k += 1
        ans[e[0]] = k
        dfs(e[1], k, to)
        k += 1

dfs(0, -1, -1)
print(max(ans))
for c in ans:
    print(c)

