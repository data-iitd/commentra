import sys
import io

reader = io.TextIOWrapper(sys.stdin.buffer,encoding='utf-8')

def NextLine():
  return reader.readline().rstrip()

def NextInts():
  s = NextLine().split()
  return int(s[0]), int(s[1])

def NextIntArray():
  line = NextLine()
  return list(map(int,line.split()))

def initialize(n):
  global par,rank
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]

def root(i):
  if par[i] == i: return i
  par[i] = root(par[i])
  return par[i]

def same(i,j):
  return root(i) == root(j)

def unite(i,j):
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
initialize(n)
for i in range(m):
  x,y = NextInts()
  unite(x-1,y-1)

s = 0
for i in range(n):
  if same(i,p[i]-1): s += 1

print(s)

