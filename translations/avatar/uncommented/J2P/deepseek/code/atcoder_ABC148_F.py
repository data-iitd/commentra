import sys
from collections import defaultdict, deque

def dfs(u, d, edges):
    for nu in edges[u]:
        if d[nu] == float('inf'):
            d[nu] = d[u] + 1
            dfs(nu, d, edges)

def main():
    input = sys.stdin.readline
    N = int(input())
    u = int(input()) - 1
    v = int(input()) - 1
    edges = defaultdict(list)
    for _ in range(N - 1):
        a, b = map(int, input().split())
        edges[a - 1].append(b - 1)
        edges[b - 1].append(a - 1)
    
    d = [float('inf')] * N
    d[u] = 0
    dfs(u, d, edges)
    
    e = [float('inf')] * N
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

if __name__ == "__main__":
    main()
