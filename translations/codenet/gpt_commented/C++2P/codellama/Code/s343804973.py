#include<cstdio>
#define int long long

# Declare global variables
n, m, mod, C = [[0] * 310] * 310, [[0] * 310] * 310, [[0] * 310] * 310, [[0] * 310] * 310

# Initialize the binomial coefficient array C
C[0][0] = 1 # Base case: C(0, 0) = 1
for i in range(1, n + 1):
    C[i][0] = C[i][i] = 1 # C(i, 0) = C(i, i) = 1 for all i
    for j in range(1, i):
        # Calculate C(i, j) using the recursive relation
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Initialize the first row of f and pre arrays
for i in range(0, m + 1):
    f[1][i] = 1
    pre[1][i] = m - i + 1 # Base case for f and pre

# Fill the f and pre arrays for dynamic programming
for i in range(2, n + 2):
    for j in range(0, m + 1):
        # Calculate f[i][j] based on previous values
        for k in range(1, i):
            (f[i][j] += f[i - k][j] * pre[k][j + 1] % mod * C[i - 2][k - 1]) %= mod
    # Update the pre array for the current row
    for j in range(m, -1, -1):
        pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod

# Output the result which is f[n + 1][0]
print(f[n + 1][0])

