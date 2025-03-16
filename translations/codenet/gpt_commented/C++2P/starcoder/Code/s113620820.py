
# 2415.py
# Sashimi
# <NAME>
# 2017-02-01

# <BEGIN-OF-CODE>

# Python 3.5.2

# Maximum number of items
MAX_N = 4000

# Define ll as a long long type
ll = int

# Define a large constant for initialization
LINF = 1 << 60

# Arrays for weights, prefix sums, and dynamic programming table
wis = [0] * MAX_N
wsums = [0] * (MAX_N + 1)
dp = [[LINF] * (MAX_N + 1) for _ in range(MAX_N)]
ks = [[-1] * (MAX_N + 1) for _ in range(MAX_N)]

# Number of items
n = int(input())

# Initialize prefix sums
wsums[0] = 0
for i in range(n):
  wis[i] = int(input())
  wsums[i + 1] = wsums[i] + wis[i]

# Initialize the dynamic programming and split point tables
for i in range(n):
  for j in range(n + 1):
    dp[i][j] = LINF
    ks[i][j] = -1

# Fill the dynamic programming table
for l in range(2, n + 1):
  for i in range(n):
    j = i + l
    if j > n:
      break
    mind = LINF
    wsum = wsums[j] - wsums[i]
    mink = -1
    for k in range(ks[i][j - 1], ks[i + 1][j] + 1):
      d = dp[i][k] + dp[k][j] + wsum
      if mind > d:
        mind = d
        mink = k
    dp[i][j] = mind
    ks[i][j] = mink

# Output the minimum cost to combine all items
print(dp[0][n])

# 