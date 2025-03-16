import sys

# 2D matrix to store the given grid data
mat = [[0] * 3000 for _ in range(3000)]

# 3D dp array to store the maximum sum of submatrices with different conditions
dp = [[[0] * 4 for _ in range(3000)] for _ in range(3000)]

# 1D array to store the maximum sum of submatrices ending at the current column
dpl = [0] * 3000

# Reading input dimensions and number of given values
rr, cc, k = map(int, sys.stdin.readline().split())

# Reading given values and updating the matrix
for _ in range(k):
    r, c, v = map(int, sys.stdin.readline().split())
    mat[r - 1][c - 1] = v

# Base case for a 1x1 submatrix
dp[0][0][1] = mat[0][0]

# Iterating through each row
for y in range(rr):
    # Iterating through each column
    for x in range(cc):
        # Iterating through all conditions (top, left, diagonal, and bottom-left)
        for c in range(4):
            v = mat[y][x]  # Current cell value
            q = 0
            if c == 0 or v == 0:
                # If the current condition is top or the cell value is zero
                q = dpl[x] if x == 0 else max(dpl[x], dp[y][x - 1][c])
            else:
                # If the current condition is left, diagonal, or bottom-left
                q = dpl[x] + v if x == 0 else max(dpl[x] + v, max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v))
            dp[y][x][c] = q  # Updating the dp array with the maximum sum of submatrices with the current condition
        # Updating the dpl array with the maximum sum of submatrices ending at the current column
        dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))

# Printing the maximum sum of submatrix ending at the last column
print(dpl[cc - 1])
