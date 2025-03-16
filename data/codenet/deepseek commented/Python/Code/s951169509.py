from collections import deque

# Step 1: Input Reading
# Read the dimensions of the grid H (height) and W (width) from the input.
H, W = map(int, input().split())

# Initialize an empty list G to store the grid.
G = []

# Add a border of '#' around the grid.
for i in range(H+2):
    if i == 0 or i == H+1:
        G.append('#'*(W+2))
    else:
        G.append('#' + input() + '#')

# Step 2: Initialize Variables
# Initialize ans to 0 to keep track of the maximum distance found.
ans = 0

# Step 3: Iterate Over Grid
# Iterate over each cell in the grid, starting from the top-left corner.
for sx in range(W+2):
    for sy in range(H+2):
        if G[sy][sx] == '.':
            # Initialize distance and visited lists for the current cell.
            dist = [[-float('inf') for _ in range(W+2)] for _ in range(H+2)]
            visited = [[-1 for _ in range(W+2)] for _ in range(H+2)]
            
            # Initialize a deque and append the current cell to it.
            q = deque([])
            q.append((sx, sy))
            
            # Set the distance to the current cell to 0 and mark it as visited.
            dist[sy][sx] = 0
            visited[sy][sx] = 1
            
            # Step 4: BFS for Each Starting Point
            # Perform BFS from the current cell.
            while q:
                x, y = q.popleft()
                
                # Check and update the distance and visit status for the right neighbor.
                if G[y][x+1] == '.' and visited[y][x+1] == -1:
                    q.append((x+1, y))
                    dist[y][x+1] = dist[y][x] + 1
                    visited[y][x+1] = 1
                
                # Check and update the distance and visit status for the left neighbor.
                if G[y][x-1] == '.' and visited[y][x-1] == -1:
                    q.append((x-1, y))
                    dist[y][x-1] = dist[y][x] + 1
                    visited[y][x-1] = 1
                
                # Check and update the distance and visit status for the below neighbor.
                if G[y+1][x] == '.' and visited[y+1][x] == -1:
                    q.append((x, y+1))
                    dist[y+1][x] = dist[y][x] + 1
                    visited[y+1][x] = 1
                
                # Check and update the distance and visit status for the above neighbor.
                if G[y-1][x] == '.' and visited[y-1][x] == -1:
                    q.append((x, y-1))
                    dist[y-1][x] = dist[y][x] + 1
                    visited[y-1][x] = 1
            
            # Step 5: Output the Result
            # Update ans with the maximum distance found.
            for i in range(W+2):
                for j in range(H+2):
                    ans = max(ans, dist[j][i])

# Print the maximum distance found.
print(ans)
