# -*- coding: utf-8 -*-
# https://atcoder.jp/contests/abc126/tasks/abc126_d

import sys
sys.setrecursionlimit(100000)  # Set the recursion limit to avoid recursion overflow

# Define the depth-first search (DFS) function to color the graph
def dfs(i):
  for v, w in V.get(i, []):  # Iterate over the adjacent vertices and their weights
    if (w % 2) == 0:  # Check if the weight is even
      if color[v] == -1:  # If the adjacent vertex is not colored
        color[v] = color[i]  # Assign the same color as the current vertex
      elif color[v] == color[i]:  # If the adjacent vertex has the same color as the current vertex
        continue  # Continue to the next adjacent vertex
      elif color[v] != color[i]:  # If the adjacent vertex has a different color
        return False  # Return False indicating a conflict
    else:  # If the weight is odd
      if color[v] == -1:  # If the adjacent vertex is not colored
        color[v] = 0 if color[i] else 1  # Assign a different color based on the current vertex's color
      elif color[v] == color[i]:  # If the adjacent vertex has the same color as the current vertex
        return False  # Return False indicating a conflict
      elif color[v] != color[i]:  # If the adjacent vertex has a different color
        continue  # Continue to the next adjacent vertex
    dfs(v)  # Recursively call DFS for the adjacent vertex
  return True  # Return True if no conflict is found

# Main block to execute the program
if __name__ == '__main__':
  n = int(input())  # Read the number of vertices
  V = {}  # Initialize the adjacency list
  color = {}  # Initialize the color dictionary
  for i in range(1, n):  # Read edges and populate the adjacency list
    u, v, w = map(int, input().split())
    if not V.get(u, False):
      V[u] = [[v, w]]
    else:
      V[u].append([v, w])

    if not V.get(v, False):
      V[v] = [[u, w]]
    else:
      V[v].append([u, w])

  for i in range(1, n + 1):  # Initialize the color dictionary with -1
    color[i] = -1

  while True:  # Main loop to perform DFS and color the graph
    i = 0
    for j in range(1, n + 1):
      if color[j] == -1:  # Find the first uncolored vertex
        i = j
        color[i] = 0  # Assign color 0 to the starting vertex
        break
    if i == 0:  # If all vertices are colored
      for j in range(1, n + 1):  # Print the color of each vertex
        print(color[j])
      break  # Exit the loop
    else:  # If there are uncolored vertices
      if not dfs(i):  # Perform DFS to color the graph
        print('No')  # Print "No" if a conflict is found
        break  # Exit the loop
