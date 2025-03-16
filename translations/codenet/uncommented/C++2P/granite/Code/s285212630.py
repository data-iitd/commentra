
import sys
input = sys.stdin.readline

N = int(input())
G = [[] for _ in range(N)]
for _ in range(N-1):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append((b, c))
    G[b].append((a, c))

MAX_L = 22
U = [[-1] * N for _ in range(MAX_L)]
R = [0] * N
L = [0] * N

def dfs(x, p, r, l):
    U[0][x] = p
    R[x] = r
    L[x] = l
    for t, c in G[x]:
        if t == p: continue
        dfs(t, x, r+1, l+c)

dfs(0, -1, 0, 0)
for i in range(MAX_L-1):
    for v in range(N):
        if U[i][v] == -1: U[i+1][v] = -1
        U[i+1][v] = U[i][U[i][v]]

Q, K = map(int, input().split())
K -= 1

def lca(a, b):
    if R[a] > R[b]: a, b = b, a
    for k in range(MAX_L):
        if (R[a] - R[b]) >> k & 1: b = U[k][b]
    if a == b: return a
    for k in range(MAX_L-1, -1, -1):
        if U[k][a]!= U[k][b]:
            a = U[k][a]
            b = U[k][b]
    return U[0][a]

def dist(x, y):
    g = lca(x, y)
    return L[x] + L[y] - 2 * L[g]

for _ in range(Q):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    print(dist(x, K) + dist(K, y))

