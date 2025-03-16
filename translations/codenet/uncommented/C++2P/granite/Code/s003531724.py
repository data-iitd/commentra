
import sys

def dfs(x, l):
    vis[x] = True
    cnt[l] += 1
    d[x] = l
    for i in range(u[x], 0, -1):
        T += 1
        if not vis[v]:
            dfs(v, (l + ec) % 3)
        else:
            if (l + ec) % 3!= d[v]:
                ok = False
    return

n, m = map(int, input().split())
e = [[] for _ in range(n + 1)]
u = [0] * (n + 1)
l = 0
for _ in range(m):
    a, b = map(int, input().split())
    e[a].append((b, 1))
    e[b].append((a, 2))

ans = 0
vis = [False] * (n + 1)
cnt = [0] * 3
d = [0] * (n + 1)
for i in range(1, n + 1):
    if not vis[i]:
        T = 0
        ok = True
        dfs(i, 0)
        s = cnt[0] + cnt[1] + cnt[2]
        if not ok:
            ans += s * s
        else:
            if cnt[0] and cnt[1] and cnt[2]:
                ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
            else:
                ans += T // 2

print(ans)

