
import sys
from fractions import gcd

def bipartite_matching(graph):
    n = len(graph)
    match = [-1] * n
    used = [False] * n

    def dfs(v):
        used[v] = True
        for u in graph[v]:
            w = match[u]
            if w < 0 or (not used[w] and dfs(w)):
                match[v] = u
                match[u] = v
                return True
        return False

    res = 0
    for v in range(n):
        if match[v] < 0:
            used = [False] * n
            if dfs(v):
                res += 1
    return res

while True:
    n, m = map(int, input().split())
    if n == 0:
        break
    graph = [[] for _ in range(n + m)]
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(n):
        for j in range(m):
            if gcd(a[i], b[j])!= 1:
                graph[i].append(n + j)
    print(bipartite_matching(graph))

