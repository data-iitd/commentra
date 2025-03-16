#include<stdio.h>
#define INF 100000
#define MAX 101
#define NIL -6
#define WHITE 0
#define GRAY 1
#define BLACK 2

G = [[0 for i in range(MAX)] for j in range(MAX)]
n = 0

def prim():
  d = [INF for i in range(MAX)]
  pi = [NIL for i in range(MAX)]
  color = [WHITE for i in range(MAX)]
  min = INF
  u = NIL
  v = 0
  sum = 0

  d[0] = 0

  while(1):
    min = INF
    u = NIL
    for i in range(n):
      if color[i] != BLACK and d[i] < min:
        min = d[i]
        u = i
    if u == NIL:
      break
    color[u] = BLACK
    for v in range(n):
      if color[v] != BLACK and G[u][v] != INF:
        if d[v] > G[u][v]:
          d[v] = G[u][v]
          pi[v] = u
          color[v] = GRAY
    #print(d)
    #print(pi)
    #print(color)
  for i in range(n):
    if pi[i] != NIL:
      sum += G[i][pi[i]]
  print(sum)

def main():
  e = 0
  i = 0
  j = 0

  scanf("%d",&n)

  for i in range(n):
    for j in range(n):
      scanf("%d",&e)
      if e == -1:
        G[i][j] = INF
      else:
        G[i][j] = e
  prim()

main()

