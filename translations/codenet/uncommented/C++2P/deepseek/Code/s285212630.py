import sys
from collections import defaultdict

# Read input from stdin
input = sys.stdin.readline

# Define the main function
def main():
    N = int(input())
    G = defaultdict(list)
    U = [[-1] * N for _ in range(22)]
    R = [0] * N
    L = [0] * N

    # Read the graph
    for _ in range(N - 1):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append((b, c))
        G[b].append((a, c))

    # Depth-first search to populate U, R, and L arrays
    def dfs(x, p, r, l):
        U[0][x] = p
        R[x] = r
        L[x] = l
        for t, cost in G[x]:
            if t == p:
                continue
            dfs(t, x, r + 1, l + cost)

    dfs(0, -1, 0, 0)

    # Precompute the ancestors for LCA
    for i in range(1, 22):
        for v in range(N):
            if U[i - 1][v] == -1:
                U[i][v] = -1
            else:
                U[i][v] = U[i - 1][U[i - 1][v]]

    # Function to find the LCA of two nodes
    def lca(a, b):
        if R[a] > R[b]:
            a, b = b, a
        for k in range(22):
            if (R[a] - R[b]) >> k & 1:
                b = U[k][b]
        if a == b:
            return a
        for k in range(21, -1, -1):
            if U[k][a] != U[k][b]:
                a = U[k][a]
                b = U[k][b]
        return U[0][a]

    # Function to calculate the distance between two nodes
    def dist(x, y):
        g = lca(x, y)
        return L[x] + L[y] - 2 * L[g]

    # Read the number of queries and the starting node K
    Q, K = map(int, input().split())
    K -= 1

    # Process each query
    for _ in range(Q):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        print(dist(x, K) + dist(K, y))

# Call the main function
if __name__ == "__main__":
    main()
