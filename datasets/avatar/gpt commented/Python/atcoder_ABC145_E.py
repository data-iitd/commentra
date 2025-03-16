import sys
from operator import itemgetter

# Read input from standard input
input = sys.stdin.readline

# Constants to represent indices for time and value
TIME = 0
VAL = 1

# Read the number of items (N) and the maximum time (T)
N, T = [int(a) for a in input().split()]

# Initialize a list to store time and value pairs, starting with a dummy entry
time_value = [(-1, -1)] + [None] * (N)

# Read the time and value pairs for each item
for i in range(1, N + 1):
    time_value[i] = tuple(int(a) for a in input().split())

# Sort the time_value list based on the value (VAL)
time_value.sort(key=itemgetter(VAL))

# Initialize a 2D list for dynamic programming, with -1 as default values
dp = [[-1] * T for _ in range(N + 1)]

# Base case: If time is 0, the maximum value is 0 for all items
for t in range(0, T):
    dp[0][t] = 0

# Fill the dynamic programming table
for n in range(1, N + 1):
    # Base case: If no time is available, the maximum value is 0
    dp[n][0] = 0
    for t in range(1, T):
        # If the current item's time exceeds the available time, skip the item
        if time_value[n][TIME] > t:
            dp[n][t] = dp[n - 1][t]
        else:
            # Choose the maximum between not taking the item and taking it
            dp[n][t] = max(dp[n - 1][t], time_value[n][VAL] + dp[n - 1][t - time_value[n][TIME]])

# Initialize the maximum value with the last item's value
val_acum = time_value[N][VAL]
t = T - 1
max_val = val_acum + dp[N - 1][t]

# Backtrack to find the maximum value considering previous items
for n in range(N - 1, 0, -1):
    val_acum += time_value[n][VAL]
    t -= time_value[n + 1][TIME]
    
    # If time goes negative, break the loop
    if t < 0:
        break
    else:
        # Update the maximum value if a better option is found
        max_val = max(max_val, val_acum + dp[n - 1][t])

# Print the maximum value achievable within the given time
print(max_val)
