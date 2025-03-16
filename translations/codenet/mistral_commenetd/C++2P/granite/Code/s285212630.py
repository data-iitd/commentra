
import sys
input = sys.stdin.readline

N = int(input())
G = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    G[a-1].append((b-1, 1))
    G[b-1].append((a-1, 1))

# N: number of nodes, G: adjacency list, U: ancestor, R: depth, L: path length
U = [[-1]*N for _ in range(20)]
R = [0]*N
L = [0]*N

def dfs(v, p, d):
    U[0][v] = p
    R[v] = d
    for u, c in G[v]:
        if u == p: continue
        L[u] = L[v] + c
        dfs(u, v, d+1)

dfs(0, -1, 0)
for k in range(1, 20):
    for v in range(N):
        if U[k-1][v] < 0:
            U[k][v] = -1
        else:
            U[k][v] = U[k-1][U[k-1][v]]

def lca(u, v):
    if R[u] > R[v]: u, v = v, u
    for k in range(20):
        if (R[v] - R[u]) >> k & 1:
            v = U[k][v]
    if u == v: return u
    for k in range(19, -1, -1):
        if U[k][u]!= U[k][v]:
            u = U[k][u]
            v = U[k][v]
    return U[0][u]

Q = int(input())
for _ in range(Q):
    c, d = map(int, input().split())
    c -= 1
    d -= 1
    l = lca(c, d)
    print(L[c] + L[d] - 2*L[l])

