
import sys

# Create a Scanner object to read input from the standard input
sc = sys.stdin

# Read the number of rows and columns from the input
H, W = map(int, sc.readline().split())

# Initialize a 2D char array 'A' to store the input grid
A = [list(sc.readline().strip()) for i in range(H)]

# Initialize a Queue to store the cells to be processed
queue = []

# Read the grid and initialize the queue with the starting points of 'B'
for i in range(H):
    row = sc.readline().strip()
    for j in range(W):
        if A[i][j] == '#':
            start = [i, j, 0]
            queue.append(start)

# Initialize a 2D int array 'flag' to mark the visited cells
flag = [[0 for j in range(W)] for i in range(H)]

# Initialize variables for the answer and the directions
ans = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# Process the queue and find the answer
while queue:
    temp = queue.pop(0)
    y = temp[0]
    x = temp[1]
    depth = temp[2]

    # Process the neighboring cells
    for i in range(4):
        newY = y + dy[i]
        newX = x + dx[i]

        # If the cell is within the grid and hasn't been visited yet,
        # and contains a '.', mark it as visited and add it to the queue
        if 0 <= newY and newY <= H - 1 and 0 <= newX and newX <= W - 1:
            if flag[newY][newX] == 0 and A[newY][newX] == '.':
                flag[newY][newX] = 1
                queue_add = [newY, newX, depth + 1]
                queue.append(queue_add)
                ans = max(ans, depth + 1)

# Print the answer
print(ans)

