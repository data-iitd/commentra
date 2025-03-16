

# Read input values
n, m, mod = map(int, input().split())

# Initialize C array with base cases
C = [[0 for _ in range(310)] for _ in range(310)]
C[0][0] = 1
for i in range(1, n+1):
    C[i][0] = C[i][i] = 1
    for j in range(1, i):
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod

# Initialize f and pre arrays for base case
f = [[0 for _ in range(310)] for _ in range(310)]
pre = [[0 for _ in range(310)] for _ in range(310)]
for i in range(1, n+2):
    f[i][0] = 1
    pre[i][0] = m-i+2

# Calculate f and pre arrays for all other rows
for i in range(2, n+2):
    for j in range(m+1):
        for k in range(1, i):
            f[i][j] = (f[i][j] + f[i-k][j] * pre[k][j+1] * C[i-2][k-1]) % mod
    for j in range(m, -1, -1):
        pre[i][j] = (pre[i][j+1] + f[i][j]) % mod

# Print the result
print(f[n+1][0])

# The code is now commented and easy to understand.

