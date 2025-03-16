
import sys

# Reading input variables from the user
v1 = int(input()) # Reading the first integer value
v2 = int(input()) # Reading the second integer value
t = int(input()) # Reading the number of time steps
d = int(input()) # Reading the maximum difference between two consecutive values

dp = [[-sys.maxsize] * 1150 for _ in range(t - 1)] # Creating a 2D list dp of size (t-1) x 1150 for dynamic programming table

# Initializing the first row of the dp table with the given value
for i in range(t - 1):
    dp[i][v1] = v1 # Setting the value of the cell (i, v1) to v1

sum = 0 # Initializing a variable sum to 0

# Filling the dp table using dynamic programming
for i in range(1, t - 1):
    for j in range(1150):
        for x in range(d + 1):
            dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j) # Filling the current cell with the maximum value of itself and the sum of the previous cell and the current element plus the jump
        for x in range(d, -1, -1):
            dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j) # Filling the current cell with the maximum value of itself and the sum of the previous cell and the current element minus the jump
    sum += dp[i][1149] # Adding the value of the last cell of the current row to the sum

ans = -sys.maxsize # Initializing a variable ans with minimum long value

# Finding the maximum value that can be obtained by jumping from any cell in the last but one row to the last row and adding the value of the last cell of the last row
for i in range(t - 2, t - 1):
    for j in range(1150):
        if abs(j - v2) <= d: # Checking if the absolute difference between j and v2 is less than or equal to d
            ans = max(ans, dp[i][j] + v2) # Updating the value of ans with the maximum of itself and the sum of the current cell and v2

print(ans) # Printing the final answer

