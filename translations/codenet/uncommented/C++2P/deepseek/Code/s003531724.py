import sys
from collections import defaultdict

# Read input
n, m = map(int, sys.stdin.readline().split())
edges = defaultdict(list)
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    edges[a].append((b, 1))
    edges[b].append((a, 2))

# Initialize variables
ans = 0
vis = [False] * (n + 1)

# DFS function
def dfs(x, l):
    vis[x] = True
    cnt[l % 3] += 1
    d[x] = l
    global T
    T += 1
    for v, ec in edges[x]:
        if not vis[v]:
            dfs(v, (l + ec) % 3)
        elif (l + ec) % 3 != d[v]:
            ok = False

# Main loop
for i in range(1, n + 1):
    if not vis[i]:
        T = 0
        cnt = [0, 0, 0]
        ok = True
        dfs(i, 0)
        s = sum(cnt)
        if not ok:
            ans += s * s
        else:
            if cnt[0] and cnt[1] and cnt[2]:
                ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
            else:
                ans += T // 2

# Output the result
print(ans)
