from collections import defaultdict
import sys

# Define constants for base and maximum size
B = 13131
N = 500000 + 7

# Declare global variables
n = 0
s = [""] * N
f = [0] * N
g = [0] * N
map = defaultdict(int)
cnt = 0

# Function to compute power of a number with a given exponent
def pow(a, k):
    # Adjust exponent if negative
    if k < 0:
        k += (1 << 63) - 1
    t = 1
    # Exponentiation by squaring
    while k:
        if k & 1:
            t *= a
        a *= a
        k >>= 1
    return t

# Read input values: number of operations and the operations string
n = int(input().strip())
s = input().strip()

# Process each character in the input string
for i in range(1, n + 1):
    # If the character is '+' or '-', update f and g arrays
    if s[i - 1] == '+' or s[i - 1] == '-':
        f[i] = f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow(B, g[i - 1])
    else:
        # If the character is '<' or '>', update f and g arrays accordingly
        f[i] = f[i - 1]
        g[i] = g[i - 1] + (-1 if s[i - 1] == '<' else 1)

# Iterate backwards through the string to count valid combinations
for i in range(n, 0, -1):
    map[f[i]] += 1
    cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]

# Output the final count of valid combinations
print(cnt)

