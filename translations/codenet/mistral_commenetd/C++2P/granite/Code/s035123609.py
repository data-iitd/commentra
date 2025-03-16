

import sys

rr, cc, k = map(int, input().split()) # reading input dimensions and number of given values

mat = [[0] * cc for _ in range(rr)] # 2D matrix to store the given grid data

dp = [[[0] * 4 for _ in range(cc)] for _ in range(rr)] # 3D dp array to store the maximum sum of submatrices with different conditions
dpl = [0] * cc # 1D array to store the maximum sum of submatrices ending at the current column

for i in range(k): # reading given values and updating the matrix
    r, c, v = map(int, input().split())
    mat[r - 1][c - 1] = v

dp[0][0][1] = mat[0][0] # base case for a 1x1 submatrix

for y in range(rr): # iterating through each row
    for x in range(cc): # iterating through each column
        for c in range(4): # iterating through all conditions (top, left, diagonal, and bottom-left)
            v = mat[y][x] # current cell value
            q = 0
            if c == 0 or v == 0: # if the current condition is top or the cell value is zero
                q = dpl[x] if x == 0 else max(dpl[x], dp[y][x - 1][c]) # the maximum sum of submatrices ending at the current column or the maximum sum of submatrices ending at the previous column with the same condition
            else: # if the current condition is left, diagonal, or bottom-left
                q = dpl[x] + v if x == 0 else max(dpl[x] + v, max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v)) # the maximum sum of submatrices ending at the current column or the maximum sum of submatrices with the same conditions at the previous cell and the current cell
            dp[y][x][c] = q # updating the dp array with the maximum sum of submatrices with the current condition
    for x in range(cc): # updating the dpl array with the maximum sum of submatrices ending at the current column
        dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))

print(dpl[cc - 1]) # printing the maximum sum of submatrix ending at the last column
