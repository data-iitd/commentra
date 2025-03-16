
# Python 3 program to find the maximum sum of submatrix
# with different conditions

# Function to find the maximum sum of submatrix
# with different conditions
def maxSubmatrix(mat, n, m, k):

    # dp[i][j][c] stores the maximum sum of submatrix
    # ending at mat[i][j] with condition c
    dp = [[[0 for x in range(4)] for y in range(m)] for z in range(n)]

    # dpl[j] stores the maximum sum of submatrix
    # ending at last column
    dpl = [0 for x in range(m)]

    # Initialize the dp array
    for i in range(n):
        for j in range(m):
            dp[i][j][1] = mat[i][j]

    # Initialize the dpl array
    for j in range(m):
        dpl[j] = dp[0][j][1]

    # Fill the dp array
    for i in range(n):
        for j in range(m):
            for c in range(1, 4):
                if (c == 0 or mat[i][j] == 0):
                    q = (j == 0) and dpl[j] or max(dpl[j], dp[i][j - 1][c])
                else:
                    q = (j == 0) and dpl[j] + mat[i][j] or max(dpl[j] + mat[i][j], max(dp[i][j - 1][c], dp[i][j - 1][c - 1] + mat[i][j]))
                dp[i][j][c] = q

            # Update the dpl array
            dpl[j] = max(max(dp[i][j][0], dp[i][j][1]), max(dp[i][j][2], dp[i][j][3]))

    return dpl[m - 1]

# Driver Code
if __name__ == '__main__':

    # n = number of rows
    # m = number of columns
    # k = number of given values
    n, m, k = map(int, input().split())

    # mat[i][j] = value at row i and column j
    mat = [[0 for x in range(m)] for y in range(n)]

    # Read the given values
    for i in range(k):
        r, c, v = map(int, input().split())
        mat[r - 1][c - 1] = v

    # Find the maximum sum of submatrix
    print(maxSubmatrix(mat, n, m, k))

