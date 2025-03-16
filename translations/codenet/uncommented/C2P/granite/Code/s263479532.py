
import sys

def prim():
    n = int(input())
    G = [[int(x) for x in input().split()] for _ in range(n)]
    d = [float('inf')] * n
    pi = [None] * n
    color = [0] * n
    d[0] = 0
    while True:
        mincost = float('inf')
        for i in range(n):
            if color[i]!= 2 and d[i] < mincost:
                mincost = d[i]
                u = i
        if mincost == float('inf'):
            break
        color[u] = 2
        for v in range(n):
            if color[v]!= 2 and G[u][v] < d[v] and G[u][v]!= -1:
                pi[v] = u
                d[v] = G[u][v]
    sum = 0
    for i in range(n):
        if d[i]!= float('inf'):
            sum += d[i]
    return sum

print(prim())

