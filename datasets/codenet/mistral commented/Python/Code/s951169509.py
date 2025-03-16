# Import the collections module
from collections import deque

# Define the height and width of the grid
H, W = map(int, input().split())

# Initialize the grid `G` with the given input and add a border of '#'
G = []
for i in range(H+2):
    if i == 0 or i == H+1:
        G.append('#'*(W+2))
    else:
        G.append('#' + input() + '#')

# Initialize the variable `ans` to 0
ans = 0

# Use a nested loop to iterate through all the cells in the grid and find the shortest path from the source cell to each cell using BFS algorithm
for sx in range(W+2):
    for sy in range(H+2):
        if G[sy][sx] == '.':
            # Initialize the distance matrix `dist` with negative infinity and visited matrix `visited` with -1
            dist = [[-float('inf') for i in range(W+2)] for i in range(H+2)]
            visited = [[-1 for i in range(W+2)] for i in range(H+2)]
            # Initialize a queue `q` and append the source cell to it
            q = deque([])
            q.append((sx, sy))
            dist[sy][sx] = 0
            visited[sy][sx] = 1
            # Use a while loop to perform BFS algorithm
            while q:
                x, y = q.popleft()

                # Check the neighboring cells and update their distances if they are unvisited and connected to the current cell
                if G[y][x+1] == '.' and visited[y][x+1] == -1:
                    q.append((x+1, y))
                    dist[y][x+1] = dist[y][x] + 1
                    visited[y][x+1] = 1

                if G[y][x-1] == '.' and visited[y][x-1] == -1:
                    q.append((x-1, y))
                    dist[y][x-1] = dist[y][x] + 1
                    visited[y][x-1] = 1

                if G[y+1][x] == '.' and visited[y+1][x] == -1:
                    q.append((x, y+1))
                    dist[y+1][x] = dist[y][x] + 1
                    visited[y+1][x] = 1

                if G[y-1][x] == '.' and visited[y-1][x] == -1:
                    q.append((x, y-1))
                    dist[y-1][x] = dist[y][x] + 1
                    visited[y-1][x] = 1
            # Update the maximum distance `ans` with the maximum distance found in the current iteration
            for i in range(W+2):
                for j in range(H+2):
                    ans = max(ans, dist[j][i])

# Print the maximum distance `ans` as the output
print(ans)