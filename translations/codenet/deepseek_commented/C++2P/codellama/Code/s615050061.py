#include <iostream>
#include <map>

using u64 = unsigned long long;

const u64 B = 13131; # Define a constant base for hashing
const int N = 500000 + 7; # Define the maximum length of the string + 7 for safety

n = 0; # Declare an integer to store the length of the string
s = []; # Declare a list to store the input string
f = []; # Declare a list of u64 to store the hash values
g = []; # Declare a list of integers to store position-dependent values
map = {}; # Declare a map to store the frequency of hash values
cnt = 0; # Declare a u64 to count the number of valid substrings

# Define the pow function to calculate a^k using binary exponentiation
def pow(a, k):
	if k < 0: k += (1 << 63) - 1 # Handle negative exponents
	t = 1 # Initialize the result to 1
	for _ in range(k): # Square and halve the exponent
		if k & 1: t = t * a # If the exponent is odd, multiply the result
		a = a * a; k >>= 1
	return t # Return the result

# Main function to execute the program
def main():
	# Uncomment the following lines if you want to read from a file and write to a file
	# freopen("code.in", "r", stdin);
	# freopen("code.out", "w", stdout);

	n, s = input().split(); # Read the input values for n and the string s
	s = list(s); # Convert the string to a list
	for i in range(1, len(s) + 1): # Iterate through the string
		if s[i - 1] == '+' or s[i - 1] == '-': # Check if the character is '+' or '-'
			f.append(f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow(B, g[i] = g[i - 1])); # Compute the hash value
		else:
			f.append(f[i - 1]); g[i] = g[i - 1] + (1 if s[i - 1] == '<' else -1); # Update the position-dependent values
	for i in range(len(s), 0, -1): # Iterate through the string in reverse
		map[f[i]] = map.get(f[i], 0) + 1; cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]; # Count the valid substrings
	print(cnt); # Print the count of valid substrings

	return 0; # Return 0 to indicate successful execution


# 