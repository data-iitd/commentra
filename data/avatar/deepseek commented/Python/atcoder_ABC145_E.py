import sys
from operator import itemgetter
input = sys.stdin.readline
TIME = 0
VAL = 1

# Reading Input: The code starts by reading the number of items N and the maximum time T.
N, T = [int(a) for a in input().split()]

# Initializing Data Structures: It initializes a list time_value to store the time and value of each item, with a placeholder at index 0.
time_value = [(-1, -1)] + [None] * (N)

# Reading Item Details: It reads the time and value for each item and stores them in time_value.
for i in range(1, N + 1):
    time_value[i] = tuple(int(a) for a in input().split())

# Sorting Items: The items are sorted based on their value.
time_value.sort(key=itemgetter(VAL))

# Dynamic Programming Table Initialization: A 2D list dp is initialized to store the maximum value that can be achieved with a given number of items and time.
dp = [[-1] * T for _ in range(N + 1)]

# Base Cases for DP Table: The base cases are set where no time means no value.
for t in range(0, T):
    dp[0][t] = 0

for n in range(1, N + 1):
    dp[n][0] = 0
    for t in range(1, T):
        if time_value[n][TIME] > t:
            dp[n][t] = dp[n - 1][t]
        else:
            dp[n][t] = max(dp[n - 1][t], time_value[n][VAL] + dp[n - 1][t - time_value[n][TIME]])

# Calculating Maximum Value: The maximum value is calculated by considering the last item and reducing the time accordingly.
val_acum = time_value[N][VAL]
t = T - 1
max_val = val_acum + dp[N - 1][t]

for n in range(N - 1, 0, -1):
    val_acum += time_value[n][VAL]
    t -= time_value[n + 1][TIME]
    if t < 0:
        break
    else:
        max_val = max(max_val, val_acum + dp[n - 1][t])

# Printing Result: The final maximum value is printed.
print(max_val)
