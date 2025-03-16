#include<stdio.h>
#define INF 100000
#define MAX 101
#define NIL -6
#define WHITE 0
#define GRAY 1
#define BLACK 2

def prim():
  d = [INF] * MAX
  pi = [NIL] * MAX
  color = [WHITE] * MAX
  min = INF
  u = NIL
  v = 0
  sum = 0

  d[0] = 0

  while True:
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
    for i in range(n):
      if pi[i] != NIL:
        sum += G[i][pi[i]]
    return sum

def main():
  global n
  global G

  scanf("%d",&n)

  for i in range(n):
    for j in range(n):
      scanf("%d",&e)
      if e == -1:
        G[i][j] = INF
      else:
        G[i][j] = e

  print(prim())

if __name__ == "__main__":
  main()

