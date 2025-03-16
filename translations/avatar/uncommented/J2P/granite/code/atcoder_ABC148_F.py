
import sys
sys.setrecursionlimit(10**6)

def dfs(u, d, edges):
    for nu in edges[u]:
        if d[nu] == float('inf'):
            d[nu] = d[u] + 1
            dfs(nu, d, edges)

def main():
    N, u, v = map(int, input().split())
    u -= 1
    v -= 1
    edges = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        edges[a].append(b)
        edges[b].append(a)
    d = [float('inf')] * N
    d[u] = 0
    dfs(u, d, edges)
    e = [float('inf')] * N
    e[v] = 0
    dfs(v, e, edges)
    q = max(e[i] for i in range(N) if d[i] < e[i])
    if q <= 0:
        print(0)
    else:
        print(q - 1)

if __name__ == '__main__':
    main()

