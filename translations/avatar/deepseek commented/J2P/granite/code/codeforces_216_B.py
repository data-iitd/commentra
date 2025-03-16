

import sys
sys.setrecursionlimit(10**6)

def dfs(child, par):
    global count, cycle, path
    if seen[child]: return cycle
    seen[child] = True
    for i in graph[child]:
        if i!= par:
            count += 1
            if dfs(i, child) == cycle: return cycle
    return path

m = int(input()) # Number of nodes
n = int(input()) # Number of edges
graph = [[] for _ in range(m + 1)] # Initialize adjacency list for each node
seen = [False] * (m + 1) # Initialize seen array
for _ in range(n):
    x = int(input()) # Read edge from
    y = int(input()) # Read edge to
    graph[x].append(y) # Add edge to adjacency list of node x
    graph[y].append(x) # Add edge to adjacency list of node y
toremove = 0 # Initialize removal count
for i in range(1, m + 1):
    if not seen[i]: # If node is not visited
        count = 0 # Reset count for each DFS call
        if dfs(i, 0) == cycle: # If cycle is detected
            if count % 2 == 1: toremove += 1 # Increment removal count if cycle length is odd
if (m - toremove) % 2 == 1: toremove += 1 # Adjust removal count if total nodes minus removed nodes is odd
print(toremove) # Print the final removal count

