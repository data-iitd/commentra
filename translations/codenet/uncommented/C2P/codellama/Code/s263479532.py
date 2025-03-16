#include<stdio.h>
#define MAX 100
#define INF 999999
#define NIL -1
#define WHITE 0
#define BLACK 2
  
def prim():
    d = [INF] * n
    pi = [NIL] * n
    color = [WHITE] * n
    d[0] = 0
    while True:
        mincost = INF
        for i in range(n):
            if color[i] != BLACK and d[i] < mincost:
                mincost = d[i]
                u = i
        if mincost == INF: break
        color[u] = BLACK
        for v in range(n):
            if color[v] != BLACK and G[u][v] < d[v] and G[u][v] != -1:
                pi[v] = u
                d[v] = G[u][v]
    sum = 0
    for i in range(n):
        if d[i] != INF: sum += d[i]
    return sum
  
n = int(input())
G = [[0] * n for i in range(n)]
for i in range(n):
    for j in range(n):
        G[i][j] = int(input())
print(prim())

