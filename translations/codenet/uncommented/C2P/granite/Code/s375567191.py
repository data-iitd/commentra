
#include <stdio.h>
#define MAX 101
#define WHITE 0
#define BLACK 2
#define GRAY 1
time,n,g = [[0 for i in range(MAX)] for j in range(MAX)]
d = [0 for i in range(MAX)]
f = [0 for i in range(MAX)]
color = [WHITE for i in range(MAX)]

def visit(u):
  i = 0
  color[u] = GRAY
  d[u] = time + 1
  while i < n:
    if g[u][i] == 0:
      i += 1
      continue
    if color[i] == WHITE:
      visit(i)
    i += 1
  color[u] = BLACK
  f[u] = time + 1

def dfs():
  global time
  time = 0
  i = 0
  while i < n:
    if color[i] == WHITE:
      visit(i)
    i += 1
  i = 0
  while i < n:
    print(str(i+1) + " " + str(d[i]) + " " + str(f[i]))
    i += 1

if __name__ == "__main__":
  n = int(input())
  i = 0
  while i < n:
    x,y = map(int,input().split())
    j = 0
    while j < y:
      z = int(input())
      g[x-1][z-1] = 1
      j += 1
    i += 1
  dfs()

