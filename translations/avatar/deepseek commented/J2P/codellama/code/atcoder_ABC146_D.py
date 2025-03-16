import sys

n = int(sys.stdin.readline())
g = [[] for _ in range(n)] # Step 1: Declare the graph as an adjacency list
ans = [0] * (n - 1) # Step 3: Declare the answer array to store edge colors

for i in range(n - 1): # Step 2: Read and populate the graph
    a, b = map(int, sys.stdin.readline().split())
    g[a - 1].append((i, b - 1))
    g[b - 1].append((i, a - 1))

def dfs(to, color, parent): # Step 4: Define the DFS function
    k = 1
    for e in g[to]:
        if e[1] == parent: continue
        if k == color: k += 1
        ans[e[0]] = k
        dfs(e[1], k, to)
        k += 1

dfs(0, -1, -1) # Step 3: Call DFS with root node 0, initial color -1, and parent -1
max = 0 # Step 5: Initialize max to find the maximum color used
for temp in ans:
    max = max(max, temp) # Step 5: Find the maximum color used
print(max) # Step 5: Print the maximum color used
for c in ans:
    print(c) # Step 5: Print the colors assigned to each edge

