from collections import defaultdict
import sys

# Define the base number for exponentiation
B = 13131

# Define the maximum size of input string
N = 500000 + 7

# Initialize variables
n = 0
s = [""] * N
f = [0] * N
g = [0] * N
map = defaultdict(int)
cnt = 0

# Function to calculate B raised to the power of k
def pow(a, k):
    if k < 0:
        k += (1 << 63) - 1  # Handle negative exponents by converting them to positive
    t = 1  # Initialize result to 1
    while k:
        if k & 1:
            t *= a  # If the current bit is 1, multiply the result by the current base
        a *= a  # Square the base
        k >>= 1  # Right shift the exponent
    return t  # Return the result

# Read the number of symbols and the input string from standard input
n = int(input().strip())
s = input().strip()

# Initialize the first element of f and g arrays
f[0] = 0
g[0] = 0

# Process each symbol in the input string
for i in range(1, n + 1):
    # Update the current element of f array based on the current symbol
    if s[i - 1] == '+' or s[i - 1] == '-':
        f[i] = f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow(B, g[i])
        g[i] = g[i - 1]
    # If the current symbol is not an operator, just copy the previous value of f to the current position
    else:
        f[i] = f[i - 1]
        g[i] = g[i - 1] + (-1 if s[i - 1] == '<' else 1)

# Calculate the final result
for i in range(n, 0, -1):
    map[f[i]] += 1  # Increment the count of the intermediate result in the map
    cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]  # Add the contribution of the current symbol to the final result

# Print the final result to standard output
print(cnt)

# End-of-code
