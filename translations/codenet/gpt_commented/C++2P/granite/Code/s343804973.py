
import sys

# Read input values for n, m, and mod
n, m, mod = map(int, input().split())

# Initialize the binomial coefficient array C
C = [[0] * (m + 1) for _ in range(n + 1)]
C[0][0] = 1
for i in range(1, n + 1):
    C[i][0] = C[i][i] = 1
    for j in range(1, i):
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Initialize the first row of f and pre arrays
f = [[0] * (m + 1) for _ in range(n + 1)]
pre = [[0] * (m + 1) for _ in range(n + 1)]
for i in range(m + 1):
    f[1][i] = 1
    pre[1][i] = m - i + 1

# Fill the f and pre arrays for dynamic programming
for i in range(2, n + 2):
    for j in range(m + 1):
        for k in range(1, i):
            f[i][j] = (f[i][j] + f[i - k][j] * pre[k][j + 1] * C[i - 2][k - 1]) % mod
    for j in range(m, -1, -1):
        pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod

# Output the result which is f[n + 1][0]
print(f[n + 1][0])

