
# We include the algorithm library to use functions like max()
from math import inf

N = int(input()) # We read the value of N from the standard input
A = [0] * (1 << 18) # We declare the array A of size (1 << 18)
for i in range(1, N + 1): A[i] = int(input()) # We read the values of the array A from the standard input

# Initialize dp array with minimum values
dp = [[[inf] * 20 for _ in range(2)] for _ in range(1 << 18)]

# Base case: dp[0][0][10] = 0
dp[0][0][10] = 0

# Iterate through all the elements of the array A
for i in range(1, N + 1):
	for j in range(6, 14 + 1): # We only consider the cases where j is between 6 and 14
		if dp[i - 1][0][j]!= inf: # If dp[i-1][0][j] is not equal to infinity
			dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]) # Update dp[i][1][j+1] with the maximum of its current value and dp[i-1][0][j] + A[i]
			dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j]) # Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][0][j]
		if dp[i - 1][1][j]!= inf: # If dp[i-1][1][j] is not equal to infinity
			dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j]) # Update dp[i][0][j-1] with the maximum of its current value and dp[i-1][1][j]

# Calculate the value of T1 and T2
V = 10 + (N // 2) - (N - (N // 2))
T1 = dp[N][0][V]
T2 = dp[N][1][V]

# Print the maximum value of T1 and T2
print(max(T1, T2))

