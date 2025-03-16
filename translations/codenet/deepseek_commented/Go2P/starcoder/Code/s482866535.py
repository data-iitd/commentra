import sys

# get_scanner initializes a new scanner for reading from a file.
def get_scanner(fp):
	scanner = fp.readline
	return scanner

# get_next_string reads the next word from the scanner.
def get_next_string(scanner):
	return scanner()

# get_next_int converts the next word from the scanner to an integer.
def get_next_int(scanner):
	return int(get_next_string(scanner))

# Main function to compute the minimum number of matrix multiplications.
def main():
	fp = sys.stdin
	if len(sys.argv) > 1:
		fp = open(sys.argv[1], "r")

	# Initialize scanner and writer for standard input and output.
	scanner = get_scanner(fp)
	writer = sys.stdout

	# Read the number of matrices.
	n = get_next_int(scanner)

	# Initialize arrays for matrix dimensions and dynamic programming.
	mm = [0] * (n+1)
	dp = [[0] * (n+1) for i in range(n+1)]

	# Read matrix dimensions into the mm array.
	for i in range(n):
		mm[i] = get_next_int(scanner)
		mm[i+1] = get_next_int(scanner)

	# Use dynamic programming to compute the minimum number of multiplications.
	for l in range(2, n+1):
		for i in range(1, n-l+2):
			j = i + l - 1
			for k in range(i, j):
				d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j]
				if dp[i][j] == 0 or dp[i][j] > d:
					dp[i][j] = d

	# Print the result to the standard output.
	print(dp[1][n])

	# Flush the writer to ensure all data is written to the output.
	writer.flush()

# 