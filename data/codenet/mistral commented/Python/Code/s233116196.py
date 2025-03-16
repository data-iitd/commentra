# Import the collections module and define variables N and M
from collections import deque
N,M = map(int,input().split())

# Initialize an empty dictionary G to represent the graph as an adjacency list
G = {i:[] for i in range(1,N+1)}

# Read the input and add each edge to the graph
for _ in range(M):
    a,b = map(int,input().split())
    # Add each edge to the graph in both directions
    G[a].append(b)
    G[b].append(a)

# Initialize an array col of size N+1 with -1s to represent the unassigned nodes
col = [-1 for _ in range(N+1)]

# Initialize a counter cnt to keep track of the number of connected components
cnt = 0

# Iterate through each node i in the graph
for i in range(1,N+1):
    # If the color of node i is not yet assigned, perform DFS from this node
    if col[i]<0:
        col[i] = cnt
        que = deque([i])
        while que:
            x = que.popleft()
            # For each neighbor y of node x, if its color is not yet assigned, color it with the same color as x and add it to the queue
            for y in G[x]:
                if col[y]<0:
                    col[y]=cnt
                    que.append(y)
        # Increment the counter cnt for the next connected component
        cnt += 1

# Calculate the maximum color cmax in the graph
cmax = max(col)

# Print the maximum color cmax
print(cmax)
