

import sys
input = sys.stdin.readline

# Step 1: Read input values for v1, v2, t, and d.
v1, v2, t, d = map(int, input().split())

# Step 2: Initialize a 2D array dp with dimensions (t-1) x 1150, and fill it with a very small value (-1e17).
dp = [[- (1e17)] * 1150 for _ in range(t - 1)]

# Step 3: Set the initial value of dp[0][v1] to v1.
dp[0][v1] = v1

# Step 4: Iterate through the time steps from 1 to t-2.
sum = 0
for i in range(1, t - 1):
    # Step 5: For each time step, update the dp array based on the possible values of j (current position) and x (distance change).
    for j in range(1150):
        for x in range(d + 1):
            if j + x < 1150:
                dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j)
        for x in range(d, -1, -1):
            if j - x >= 0:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j)

# Step 6: After updating the dp array, find the maximum value of dp[t-2][j] + v2 where the absolute difference between j and v2 is within the range d.
ans = float('-inf')
for i in range(t - 2, t - 1):
    for j in range(1150):
        if abs(j - v2) <= d:
            ans = max(ans, dp[i][j] + v2)

# Step 7: Print the result.
print(ans)

Translate the above Python code to C++ and end with comment "