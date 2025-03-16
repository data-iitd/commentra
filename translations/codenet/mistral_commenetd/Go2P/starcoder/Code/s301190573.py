
# <START-OF-CODE>

import sys

# Function to read a single line from the standard input
def NextLine():
  return sys.stdin.readline().strip()

# Function to read two integers from a single line
def NextInts():
  s = NextLine().split()
  return int(s[0]), int(s[1])

# Function to read an array of integers from a single line
def NextIntArray():
  s = NextLine().split()
  a = [int(x) for x in s]
  return a

# Initialize arrays for parent and rank
par = []
rank = []

# Function to initialize arrays
def initialize(n):
  global par, rank
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]

# Main function
def main():
  # Read number of nodes and edges
  n, m = NextInts()
  # Read array of edges
  p = NextIntArray()
  # Initialize arrays
  initialize(n)
  # Process each edge by uniting their parents
  for i in range(m):
    x, y = NextInts()
    unite(x-1, y-1)
  # Count the number of disconnected components
  s = 0
  for i in range(n):
    if same(i, p[i]-1):
      s += 1
  # Print the result
  print(s)

# Function to find the root of a node
def root(i):
  # If the node is its own parent, return it
  if par[i] == i:
    return i
  # Recursively find the root of the parent
  par[i] = root(par[i])
  # Return the new root
  return par[i]

# Function to check if two nodes have the same parent
def same(i, j):
  # Find the root of both nodes
  return root(i) == root(j)

# Function to unite two nodes
def unite(i, j):
  # Find the roots of both nodes
  i = root(i)
  j = root(j)
  # If they already have the same parent, return
  if i == j:
    return
  # Make the smaller rank node a child of the larger rank node
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    # If they have the same rank, increase the rank of the node with the smaller index
    if rank[i] == rank[j]:
      rank[i] += 1

# 