
import sys
sys.setrecursionlimit(10**6)

N = int(input())
G = [[] for _ in range(N)]
for _ in range(N-1):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    G[x].append(y)
    G[y].append(x)

used = [False]*N
grundy = [0]*N

def dfs(v):
    used[v] = True
    grundy[v] = 0
    for u in G[v]:
        if not used[u]:
            dfs(u)
            grundy[v] ^= (grundy[u]+1)

dfs(0)
if grundy[0]!= 0:
    print("Alice")
else:
    print("Bob")

