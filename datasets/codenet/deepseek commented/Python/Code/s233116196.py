from collections import deque

# Step 1: Read the number of nodes (N) and the number of edges (M)
N, M = map(int, input().split())

# Step 2: Initialize the graph as a dictionary where each node is a key and its value is a list of adjacent nodes
G = {i: [] for i in range(1, N + 1)}

# Step 3: Construct the graph by reading each edge (a, b) and adding it to the graph
for _ in range(M):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)

# Step 4: Initialize the color array where each node is set to -1 (uncolored)
col = [-1 for _ in range(N + 1)]

# Step 5: Initialize a counter to keep track of the number of connected components
cnt = 0

# Step 6: Iterate over each node to color the graph using BFS
for i in range(1, N + 1):
    if col[i] < 0:  # If the node is uncolored
        col[i] = cnt  # Assign a new color to this node
        que = deque([i])  # Initialize a queue with the current node
        while que:  # Perform BFS
            x = que.popleft()  # Get the next node from the queue
            for y in G[x]:  # Iterate over all adjacent nodes
                if col[y] < 0:  # If the adjacent node is uncolored
                    col[y] = cnt  # Assign the current color to this node
                    que.append(y)  # Add the adjacent node to the queue
        cnt += 1  # Increment the component counter

# Step 7: Find the maximum color value which represents the number of connected components
cmax = max(col)

# Step 8: Print the number of connected components
print(cmax)
