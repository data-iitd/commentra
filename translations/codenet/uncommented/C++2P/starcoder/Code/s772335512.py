
import sys

G = [[] for i in range(100000)]
used = [False for i in range(100000)]
grundy = [0 for i in range(100000)]

def dfs(v):
    used[v] = True
    grundy[v] = 0
    for i in G[v]:
        if not used[i]:
            dfs(i)
            grundy[v] ^= (grundy[i]+1)

N = int(sys.stdin.readline())
for i in range(N-1):
    x, y = map(int, sys.stdin.readline().split())
    x -= 1
    y -= 1
    G[x].append(y)
    G[y].append(x)

dfs(0)
if grundy[0]!= 0:
    print("Alice")
else:
    print("Bob")

