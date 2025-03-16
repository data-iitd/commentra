
import sys

# Read the number of vertices and edges
n, m = map(int, input().split())

# Create a list of adjacency lists
adj = [[] for _ in range(n)]

# Read edges and construct the graph
for _ in range(m):
    a, b = map(int, input().split())
    adj[a-1].append((b-1, 1))
    adj[b-1].append((a-1, 2))

# Define a recursive function to traverse the graph
def dfs(u, color, vis):
    vis[u] = True
    cnt[color] += 1
    d[u] = color

    for v, c in adj[u]:
        if not vis[v]:
            dfs(v, (color + c) % 3, vis)
        elif (color + c) % 3!= d[v]:
            global ok
            ok = False

# Initialize variables
ans = 0
vis = [False] * n
cnt = [0] * 3
d = [0] * n

# Iterate through all vertices
for i in range(n):
    if not vis[i]:
        T = 0
        ok = True
        dfs(i, 0, vis)
        s = cnt[0] + cnt[1] + cnt[2]
        if not ok:
            ans += s * s
        else:
            if cnt[0] and cnt[1] and cnt[2]:
                ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
            else:
                ans += T // 2

# Output the final answer
print(ans)

