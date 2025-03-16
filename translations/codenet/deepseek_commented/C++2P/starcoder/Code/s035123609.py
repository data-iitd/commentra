
# Define the matrix and DP arrays
mat = [[0 for x in range(3000)] for y in range(3000)]
dp = [[[0 for x in range(4)] for y in range(3000)] for z in range(3000)]
dpl = [0 for x in range(3000)]

# Read input values for rows, columns, and number of non-zero elements
rr, cc, k = map(int, raw_input().split())

# Read each non-zero element's row, column, and value, and store in the matrix
for i in range(1, k + 1):
    r, c, v = map(int, raw_input().split())
    mat[r - 1][c - 1] = v

# Initialize the DP table for the starting cell
dp[0][0][1] = mat[0][0]

# Fill the DP table
for y in range(0, rr):
    for x in range(0, cc):
        for c in range(0, 4):
            v = mat[y][x]
            q = 0
            # Update the DP table based on the current cell's value and previous values
            if c == 0 or v == 0:
                q = (x == 0) and dpl[x] or max(dpl[x], dp[y][x - 1][c])
            else:
                q = (x == 0) and dpl[x] + v or max(dpl[x] + v, max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v))
            dp[y][x][c] = q
    # Update the maximum values for each column after processing the current row
    for x in range(0, cc):
        dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))

# Output the maximum value in the last column of the last row
print dpl[cc - 1]

