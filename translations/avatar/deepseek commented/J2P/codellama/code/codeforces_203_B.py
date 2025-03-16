
import sys

# Read the first integer input, which is the size of the grid
N = int(sys.stdin.readline().strip())

# Read the second integer input, which is the number of operations
M = int(sys.stdin.readline().strip())

# Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
black = [[0] * (N + 2) for _ in range(N + 2)]

# Loop through M operations
for m in range(1, M + 1):
    # Read the x-coordinate of the current operation
    x = int(sys.stdin.readline().strip())

    # Read the y-coordinate of the current operation
    y = int(sys.stdin.readline().strip())

    # Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
    for xx in range(x - 1, x + 2):
        for yy in range(y - 1, y + 2):
            if black[xx][yy] == 8:
                print(m)
                sys.exit()
            black[xx][yy] += 1

# If no element reaches 9 after all operations, print -1
print(-1)

