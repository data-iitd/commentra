from collections import deque

# Read the dimensions of the grid (H: height, W: width)
H, W = map(int, input().split())

# Initialize the grid with walls ('#') and input the inner part of the grid
G = []
for i in range(H + 2):
    if i == 0 or i == H + 1:
        # Add a row of walls at the top and bottom
        G.append('#' * (W + 2))
    else:
        # Add walls on the left and right sides of the input row
        G.append('#' + input() + '#')

# Variable to store the maximum distance found
ans = 0

# Iterate through each cell in the grid
for sx in range(W + 2):
    for sy in range(H + 2):
        # Check if the current cell is an empty space ('.')
        if G[sy][sx] == '.':
            # Initialize distance and visited matrices
            dist = [[-float('inf') for i in range(W + 2)] for i in range(H + 2)]
            visited = [[-1 for i in range(W + 2)] for i in range(H + 2)]
            
            # Initialize the queue for BFS and set the starting point
            q = deque([])
            q.append((sx, sy))
            dist[sy][sx] = 0  # Distance to the starting point is 0
            visited[sy][sx] = 1  # Mark the starting point as visited
            
            # Perform BFS to explore the grid
            while q:
                x, y = q.popleft()  # Get the current position from the queue

                # Check the right cell
                if G[y][x + 1] == '.' and visited[y][x + 1] == -1:
                    q.append((x + 1, y))  # Add to queue
                    dist[y][x + 1] = dist[y][x] + 1  # Update distance
                    visited[y][x + 1] = 1  # Mark as visited

                # Check the left cell
                if G[y][x - 1] == '.' and visited[y][x - 1] == -1:
                    q.append((x - 1, y))  # Add to queue
                    dist[y][x - 1] = dist[y][x] + 1  # Update distance
                    visited[y][x - 1] = 1  # Mark as visited

                # Check the bottom cell
                if G[y + 1][x] == '.' and visited[y + 1][x] == -1:
                    q.append((x, y + 1))  # Add to queue
                    dist[y + 1][x] = dist[y][x] + 1  # Update distance
                    visited[y + 1][x] = 1  # Mark as visited

                # Check the top cell
                if G[y - 1][x] == '.' and visited[y - 1][x] == -1:
                    q.append((x, y - 1))  # Add to queue
                    dist[y - 1][x] = dist[y][x] + 1  # Update distance
                    visited[y - 1][x] = 1  # Mark as visited
            
            # Update the maximum distance found
            for i in range(W + 2):
                for j in range(H + 2):
                    ans = max(ans, dist[j][i])  # Keep track of the maximum distance

# Print the maximum distance found
print(ans)
