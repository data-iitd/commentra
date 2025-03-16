import sys

# get_scanner initializes a new scanner for reading input from the provided file pointer.
def get_scanner(fp):
	scanner = fp.readline
	return scanner

# get_next_string retrieves the next string from the scanner.
def get_next_string(scanner):
	return scanner()

# get_next_int retrieves the next integer from the scanner.
def get_next_int(scanner):
	return int(scanner())

def main():
	# Determine the input source: standard input or a file specified as a command-line argument.
	fp = sys.stdin
	if len(sys.argv) > 1:
		fp = open(sys.argv[1], "r") # Open the file if a filename is provided.

	# Initialize the scanner for reading input and a writer for output.
	scanner = get_scanner(fp)
	writer = sys.stdout

	# Read the number of elements.
	n = get_next_int(scanner)
	mm = [0] * (n+1) # Create a slice to hold the input values.
	dp = [[0] * (n+1) for i in range(n+1)] # Create a 2D slice for dynamic programming.

	# Initialize the 2D slice for dynamic programming.
	for i in range(n+1):
		for j in range(n+1):
			dp[i][j] = 0 # Each entry is initialized to zero by default.

	# Read the input values into the mm slice.
	for i in range(n):
		mm[i] = get_next_int(scanner) # Read the first value.
		mm[i+1] = get_next_int(scanner) # Read the second value.

	# Perform dynamic programming to calculate the minimum cost.
	for l in range(2, n+1): # l is the length of the subproblem.
		for i in range(1, n-l+2): # i is the starting index of the subproblem.
			j = i + l - 1 # j is the ending index of the subproblem.
			for k in range(i, j): # k is the partition point.
				# Calculate the cost of multiplying the matrices.
				d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j]
				# Update the dp table with the minimum cost found.
				if dp[i][j] == 0 or dp[i][j] > d:
					dp[i][j] = d
	# Output the minimum cost of multiplying the entire sequence of matrices.
	print(dp[1][n])

# 