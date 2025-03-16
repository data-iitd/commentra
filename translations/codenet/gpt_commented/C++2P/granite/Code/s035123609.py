
import sys

# Read the number of rows (rr), columns (cc), and the number of values (k)
rr, cc, k = map(int, input().split())

# Declare a matrix to store values
mat = [[0] * cc for _ in range(rr)]

# Declare a 3D dynamic programming array
dp = [[[0] * 4 for _ in range(cc)] for _ in range(rr)]
# Declare a 1D array to store maximum values for each column
dpl = [0] * cc

# Input the values into the matrix
for i in range(k):
    r, c, v = map(int, input().split())
    # Store the value in the matrix (adjusting for 0-based indexing)
    mat[r - 1][c - 1] = v

# Initialize the dynamic programming array with the value at the starting position
dp[0][0][1] = mat[0][0]

# Iterate through each cell in the matrix
for y in range(rr):
    for x in range(cc):
        # Iterate through the four possible states (c)
        for c in range(4):
            v = mat[y][x]  # Get the current cell value
            q = 0  # Variable to store the computed maximum value

            # Check if we are at the first column or if the current value is zero
            if c == 0 or v == 0:
                # If at the first column, take the value from dpl, else take the maximum from previous states
                q = dpl[x] if x == 0 else max(dpl[x], dp[y][x - 1][c])
            else:
                # If not at the first column, calculate the maximum considering the current value
                q = dpl[x] + v if x == 0 else max(dpl[x] + v, max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v))
            # Store the computed maximum value in the dp array
            dp[y][x][c] = q
        # Update the dpl array with the maximum values from the current row
        dpl = [max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3])] if x == 0 else [max(dpl[x], dp[y][x][0]), max(dpl[x], dp[y][x][1]), max(dpl[x], dp[y][x][2]), max(dpl[x], dp[y][x][3])]

# Output the maximum value found in the last column
print(dpl[-1])

