import sys
from collections import defaultdict

# Define the type alias
u64 = int

# Constants
B = 13131
N = 500000 + 7

# Initialize variables
n = 0
s = ""
f = [0] * N
g = [0] * N
map = defaultdict(int)
cnt = 0

# Define the pow function
def pow(a, k):
    if k < 0:
        k += (1 << 63) - 1
    t = 1
    while k:
        if k & 1:
            t *= a
        a *= a
        k >>= 1
    return t

# Read input
# n, s = map(int, sys.stdin.readline().split())
n = int(input().strip())
s = input().strip()

# Precompute f and g arrays
for i in range(1, n + 1):
    if s[i - 1] == '+' or s[i - 1] == '-':
        f[i] = f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow(B, g[i - 1])
        g[i] = g[i - 1]
    else:
        f[i] = f[i - 1]
        g[i] = g[i - 1] + (-1 if s[i - 1] == '<' else 1)

# Compute the count
for i in range(n, 0, -1):
    map[f[i]] += 1
    cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]

# Print the result
print(cnt)

# End-of-code comment
print("<END-OF-CODE>")