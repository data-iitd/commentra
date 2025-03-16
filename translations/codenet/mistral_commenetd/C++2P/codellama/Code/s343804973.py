
#include<cstdio>
#define int long long

# Define constants and input variables
n, m, mod = 0, 0, 0

# Define 2D arrays and names
C = [[0 for i in range(310)] for j in range(310)]
pre = [[0 for i in range(310)] for j in range(310)]
f = [[0 for i in range(310)] for j in range(310)]

# Main function
def main():
	# Read input values
	n, m, mod = map(int, input().split())

	# Initialize C array with base cases
	C[0][0] = 1
	for i in range(1, n+1):
		# Initialize i-th row with base cases
		C[i][0] = C[i][i] = 1

		# Calculate C[i][j] using previous rows
		for j in range(1, i):
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod

	# Initialize f and pre arrays for base case
	for i in range(0, m+1):
		f[1][i] = 1
		pre[1][i] = m-i+1

	# Calculate f and pre arrays for all other rows
	for i in range(2, n+2):
		for j in range(0, m+1):
			# Calculate f[i][j] using previous rows and pre arrays
			for k in range(1, i):
				f[i][j] += f[i-k][j] * pre[k][j+1] % mod * C[i-2][k-1]
				f[i][j] %= mod

		# Calculate pre[i][j] using previous rows and f arrays
		for j in range(m, -1, -1):
			pre[i][j] = (pre[i][j+1] + f[i][j]) % mod

	# Print the result
	print(f[n+1][0])

# The code is now commented and easy to understand.

