import sys

# Define a large enough matrix to store the given grid data
mat = [[0] * 3000 for _ in range(3000)] 

# 3D list to store the maximum sum of submatrices with different conditions
dp = [[[0] * 4 for _ in range(3000)] for _ in range(3000)] 
# 1D list to store the maximum sum of submatrices ending at the current column
dpl = [0] * 3000 

def main():
    rr, cc, k = map(int, sys.stdin.readline().split())  # reading input dimensions and number of given values

    for _ in range(k):  # reading given values and updating the matrix
        r, c, v = map(int, sys.stdin.readline().split())
        mat[r - 1][c - 1] = v

    dp[0][0][1] = mat[0][0]  # base case for a 1x1 submatrix

    for y in range(rr):  # iterating through each row
        for x in range(cc):  # iterating through each column
            for c in range(4):  # iterating through all conditions (top, left, diagonal, and bottom-left)
                v = mat[y][x]  # current cell value
                if c == 0 or v == 0:  # if the current condition is top or the cell value is zero
                    q = dpl[x] if x == 0 else max(dpl[x], dp[y][x - 1][c])  # maximum sum of submatrices
                else:  # if the current condition is left, diagonal, or bottom-left
                    q = (dpl[x] + v) if x == 0 else max(dpl[x] + v, max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v))  # maximum sum of submatrices
                dp[y][x][c] = q  # updating the dp array with the maximum sum of submatrices with the current condition

        for x in range(cc):  # updating the dpl array with the maximum sum of submatrices ending at the current column
            dpl[x] = max(max(dp[y][x][0], dp[y][x][1]), max(dp[y][x][2], dp[y][x][3]))

    print(dpl[cc - 1])  # printing the maximum sum of submatrix ending at the last column

if __name__ == "__main__":
    main()

# <END-OF-CODE>
