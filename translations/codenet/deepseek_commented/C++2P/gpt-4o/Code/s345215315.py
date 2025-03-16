import sys
from collections import deque

# Type definitions for convenience
EPS = 1e-10
INF = int(1e9)
MOD = 1000000007

# Global variables for the problem
ans = INF  # Variable to store the minimum number of moves
h, w = 19, 15  # Dimensions of the grid
dx = [0, 1, 0, -1, 1, 1, -1, -1]  # Direction vectors for x-axis
dy = [1, 0, -1, 0, 1, -1, 1, -1]  # Direction vectors for y-axis
s = [input().strip() for _ in range(h)]  # 2D grid representation

# Depth-First Search (DFS) function to explore the grid
def dfs(x, y, cnt):
    global ans
    # Base case: if the count exceeds 20, stop the search
    if cnt > 20:
        return

    # Check if the bottom row is reached
    if x == h - 1:
        ans = min(ans, cnt)  # Update the answer with the minimum moves
        return

    # Explore all 8 possible directions
    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]  # New coordinates
        # Check if the new coordinates are within bounds
        if nx < 0 or nx >= h or ny < 0 or ny >= w:
            continue
        # Check if the current cell is not blocked
        if s[nx][ny] != 'X':
            continue

        c = True  # Flag to control the loop
        # Move in the current direction while possible
        while c and s[nx][ny] == 'X':
            s[nx] = s[nx][:ny] + '.' + s[nx][ny + 1:]  # Mark the cell as visited
            nx += dx[i]  # Move to the next cell in the direction
            ny += dy[i]
            # Check if the new coordinates are out of bounds
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                if nx >= h:
                    ans = min(ans, cnt + 1)  # Update answer if out of bounds
                c = False  # Stop the loop

        # Recursive DFS call for the new position
        if c:
            dfs(nx, ny, cnt + 1)
        # Backtrack: restore the grid to its previous state
        while nx != x or ny != y:
            nx -= dx[i]
            ny -= dy[i]
            s[nx] = s[nx][:ny] + 'X' + s[nx][ny + 1:]  # Restore the cell
        s[x] = s[x][:y] + '.' + s[x][y + 1:]  # Mark the original cell as visited

# Find the starting position 'O' and mark it as visited
for i in range(h):
    for j in range(w):
        if s[i][j] == 'O':
            sx, sy = i, j  # Store the starting position
            s[i] = s[i][:j] + '.' + s[i][j + 1:]  # Mark the starting position as visited

# Start DFS from the initial position
dfs(sx, sy, 0)

# Output the result: minimum moves or -1 if not reachable
if ans == INF:
    print(-1)
else:
    print(ans)

# <END-OF-CODE>
