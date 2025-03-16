#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

#define int long long
typedef pair<int, int> P;

#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back

#define INF 1145141919
#define MOD 1000000007
#define MAX_L 22

int N; // Number of nodes in the tree
vector<P> G[100000]; // Adjacency list representation of the tree
int U[MAX_L][100000], R[100000]; // U for storing ancestors, R for depth
long long L[100000]; // L for storing the distance from the root

def dfs(x, p, r, l):
  U[0][x] = p # Set the parent of the current node
  R[x] = r # Set the depth of the current node
  L[x] = l # Set the distance from the root to the current node
  for pp in G[x]: # Iterate through all adjacent nodes
    t = pp._1 # Get the adjacent node
    if t == p: continue # Skip the parent node to avoid cycles
    dfs(t, x, r+1, l+pp._2) # Recursive DFS call for the child node

def lca(a, b):
  if R[a] > R[b]: a, b = b, a # Ensure a is the deeper node
  for k in range(MAX_L): # Adjust b to the same depth as a
    if (R[a] - R[b]) >> k & 1: b = U[k][b]
  if a == b: return a # If both nodes are the same, return a
  for k in range(MAX_L-1, -1, -1): # Find the LCA using binary lifting
    if U[k][a] != U[k][b]:
      a = U[k][a]
      b = U[k][b]
  return U[0][a] # Return the parent of a, which is the LCA

def dist(x, y):
  g = lca(x, y) # Find the LCA of x and y
  return L[x] + L[y] - 2LL*L[g] # Calculate the distance using LCA

def main():
  cin.sync_with_stdio(False)
  cin.tie(0) # Optimize input/output
  cin >> N # Read the number of nodes
  rep(i, N-1): # Read the edges of the tree
    a, b, c = cin.readline().split()
    a, b = int(a)-1, int(b)-1 # Convert to 0-based indexing
    G[a].append(P(b, int(c))) # Add edge to the adjacency list
    G[b].append(P(a, int(c))) # Add the reverse edge
  
  # Initialize the ancestor table with -1
  rep(i, MAX_L): rep(j, N): U[i][j] = -1
  
  # Perform DFS from the root to fill ancestor and depth information
  dfs(0, -1, 0, 0)
  
  # Precompute ancestors for binary lifting
  for i in range(MAX_L-1):
    for v in range(N):
      if U[i][v] == -1: U[i+1][v] = -1 # If no ancestor, set to -1
      U[i+1][v] = U[i][U[i][v]] # Set the 2^(i+1) ancestor
  
  Q, K = cin.readline().split() # Number of queries and a specific node K
  K = int(K)-1 # Convert K to 0-based indexing
  
  # Process each query
  rep(i, int(Q)):
    x, y = cin.readline().split() # Nodes for which distance is to be calculated
    x, y = int(x)-1, int(y)-1 # Convert to 0-based indexing
    # Output the total distance from x to K and K to y
    print(dist(x, K) + dist(K, y))

# 