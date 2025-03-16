
import sys

def prim():
    n = int(input())
    G = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            G[i][j] = int(input())
    d = [sys.maxsize for _ in range(n)]
    pi = [-1 for _ in range(n)]
    color = [0 for _ in range(n)]
    d[0] = 0
    while True:
        min = sys.maxsize
        u = -1
        for i in range(n):
            if color[i]!= 2 and d[i] < min:
                min = d[i]
                u = i
        if u == -1:
            break
        color[u] = 2
        for v in range(n):
            if color[v]!= 2 and G[u][v]!= sys.maxsize:
                if d[v] > G[u][v]:
                    d[v] = G[u][v]
                    pi[v] = u
                    color[v] = 1
    sum = 0
    for i in range(n):
        if pi[i]!= -1:
            sum += G[i][pi[i]]
    print(sum)

prim()

