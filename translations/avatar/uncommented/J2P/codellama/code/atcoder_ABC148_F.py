
import sys
import math

def main():
    N = int(sys.stdin.readline().strip())
    u = int(sys.stdin.readline().strip()) - 1
    v = int(sys.stdin.readline().strip()) - 1
    edges = [[] for i in range(N)]
    for i in range(N - 1):
        a, b = map(int, sys.stdin.readline().strip().split())
        edges[a - 1].append(b - 1)
        edges[b - 1].append(a - 1)
    d = [math.inf] * N
    d[u] = 0
    dfs(u, d, edges)
    e = [math.inf] * N
    e[v] = 0
    dfs(v, e, edges)
    q = -1
    for i in range(N):
        if d[i] < e[i]:
            if e[i] > q:
                q = e[i]
    if q <= 0:
        print(0)
    else:
        print(q - 1)

def dfs(u, d, edges):
    for nu in edges[u]:
        if d[nu] == math.inf:
            d[nu] = d[u] + 1
            dfs(nu, d, edges)

if __name__ == "__main__":
    main()

