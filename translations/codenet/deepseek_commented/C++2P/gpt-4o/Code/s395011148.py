import sys

N = int(sys.stdin.readline().strip())
A = list(map(int, sys.stdin.readline().strip().split()))

# Step 2: Initialization
dp = [[[-(1 << 60) for _ in range(20)] for _ in range(2)] for _ in range(N + 1)]
dp[0][0][10] = 0

# Step 3: Dynamic Programming Transition
for i in range(1, N + 1):
    for j in range(6, 15):
        if dp[i - 1][0][j] != (1 << 60):
            dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i - 1])
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j])
        if dp[i - 1][1][j] != (1 << 60):
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j])

# Step 4: Calculating the Result
V = 10 + (N // 2) - (N - (N // 2))
T1 = dp[N][0][V]
T2 = dp[N][1][V]
print(max(T1, T2))

# <END-OF-CODE>
