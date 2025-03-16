import sys
from collections import defaultdict

input = sys.stdin.read
sys.setrecursionlimit(10**6)

MAX_L = 22
N = 0
G = defaultdict(list)
U = [[-1] * 100000 for _ in range(MAX_L)]
R = [0] * 100000
L = [0] * 100000

def dfs(x, p, r, l):
    U[0][x] = p
    R[x] = r
    L[x] = l
    for t, cost in G[x]:
        if t == p:
            continue
        dfs(t, x, r + 1, l + cost)

def lca(a, b):
    if R[a] > R[b]:
        a, b = b, a
    for k in range(MAX_L):
        if (R[a] - R[b]) >> k & 1:
            b = U[k][b]
    if a == b:
        return a
    for k in range(MAX_L - 1, -1, -1):
        if U[k][a] != U[k][b]:
            a = U[k][a]
            b = U[k][b]
    return U[0][a]

def dist(x, y):
    g = lca(x, y)
    return L[x] + L[y] - 2 * L[g]

def main():
    global N
    data = input().split()
    idx = 0
    N = int(data[idx])
    idx += 1
    for _ in range(N - 1):
        a = int(data[idx]) - 1
        b = int(data[idx + 1]) - 1
        c = int(data[idx + 2])
        idx += 3
        G[a].append((b, c))
        G[b].append((a, c))
    
    dfs(0, -1, 0, 0)
    
    for i in range(MAX_L - 1):
        for v in range(N):
            if U[i][v] != -1:
                U[i + 1][v] = U[i][U[i][v]]
    
    Q = int(data[idx])
    K = int(data[idx + 1]) - 1
    idx += 2
    
    results = []
    for _ in range(Q):
        x = int(data[idx]) - 1
        y = int(data[idx + 1]) - 1
        idx += 2
        results.append(dist(x, K) + dist(K, y))
    
    print("\n".join(map(str, results)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
