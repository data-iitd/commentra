import sys

# Read input values
n, m, mod = map(int, sys.stdin.readline().split())

# Initialize the binomial coefficient table
C = [[0] * 310 for _ in range(310)]
C[0][0] = 1

# Compute binomial coefficients using nested loops
for i in range(1, 310):
    C[i][0] = C[i][i] = 1
    for j in range(1, i):
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Initialize the dynamic programming table
f = [[0] * 310 for _ in range(310)]
pre = [[0] * 310 for _ in range(310)]
for i in range(m + 1):
    f[1][i] = 1
    pre[1][i] = m - i + 1

# Compute the dynamic programming table
for i in range(2, n + 2):
    for j in range(m + 1):
        for k in range(1, i):
            f[i][j] = (f[i][j] + f[i - k][j] * pre[k][j + 1] * C[i - 2][k - 1]) % mod
    for j in range(m, -1, -1):
        pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod

# Output the result
print(f[n + 1][0])
