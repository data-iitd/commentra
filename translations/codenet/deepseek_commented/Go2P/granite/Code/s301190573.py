
import sys

def NextLine():
  return sys.stdin.readline().strip()
# Reads the next line of input from the standard input.

def NextInts():
  return list(map(int,NextLine().split()))
# Reads two integers from a single line of input, splits the line by spaces, and converts the split strings to integers.

def NextIntArray():
  return list(map(lambda x:int(x)-1,NextLine().split()))
# Reads a line of space-separated integers, converts them to integers, and decrements each value by 1.

par = []
rank = []
# Global variables for the union-find data structure.

def initialize(n):
  global par,rank
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Initializes the union-find data structure with n elements, each in its own set.

def root(i):
  global par
  if par[i] == i: return i
  par[i] = root(par[i])
  return par[i]
# Finds the root of the element i, applying path compression to improve future queries.

def same(i,j):
  return root(i) == root(j)
# Checks if the elements i and j are in the same set.

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
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.

if __name__ == '__main__':
  n,m = NextInts()
  p = NextIntArray()
  initialize(n)
  for i in range(m):
    x,y = NextInts()
    unite(x-1,y-1)
  s = 0
  for i in range(n):
    if same(i,p[i]): s += 1
  print(s)
# The main function initializes the union-find data structure, processes the union operations, and counts the number of elements in the same connected component as their corresponding values in the array p.

