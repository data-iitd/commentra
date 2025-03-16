
#include <iostream>
#include <map>

B = 13131 # Base number for exponentiation
N = 500000 + 7 # Maximum size of input string

n = 0 # Number of symbols in input string
s = [0] * N # Input string
f = [0] * N # Intermediate result array
g = [0] * N # Exponent array
map = {} # Map to store intermediate results for faster calculation
cnt = 0 # Final result

# Function to calculate B raised to the power of k
def pow(a, k):
	if k < 0: k += (1 << 63) - 1 # Handle negative exponents by converting them to positive
	t = 1 # Initialize result to 1
	for (; k; a = a * a, k >>= 1): # Calculate exponentiation using bitwise right shift and multiplication
		if k & 1: t = t * a # If the current bit is 1, add the current base to the result
	return t # Return the result

def main():
#	freopen("code.in", "r", stdin); # Uncomment to read input from a file
#	freopen("code.out", "w", stdout); # Uncomment to write output to a file

	n = int(input()) # Read the number of symbols and the input string from standard input
	s[0] = 0 # Initialize the first element of f and g arrays
	f[0] = 0
	g[0] = 0

	# Process each symbol in the input string
	for i in range(1, n + 1):
		# Update the current element of f array based on the current symbol
		if s[i - 1] == '+' or s[i - 1] == '-':
			f[i] = f[i - 1] + (s[i - 1] == '+' and 1 or -1) * pow(B, g[i - 1])
		# If the current symbol is not an operator, just copy the previous value of f to the current position
		else:
			f[i] = f[i - 1]
			g[i] = g[i - 1] + (s[i - 1] == '<' and -1 or 1)

	# Calculate the final result
	for i in range(n, 0, -1):
		map[f[i]] = map.get(f[i], 0) + 1 # Increment the count of the intermediate result in the map
		cnt += map.get(f[n] * pow(B, g[i - 1]) + f[i - 1], 0) # Add the contribution of the current symbol to the final result

	print(cnt) # Print the final result to standard output

	return 0

