
import sys
sys.setrecursionlimit(10**6)

n = int(input())
g = [[] for _ in range(n)]
for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append((i, b))
    g[b].append((i, a))

ans = [0] * (n - 1)

def dfs(to, color, parent):
    k = 1
    for i, to in g[to]:
        if to == parent:
            continue
        if k == color:
            k += 1
        ans[i] = k
        dfs(to, k, to)
        k += 1

dfs(0, -1, -1)

max_color = max(ans)
print(max_color)
for c in ans:
    print(c)

