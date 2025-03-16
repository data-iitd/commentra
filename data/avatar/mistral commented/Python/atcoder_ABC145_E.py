# Import necessary modules
import sys
from operator import itemgetter

# Define input function
input = sys.stdin.readline

# Initialize variables
TIME = 0
VAL = 1
N, T = [int(a) for a in input().split()]

# Initialize time_value list
time_value = [(-1, -1)] + [None] * N

# Read time_value for each activity
for i in range(1, N+1):
    time_value[i] = tuple(int(a) for a in input().split())

# Sort time_value based on their VAL (end time)
time_value.sort(key=itemgetter(VAL))

# Initialize dp matrix
dp = [[-1] * T for _ in range(N+1)]

# Initialize first row and column of dp matrix
for t in range(0, T):
    dp[0][t] = 0
dp[0][0] = 0
for n in range(1, N+1):
    dp[n][0] = 0

# Fill dp matrix
for n in range(1, N+1):
    for t in range(1, T):
        # If current activity's start time is greater than t, then we cannot include it in the solution
        if time_value[n][TIME] > t:
            dp[n][t] = dp[n-1][t]
        # If current activity's start time is less than or equal to t, then we can include it in the solution
        else:
            dp[n][t] = max(dp[n-1][t], time_value[n][VAL] + dp[n-1][t-time_value[n][TIME]])

# Calculate maximum value that can be obtained
val_acum = time_value[N][VAL]
t = T - 1
max_val = val_acum + dp[N-1][t]

# Calculate maximum value by considering all activities
for n in range(N-1, 0, -1):
    val_acum += time_value[n][VAL]
    t -= time_value[n+1][TIME]
    if t < 0:
        break
    else:
        max_val = max(max_val, val_acum + dp[n-1][t])

# Print the maximum value
print(max_val)
