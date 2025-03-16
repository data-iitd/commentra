import sys
from collections import deque
input = sys.stdin.buffer.readline

# Read the number of nodes N
N = int(input())

# Initialize adjacency list to store the graph
adj = [[] for _ in range(N + 1)]

# Read N-1 edges and populate the adjacency list
for _ in range(N - 1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

# Initialize deque for BFS and seen array to track visited nodes
que = deque()
que.append(1)
seen = [0] * (N + 1)
seen[1] = 1

# Array to store parent nodes
par = [0] * (N + 1)

# Array to count the number of children for each node
child_num = [0] * (N + 1)

# Perform BFS to find parent and child relationships
while que:
    v = que.popleft()
    for u in adj[v]:
        if seen[u] == 0:
            seen[u] = 1
            par[u] = v
            child_num[v] += 1
            que.append(u)

# Find leaf nodes (nodes with no children)
seq = deque()
for i in range(1, N + 1):
    if child_num[i] == 0:
        seq.append(i)

# Process leaf nodes to determine the winning strategy
while seq:
    c = seq.pop()
    seen[c] = 0
    if seen[par[c]] == 0:
        print('First')
        exit()
    seen[par[c]] = 0
    child_num[par[par[c]]] -= 1
    if child_num[par[par[c]]] == 0:
        seq.append(par[par[c]])

# If no winning strategy is found for the first player, print 'Second'
print('Second')
