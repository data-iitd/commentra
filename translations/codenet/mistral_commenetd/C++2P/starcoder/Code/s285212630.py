
# <START-OF-CODE>
import sys

def dfs(v, p, d):
    U[0][v] = p
    R[v] = d
    L[v] = 1
    for c, w in G[v]:
        if c == p: continue
        dfs(c, v, d+1)
        L[v] += L[c]

def solve(n, g):
    global N, G, U, R, L
    N = n
    G = g
    for i in range(MAX_L):
        for j in range(N):
            U[i][j] = -1
    dfs(0, -1, 0)
    for i in range(1, MAX_L):
        for j in range(N):
            if U[i-1][j] == -1: continue
            U[i][j] = U[i-1][U[i-1][j]]
    for i in range(N):
        print(U[i])

def main():
    n = int(input())
    g = [[] for i in range(n)]
    for i in range(n-1):
        a, b = map(int, input().split())
        g[a-1].append((b-1, 1))
        g[b-1].append((a-1, 1))
    solve(n, g)

if __name__ == '__main__':
    main()
# 