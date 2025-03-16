import sys

# Read input
rr, cc, k = map(int, input().split())
mat = [[0] * cc for _ in range(rr)]
dp = [[[0] * 4 for _ in range(cc)] for _ in range(rr)]
dpl = [0] * cc

# Read the matrix values
for _ in range(k):
    r, c, v = map(int, input().split())
    mat[r - 1][c - 1] = v

# Initialize the dp array
dp[0][0][1] = mat[0][0]

# Fill the dp array
for y in range(rr):
    for x in range(cc):
        for c in range(4):
            v = mat[y][x]
            if c == 0 or v == 0:
                q = dp[y][x - 1][c] if x > 0 else dpl[x]
            else:
                q = max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v) if x > 0 else dpl[x] + v
            dp[y][x][c] = q
    # Update dpl array
    for x in range(cc):
        dpl[x] = max(dp[y][x][0], dp[y][x][1], dp[y][x][2], dp[y][x][3])

# Output the result
print(dpl[cc - 1])
