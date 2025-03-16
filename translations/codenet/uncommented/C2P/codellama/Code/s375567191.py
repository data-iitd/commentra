#include <stdio.h>
#define MAX 101
#define WHITE 0
#define BLACK 2
#define GRAY 1

def visit(u):
  global time, n, g, d, f, color

  color[u] = GRAY
  d[u] = time + 1

  for i in range(n):
    if g[u][i] == 0:
      continue
    if color[i] == WHITE:
      visit(i)

  color[u] = BLACK
  f[u] = time + 1

def dfs():
  global time, n, g, d, f, color

  time = 0

  for i in range(n):
    if color[i] == WHITE:
      visit(i)

  for i in range(n):
    print(i + 1, d[i], f[i])

n = int(input())

g = [[0] * MAX for _ in range(MAX)]
d = [0] * MAX
f = [0] * MAX
color = [WHITE] * MAX

for i in range(n):
  x, y = map(int, input().split())
  for j in range(y):
    z = int(input())
    g[x - 1][z - 1] = 1

dfs()

