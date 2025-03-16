import sys

# Read input
N = int(input())
A = list(map(int, input().split()))

# Initialize dp array with minimum values
dp = [[[-sys.maxsize] * 20 for _ in range(2)] for _ in range(N + 1)]

# Base case: dp[0][0][10] = 0
dp[0][0][10] = 0

# Iterate through all the elements of the array A
for i in range(1, N + 1):
    for j in range(6, 15):  # We only consider the cases where j is between 6 and 14
        if dp[i - 1][0][j] != -sys.maxsize:
            dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i - 1])
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j])
        if dp[i - 1][1][j] != -sys.maxsize:
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j])

# Calculate the value of T1 and T2
V = 10 + (N // 2) - (N - (N // 2))
T1 = dp[N][0][V]
T2 = dp[N][1][V]

# Print the maximum value of T1 and T2
print(max(T1, T2))

# <END-OF-CODE>