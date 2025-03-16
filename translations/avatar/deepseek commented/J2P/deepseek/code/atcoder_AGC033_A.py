from collections import deque
import sys

# Read input
H = int(input())
W = int(input())

# Initialize the grid A and the queue for BFS
A = [list(input()) for _ in range(H)]
queue = deque()

# Initialize the queue with positions of '#' characters
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            queue.append([i, j, 0])

# Initialize a flag array to keep track of visited cells
flag = [[0] * W for _ in range(H)]
ans = 0  # Variable to store the maximum distance

# Directions for moving in the grid (right, left, down, up)
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# Perform BFS to find the maximum distance from any '#' to a '.'
while queue:
    temp = queue.popleft()  # Remove the first element from the queue
    y, x, depth = temp

    # Check all four possible directions
    for i in range(4):
        if 0 <= y + dy[i] < H and 0 <= x + dx[i] < W:
            if flag[y + dy[i]][x + dx[i]] == 0 and A[y + dy[i]][x + dx[i]] == '.':
                flag[y + dy[i]][x + dx[i]] = 1  # Mark the cell as visited
                queue.append([y + dy[i], x + dx[i], depth + 1])  # Add the new position to the queue
                ans = max(ans, depth + 1)  # Update the maximum distance

# Output the maximum distance found
print(ans)
