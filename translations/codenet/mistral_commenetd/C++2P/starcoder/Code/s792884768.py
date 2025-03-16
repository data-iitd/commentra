
# Python 3 program to solve MCM problem using
# Dynamic Programming

# A Dynamic Programming based
# function to solve MCM problem

# Returns the minimum number of multiplications
# needed to multiply the matrices A[][] and B[][]
def mcm(A, B, m, n, o, p):

    # Create a table to store results of subproblems
    dp = [[0 for x in range(p + 1)] for x in range(o + 1)]

    # Fill d[][] in bottom up manner
    for i in range(o + 1):
        for j in range(p + 1):

            # Base case (If given matrix is empty)
            if (i == 0 or j == 0):
                dp[i][j] = 0

            # If given matrix has only one row or
            # only one column
            elif (i == 1 or j == 1):
                dp[i][j] = 0

            # To get minimum number of multiplications,
            # we need to consider all submatrices
            # of the given matrix. The following
            # recursive formula calculates minimum
            # number of multiplications needed to
            # multiply A[0..x][0..y] and B[0..x][0..y]
            else:
                dp[i][j] = INT_MAX
                for x in range(1, i):
                    for y in range(1, j):
                        dp[i][j] = min(dp[i][j], dp[x][y] +
                                       dp[i - x][j - y] + A[x - 1][y - 1] * B[i - x][j - y])

    return dp[o][p]


# Driver program to test above function
A = [[1, 2, 3],
     [4, 5, 6]]

B = [[1, 2],
     [3, 4],
     [5, 6]]

m = 2
n = 3
o = 3
p = 2

print(mcm(A, B, m, n, o, p))

