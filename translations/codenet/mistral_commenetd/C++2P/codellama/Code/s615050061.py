
#include <iostream>
#include <map>

using u64 = unsigned long long;

const u64 B = 13131; # Base number for exponentiation
const int N = 500000 + 7; # Maximum size of input string

n = 0; # Number of symbols in input string
s = []; # Input string
f = []; # Intermediate result array
g = []; # Exponent array
map = {}; # Map to store intermediate results for faster calculation
cnt = 0; # Final result

# Function to calculate B raised to the power of k
def pow(a, k):
	if k < 0: k += (1 << 63) - 1 # Handle negative exponents by converting them to positive
	t = 1 # Initialize result to 1
	for _ in range(k): # Calculate exponentiation using bitwise right shift and multiplication
		if k & 1: t *= a # If the current bit is 1, add the current base to the result
		a *= a; k >>= 1 # Update the current base and exponent
	return t # Return the result

# Read the number of symbols and the input string from standard input
n, s = input(), list(input())

# Initialize the first element of f and g arrays
f.append(0); g.append(0)

# Process each symbol in the input string
for i in range(1, n + 1):
	# Update the current element of f array based on the current symbol
	if s[i] in ['+', '-']:
		f.append(f[i - 1] + (1 if s[i] == '+' else -1) * pow(B, g[i] = g[i - 1]))
	# If the current symbol is not an operator, just copy the previous value of f to the current position
	else:
		f.append(f[i - 1]); g.append(g[i - 1] + (1 if s[i] == '<' else -1))

# Calculate the final result
for i in range(n, 0, -1):
	map[f[i]] = map.get(f[i], 0) + 1 # Increment the count of the intermediate result in the map
	cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]] # Add the contribution of the current symbol to the final result

print(cnt) # Print the final result to standard output

# 