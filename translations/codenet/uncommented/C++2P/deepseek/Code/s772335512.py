import sys
sys.setrecursionlimit(10**6)

N = int(input())
G = [[] for _ in range(100000)]
used = [False] * 100000
grundy = [0] * 100000

def dfs(v):
    used[v] = True
    grundy[v] = 0
    for i in G[v]:
        if not used[i]:
            dfs(i)
            grundy[v] ^= (grundy[i] + 1)

for _ in range(N - 1):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    G[x].append(y)
    G[y].append(x)

dfs(0)

if grundy[0] != 0:
    print("Alice")
else:
    print("Bob")

