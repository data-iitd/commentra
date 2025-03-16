
#include<stdio.h>
#define INF 100000
#define MAX 101
#define NIL -6
#define WHITE 0
#define GRAY 1
#define BLACK 2

n = 0
G = []

def prim():
  d = [INF for i in range(MAX)]
  pi = [NIL for i in range(MAX)]
  color = [WHITE for i in range(MAX)]
  sum = 0
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
    print(d)
  for i in range(n):
    if(pi[i]!= NIL):
      sum += G[i][pi[i]]
  print(sum)

def main():
  global n
  global G
  n = int(input())
  for i in range(n):
    G.append([INF for j in range(n)])
  for i in range(n):
    for j in range(n):
      e = int(input())
      if(e == -1):
        G[i][j] = INF
      else:
        G[i][j] = e
  prim()
  return 0

main()
print("