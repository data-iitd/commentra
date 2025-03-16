# Include necessary headers for input/output, data manipulation, and other functionalities
import sys
import io
import math
import collections
import itertools
import bisect
import functools
import operator
import heapq
import array
import time
import random
import re

# Define constants and data structures
MOD = 1000000007
INF = 1145141919
MAX_L = 22

# Depth-First Search (DFS) function to traverse the graph and populate the ancestor matrix and rank array
def dfs(x, p, r, l):
  U[0][x] = p
  R[x] = r
  L[x] = l
  for pp in G[x]:
    t = pp[0]
    if t == p: continue
    dfs(t, x, r+1, l+pp[1])

# Lowest Common Ancestor (LCA) function to find the lowest common ancestor of two nodes
def lca(a, b):
  if R[a] > R[b]:
    a, b = b, a
  for k in range(MAX_L-1, -1, -1):
    if (R[a] - R[b]) >> k & 1:
      b = U[k][b]
  if a == b: return a
  for k in range(MAX_L-1, -1, -1):
    if U[k][a]!= U[k][b]:
      a = U[k][a]
      b = U[k][b]
  return U[0][a]

# Distance calculation function to find the distance between two nodes
def dist(x, y):
  g = lca(x, y)
  return L[x] + L[y] - 2*L[g]

# Main function to read input, initialize the graph, call dfs to populate the ancestor matrix, and process queries
if __name__ == '__main__':
  # Read input
  N = int(input())
  G = [[] for _ in range(N)]
  for i in range(N-1):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append((b, c))
    G[b].append((a, c))
  for i in range(MAX_L):
    for j in range(N):
      U[i][j] = -1
  dfs(0, -1, 0, 0)
  for i in range(MAX_L-1):
    for v in range(N):
      if U[i][v] == -1:
        U[i+1][v] = -1
      U[i+1][v] = U[i][U[i][v]]
  Q, K = map(int, input().split())
  K -= 1
  for i in range(Q):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    print(dist(x, K) + dist(K, y))

