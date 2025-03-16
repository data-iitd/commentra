import sys

# Function to get a new scanner from a file pointer
def getScanner(fp):
	return bufio.Scanner(fp)

# Function to read the next string from the scanner
def getNextString(scanner):
	scanner.scan()
	return scanner.text()

# Function to read the next integer from the scanner
def getNextInt(scanner):
	return int(getNextString(scanner))

# Main function to read input and process it
def main():
	# Open the standard input stream if no file is provided as an argument
	fp = sys.stdin
	if len(sys.argv) > 1:
		# Open the file provided as an argument and use it as the input stream
		fp = open(sys.argv[1], "r")

	# Initialize a new scanner from the input stream
	scanner = getScanner(fp)
	writer = sys.stdout

	# Read the number of test cases from the input
	n = getNextInt(scanner)

	# Initialize a slice to store the prefix sum of squares of elements
	mm = [0] * (n+1)

	# Initialize a 2D slice to store the dynamic programming table
	dp = [[0] * (n+1) for i in range(n+1)]

	# Read the elements and their prefix sum of squares from the input
	for i in range(n):
		# Read the next integer as the current element
		mm[i+1] = getNextInt(scanner)
		# Read the next integer as the next element's prefix sum of square
		mm[i+1] += mm[i] * mm[i]

	# Process the dynamic programming table for all subarrays of given size
	for l in range(2, n+1):
		for i in range(1, n-l+2):
			j = i + l - 1
			# Iterate through all subarrays of the current subarray
			for k in range(i, j):
				# Calculate the sum of squares of elements in the current subarray
				d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j]
				# Update the dynamic programming table if a larger sum is found
				if dp[i][j] == 0 or dp[i][j] > d:
					dp[i][j] = d

	# Print the result for the given input
	print(dp[1][n])

	# End of the code

