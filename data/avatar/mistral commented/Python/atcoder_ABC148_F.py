# Importing necessary libraries and setting recursion limit
from collections import Counter, defaultdict, deque
from heapq import heappop, heappush, heapify
import sys, bisect, math, itertools, pprint, fractions
sys.setrecursionlimit(10**8)
mod=10**9+7
INF=float('inf')

# Function to take input as an integer
def inp():
    return int(sys.stdin.readline())

# Function to take input as a list
def inpl():
    return list(map(int,sys.stdin.readline().split()))

# Input the number of nodes, starting and ending nodes
n, ta, ao = inpl()
ta -= 1 ; ao -= 1

# Initialize an adjacency list
g = [ [ ] for i in range(n) ]

# Read edges and add them to the graph
for i in range(n-1):
    a, b = inpl()
    g[a-1].append(b-1)
    g[b-1].append(a-1)

# Initialize distance arrays for both nodes
ta_dist = [None]*n
ao_dist = [None]*n

# Initialize distances for starting and ending nodes
ta_dist[ta] = 0
ao_dist[ao] = 0

# Depth First Search from starting node to calculate distances from starting node
def ta_dfs(node):
    for v in g[node]:
        if ta_dist[v] is not None: continue
        ta_dist[v] = ta_dist[node] + 1
        ta_dfs(v)

# Depth First Search from ending node to calculate distances from ending node
def ao_dfs(node):
    for v in g[node]:
        if ao_dist[v] is not None: continue
        ao_dist[v] = ao_dist[node] + 1
        ao_dfs(v)

# Perform Depth First Search from starting and ending nodes
ao_dfs(ao)
ta_dfs(ta)

# Calculate the answer
res = 0
for i in range(n):
    if ta_dist[i] is None or ao_dist[i] is None or ta_dist[i] > ao_dist[i]: continue
    res = max(res, ao_dist[i])

# Print the answer
print(res-1)
