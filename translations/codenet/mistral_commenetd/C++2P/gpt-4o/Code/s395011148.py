import sys

N = int(input())  # We read the value of N from the standard input
A = list(map(int, input().split()))  # We read the values of the array A from the standard input

# Initialize dp array with minimum values
dp = [[[-(1 << 60) for _ in range(20)] for _ in range(2)] for _ in range(N + 1)]

# Base case: dp[0][0][10] = 0
dp[0][0][10] = 0

# Iterate through all the elements of the array A
for i in range(1, N + 1):
    for j in range(6, 15):  # We only consider the cases where j is between 6 and 14
        if dp[i - 1][0][j] != (1 << 60):  # If dp[i-1][0][j] is not equal to the very large negative value
            dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i - 1])  # Update dp[i][1][j+1]
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j])  # Update dp[i][0][j-1]
        if dp[i - 1][1][j] != (1 << 60):  # If dp[i-1][1][j] is not equal to the very large negative value
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j])  # Update dp[i][0][j-1]

# Calculate the value of T1 and T2
V = 10 + (N // 2) - (N - (N // 2))
T1 = dp[N][0][V]
T2 = dp[N][1][V]

# Print the maximum value of T1 and T2
print(max(T1, T2))

# <END-OF-CODE>
