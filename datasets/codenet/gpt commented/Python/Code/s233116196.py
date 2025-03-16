from collections import deque

# Read the number of nodes (N) and edges (M) from input
N, M = map(int, input().split())

# Initialize the graph as an adjacency list
G = {i: [] for i in range(1, N + 1)}

# Read the edges and populate the graph
for _ in range(M):
    a, b = map(int, input().split())
    G[a].append(b)  # Add edge from a to b
    G[b].append(a)  # Add edge from b to a (undirected graph)

# Initialize a list to keep track of the color (or component) of each node
col = [-1 for _ in range(N + 1)]

# Initialize a counter for the number of connected components
cnt = 0

# Iterate through each node to find connected components
for i in range(1, N + 1):
    # If the node has not been colored (visited)
    if col[i] < 0:
        col[i] = cnt  # Assign the current component number
        que = deque([i])  # Initialize a queue for BFS with the current node
        
        # Perform BFS to color all reachable nodes in the component
        while que:
            x = que.popleft()  # Dequeue a node
            for y in G[x]:  # Check all adjacent nodes
                if col[y] < 0:  # If the adjacent node has not been colored
                    col[y] = cnt  # Color it with the current component number
                    que.append(y)  # Enqueue the adjacent node for further exploration
        
        cnt += 1  # Increment the component counter after finishing one component

# Find the maximum component number (which represents the number of connected components)
cmax = max(col)

# Print the maximum component number
print(cmax)
