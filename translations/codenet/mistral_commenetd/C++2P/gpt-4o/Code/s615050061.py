from collections import defaultdict

B = 13131  # Base number for exponentiation
N = 500000 + 7  # Maximum size of input string

n = 0  # Number of symbols in input string
s = [''] * N  # Input string
f = [0] * N  # Intermediate result array
g = [0] * N  # Exponent array
map_count = defaultdict(int)  # Map to store intermediate results for faster calculation
cnt = 0  # Final result

# Function to calculate B raised to the power of k
def pow(a, k):
    if k < 0:
        k += (1 << 63) - 1  # Handle negative exponents by converting them to positive
    t = 1  # Initialize result to 1
    while k:  # Calculate exponentiation using bitwise right shift and multiplication
        if k & 1:
            t *= a  # If the current bit is 1, multiply the current base to the result
        a *= a
        k >>= 1
    return t  # Return the result

# Read the number of symbols and the input string from standard input
n, s[1:] = int(input()), input().strip()

# Initialize the first element of f and g arrays
f[0] = 0
g[0] = 0

# Process each symbol in the input string
for i in range(1, n + 1):
    # Update the current element of f array based on the current symbol
    if s[i - 1] == '+' or s[i - 1] == '-':
        f[i] = f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow(B, g[i])
        g[i] = g[i - 1]
    else:
        f[i] = f[i - 1]
        g[i] = g[i - 1] + (-1 if s[i - 1] == '<' else 1)

# Calculate the final result
for i in range(n, 0, -1):
    map_count[f[i]] += 1  # Increment the count of the intermediate result in the map
    cnt += map_count[f[n] * pow(B, g[i - 1]) + f[i - 1]]  # Add the contribution of the current symbol to the final result

print(cnt)  # Print the final result to standard output

# <END-OF-CODE>
