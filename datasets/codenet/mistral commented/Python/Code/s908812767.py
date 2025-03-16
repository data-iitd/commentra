# -*- coding: utf-8 -*-
# https://atcoder.jp/contests/abc126/tasks/abc126_d

import sys
sys.setrecursionlimit(100000)

# Initialize an empty dictionary to store the graph as an adjacency list.
# Key: vertex, Value: list of adjacent vertices and their edge weights.
V = {}

# Initialize a dictionary to store the color of each vertex.
# Initially, all vertices are uncolored.
color = {}

# Function to perform Depth-First Search (DFS) from a given vertex.
# Returns True if all vertices in the connected component are colored,
# otherwise returns False.
def dfs(i):
  # Iterate through all adjacent vertices of the current vertex.
  for v, w in V.get(i, []):
    # If the edge weight is even, check if the adjacent vertex is already colored.
    if w % 2 == 0:
      # If the adjacent vertex is uncolored, assign it the same color as the current vertex.
      if color[v] == -1:
        color[v] = color[i]
      # If the adjacent vertex has the same color as the current vertex, continue to the next vertex.
      elif color[v] == color[i]:
        continue
      # If the adjacent vertex has a different color, return False as the search must stop here.
      elif color[v] != color[i]:
        return False
    # If the edge weight is odd, assign the opposite color to the adjacent vertex.
    else:
      if color[v] == -1:
        color[v] = 0 if color[i] else 1
      # If the adjacent vertex has the same color as the current vertex, return False as the search must stop here.
      elif color[v] == color[i]:
        return False
      # If the adjacent vertex has a different color, continue to the next vertex.
      elif color[v] != color[i]:
        continue
    # Recursively call the DFS function on the adjacent vertex.
    dfs(v)
  # If all adjacent vertices have been colored successfully, return True.
  return True

# Main function to read input and perform the graph coloring.
if __name__ == '__main__':
  # Read the number of vertices in the graph.
  n = int(input())
  # Initialize the graph and color dictionary.
  for i in range(1, n+1):
    color[i] = -1

  # Read the edges of the graph and add them to the graph dictionary.
  for _ in range(n-1):
    u, v, w = map(int, input().split())
    # Add the edge (u, v) with weight w to the graph dictionary.
    if not V.get(u, False):
      V[u] = [[v, w]]
    else:
      V[u].append([v, w])

    if not V.get(v, False):
      V[v] = [[u, w]]
    else:
      V[v].append([u, w])

  # Perform DFS from each uncolored vertex and color them accordingly.
  while True:
    i = 0
    for j in range(1, n+1):
      if color[j] == -1:
        i = j
        color[i] = 0
        break
    # If all vertices have been colored, print the colors and exit.
    if i == 0:
      for j in range(1, n+1):
        print(color[j])
      break
    # If a vertex cannot be colored, print "No" and exit.
    else:
      if not dfs(i):
        print('No')
        break
