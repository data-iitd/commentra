
#depth first search
#not lie in stack

import sys
sys.setrecursionlimit(10000)

N = 100
WHITE = 0
GRAY = 1
BLACK = 2

M = [[0 for i in range(N)] for j in range(N)]
color = [WHITE for i in range(N)]
d = [0 for i in range(N)]
f = [0 for i in range(N)]
tt = 0

def dfs_visit(u):
    global tt
    color[u] = GRAY
    d[u] = tt + 1
    for v in range(N):
        if M[u][v] == 0:
            continue
        if color[v] == WHITE:
            dfs_visit(v)
    color[u] = BLACK
    f[u] = tt + 1

def dfs():
    global tt
    for i in range(N):
        color[i] = WHITE
    tt = 0
    for u in range(N):
        if color[u] == WHITE:
            dfs_visit(u)
    for i in range(N):
        print(i + 1, d[i], f[i])

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        u, k = map(int, input().split())
        u -= 1
        for j in range(k):
            v = int(input())
            v -= 1
            M[u][v] = 1
    dfs()

