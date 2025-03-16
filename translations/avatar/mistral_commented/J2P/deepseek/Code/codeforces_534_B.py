import sys

# Reading input variables from the user
v1 = int(input().strip())  # Reading the first integer value
v2 = int(input().strip())  # Reading the second integer value
t = int(input().strip())  # Reading the number of time steps
d = int(input().strip())  # Reading the maximum difference between two consecutive values

# Creating a 2D list dp of size (t-1) x 1150 for dynamic programming table
dp = [[float('-inf')] * 1150 for _ in range(t - 1)]

# Initializing the first row of the dp table with the given value
dp[0][v1] = v1

# Filling the dp table using dynamic programming
for i in range(1, t - 1):
    for j in range(1150):
        for x in range(d + 1):
            if j + x < 1150:
                dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j)
        for x in range(d, -1, -1):
            if j - x >= 0:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j)

# Finding the maximum value that can be obtained by jumping from any cell in the last but one row to the last row and adding the value of the last cell of the last row
ans = float('-inf')
for j in range(1150):
    if abs(j - v2) <= d:
        ans = max(ans, dp[-2][j] + v2)

# Printing the final answer
print(ans)
