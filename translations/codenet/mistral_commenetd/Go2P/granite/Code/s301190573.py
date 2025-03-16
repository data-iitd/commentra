

import sys

size = 1000000
reader = sys.stdin.buffer.read(size)

def NextLine():
  return reader.readline().decode()

def NextInts():
  return list(map(int, NextLine().split()))

def NextIntArray():
  return list(map(lambda x: int(x) - 1, NextLine().split()))

par = []
rank = []

def initialize(n):
  global par, rank
  par = [i for i in range(n)]
  rank = [0] * n

def root(i):
  global par
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]

def same(i, j):
  return root(i) == root(j)

def unite(i, j):
  global par, rank
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1

if __name__ == "__main__":
  n, m = NextInts()
  p = NextIntArray()
  initialize(n)
  for i in range(m):
    x, y = NextInts()
    unite(x - 1, y - 1)
  s = 0
  for i in range(n):
    if same(i, p[i]):
      s += 1
  print(s)

