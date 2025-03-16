# Include necessary libraries for input/output, data manipulation, and other functionalities
import sys
from collections import defaultdict

# Define constants and data structures
MAX_L = 22
N = 0
G = defaultdict(list)
U = [[-1] * 100000 for _ in range(MAX_L)]
R = [0] * 100000
L = [0] * 100000

# Depth-First Search (DFS) function to traverse the graph and populate the ancestor matrix and rank array
def dfs(x, p, r, l):
    U[0][x] = p
    R[x] = r
    L[x] = l
    for t, cost in G[x]:
        if t == p:
            continue
        dfs(t, x, r + 1, l + cost)

# Lowest Common Ancestor (LCA) function to find the lowest common ancestor of two nodes
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

# Distance calculation function to find the distance between two nodes
def dist(x, y):
    g = lca(x, y)
    return L[x] + L[y] - 2 * L[g]

# Main function to read input, initialize the graph, call dfs to populate the ancestor matrix, and process queries
def main():
    global N
    input = sys.stdin.read
    data = input().splitlines()
    
    N = int(data[0])
    for i in range(1, N):
        a, b, c = map(int, data[i].split())
        a -= 1
        b -= 1
        G[a].append((b, c))
        G[b].append((a, c))
    
    dfs(0, -1, 0, 0)
    
    for i in range(MAX_L - 1):
        for v in range(N):
            if U[i][v] != -1:
                U[i + 1][v] = U[i][U[i][v]]
    
    Q, K = map(int, data[N].split())
    K -= 1
    
    results = []
    for i in range(Q):
        x, y = map(int, data[N + 1 + i].split())
        x -= 1
        y -= 1
        results.append(dist(x, K) + dist(K, y))
    
    print("\n".join(map(str, results)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
