

import queue

# Read the number of rows and columns from the input
H, W = map(int, input().split())

# Initialize a 2D list 'A' to store the input grid
A = [list(input()) for _ in range(H)]

# Initialize a queue to store the cells to be processed
q = queue.Queue()

# Read the grid and initialize the queue with the starting points of 'B'
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            q.put((i, j, 0))

# Initialize a 2D list 'flag' to mark the visited cells
flag = [[0] * W for _ in range(H)]

# Initialize variables for the answer and the directions
ans = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# Process the queue and find the answer
while not q.empty():
    y, x, depth = q.get()

    # Process the neighboring cells
    for i in range(4):
        newY = y + dy[i]
        newX = x + dx[i]

        # If the cell is within the grid and hasn't been visited yet,
        # and contains a '.', mark it as visited and add it to the queue
        if 0 <= newY < H and 0 <= newX < W and flag[newY][newX] == 0 and A[newY][newX] == '.':
            flag[newY][newX] = 1
            q.put((newY, newX, depth + 1))
            ans = max(ans, depth + 1)

# Print the answer
print(ans)

These comments should provide a clear understanding of the code's logic and purpose. Let me know if you need any further clarification.