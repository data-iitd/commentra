#include<stdio.h>
#define INF 100000
#define MAX 101
#define NIL -6
#define WHITE 0
#define GRAY 1
#define BLACK 2

n = int(input())
G = [[INF for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        G[i][j] = int(input())

def prim():
    d = [INF for i in range(n)]
    pi = [NIL for i in range(n)]
    color = [WHITE for i in range(n)]
    d[0] = 0
    while(1):
        min = INF
        u = NIL
        for i in range(n):
            if(color[i]!= BLACK and d[i] < min):
                min = d[i]
                u = i
        if(u == NIL):
            break
        color[u] = BLACK
        for v in range(n):
            if(color[v]!= BLACK and G[u][v]!= INF):
                if(d[v] > G[u][v]):
                    d[v] = G[u][v]
                    pi[v] = u
                    color[v] = GRAY
    sum = 0
    for i in range(n):
        if(pi[i]!= NIL):
            sum += G[i][pi[i]]
    print(sum)

prim()

