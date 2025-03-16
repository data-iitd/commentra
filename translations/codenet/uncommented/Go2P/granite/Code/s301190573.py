
import sys
import io

size = 1000000
reader = io.BufferedReader(io. InputStreamReader(sys.stdin.buffer, encoding='utf-8'), size)
def NextLine():
  return reader.readline().rstrip()
def NextInts():
  x,y = map(int,NextLine().split())
  return x,y
def NextIntArray():
  return list(map(lambda x:int(x)-1,NextLine().split()))

par = []
rank = []
def initialize(n):
  global par,rank
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
def root(i):
  global par
  if par[i] == i: return i
  par[i] = root(par[i])
  return par[i]
def same(i,j):
  return root(i) == root(j)
def unite(i,j):
  global par,rank
  i = root(i)
  j = root(j)
  if i == j: return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]: rank[i] += 1

n,m = NextInts()
p = NextIntArray()
for i in range(m):
  x,y = NextInts()
  unite(x-1,y-1)
s = 0
for i in range(n):
  if same(i,p[i]): s += 1
print(s)
