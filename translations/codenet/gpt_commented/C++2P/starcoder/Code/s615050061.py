# Define constants for base and maximum size
B = 13131
N = 500000 + 7

# Declare global variables
n = 0 # Length of the input string
s = [0] * N # Input string
f = [0] * N # Array to store computed values based on the input string
g = [0] * N # Array to store the shift values
map = {} # Map to count occurrences of computed values
cnt = 0 # Counter for the final result

# Function to compute power of a number with a given exponent
def pow(a, k):
    # Adjust exponent if negative
    if k < 0: k += (1 << 63) - 1
    t = 1 # Initialize result
    # Exponentiation by squaring
    while k:
        if k & 1: t = t * a
        a = a * a
        k >>= 1
    return t

# Read input values: number of operations and the operations string
n = int(input())
s = list(input())

# Process each character in the input string
for i in range(1, n + 1):
    # If the character is '+' or '-', update f and g arrays
    if s[i - 1] == '+' or s[i - 1] == '-':
        f[i] = f[i - 1] + (s[i - 1] == '+' and 1 or -1) * pow(B, g[i] = g[i - 1])
    else:
        # If the character is '<' or '>', update f and g arrays accordingly
        f[i] = f[i - 1] # No change in f
        g[i] = g[i - 1] + (s[i - 1] == '<' and -1 or 1) # Update g based on direction

# Iterate backwards through the string to count valid combinations
for i in range(n, 0, -1):
    map[f[i]] = map.get(f[i], 0) + 1 # Increment the count of the current f value
    # Update the counter with the number of valid combinations found
    cnt += map.get(f[n] * pow(B, g[i - 1]) + f[i - 1], 0)

# Output the final count of valid combinations
print(cnt)

