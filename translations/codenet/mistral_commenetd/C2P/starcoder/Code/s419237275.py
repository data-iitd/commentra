
#include <stdio.h>

#define N 200
#define SHIRO 0
#define HAI 1
#define KURO 2

def aaaaa():
  global n,A,color,d,f,TT
  u,k,v = 0,0,0
  i,j = 0,0

  print("Enter the number of nodes: ")
  n = int(input()) # Read the number of nodes from the user

  # Initialize the 2D array A with zeros
  for i in range(n):
    for j in range(n):
      A[i][j] = 0

  # Read the adjacency matrix from the user
  for i in range(n):
    print("Enter the number of neighbors for node %d: " % (i+1))
    k = int(input())
    for j in range(k):
      print("Enter the neighbor index: ")
      v = int(input())
      A[i][v-1] = 1 # Store the edge weight (assumed to be 1) in the adjacency matrix

  aaaaa() # Call the function aaaaa() to perform the required computation

def bbbbb(k):
  global n,A,color,d,f,TT
  v = 0

  color[k] = HAI # Mark the current node as visited (gray)
  TT += 1 # Increment the time variable TT
  d[k] = TT # Set the discovery time for the current node

  # Explore all neighbors of the current node
  for v in range(n):
    if A[k][v] == 1 and color[v] == SHIRO: # If the neighbor is unvisited
      bbbbb(v) # Recursively call the function bbbbb() for the neighbor

  # Mark the current node as finished (black)
  color[k] = KURO
  f[k] = TT + 1 # Set the finishing time for the current node

if __name__ == "__main__":
  n,A,color,d,f,TT = [0]*6
  aaaaa()

