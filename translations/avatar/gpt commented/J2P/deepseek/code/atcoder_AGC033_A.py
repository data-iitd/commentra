from collections import deque
import sys

# Read the height (H) and width (W) of the grid
H, W = map(int, input().split())

# Initialize a 2D character array to store the grid
A = [list(input().strip()) for _ in range(H)]

# Initialize a queue to perform BFS (Breadth-First Search)
queue = deque()

# Read the grid input and populate the character array
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            queue.append((i, j, 0))  # Store the position and initial depth

# Initialize a flag array to track visited cells
flag = [[0] * W for _ in range(H)]

# Variable to store the maximum depth reached
ans = 0

# Direction vectors for moving up, down, left, and right
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# Perform BFS until the queue is empty
while queue:
    y, x, depth = queue.popleft()  # Remove the front element from the queue

    # Explore all four possible directions
    for i in range(4):
        # Calculate new coordinates
        newY = y + dy[i]
        newX = x + dx[i]

        # Check if the new coordinates are within bounds
        if 0 <= newY < H and 0 <= newX < W:
            # Check if the cell has not been visited and is an empty space ('.')
            if flag[newY][newX] == 0 and A[newY][newX] == '.':
                flag[newY][newX] = 1  # Mark the cell as visited
                queue.append((newY, newX, depth + 1))  # Prepare the new position and updated depth
                ans = depth + 1  # Update the maximum depth reached

# Output the maximum depth reached
print(ans)
