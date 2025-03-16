import sys

# get_scanner initializes a new scanner for reading from the provided file pointer.
# It sets the scanner to split input by words and allocates a buffer for large inputs.
def get_scanner(fp):
	scanner = fp.readline
	scanner = map(str.strip, scanner)
	scanner = iter(scanner)
	return scanner

# get_next_string retrieves the next string from the scanner.
def get_next_string(scanner):
	return next(scanner)

# get_next_int converts the next string from the scanner to an integer.
def get_next_int(scanner):
	return int(get_next_string(scanner))

# get_next_int64 converts the next string from the scanner to a 64-bit integer.
def get_next_int64(scanner):
	return int(get_next_string(scanner))

def main():
	# Determine the input source: standard input or a file specified as a command-line argument.
	fp = sys.stdin
	if len(sys.argv) > 1:
		fp = open(sys.argv[1])

	# Initialize the scanner for reading input.
	scanner = get_scanner(fp)

	# Read the number of elements from the input.
	n = get_next_int(scanner)

	# Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
	aa = [0] * (n+2)
	sum = 0

	# Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
	for i in range(n):
		aa[i+1] = get_next_int(scanner)
		sum += abs(aa[i+1] - aa[i])
	# Include the difference between the last element and the element before it.
	sum += abs(aa[n+1] - aa[n])

	# Calculate and print the result for each element.
	for i in range(1, n+1):
		# Calculate the new sum of absolute differences if the i-th element is removed.
		ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1])
		print(ans) # Output the result for the current element.

# abs returns the absolute value of an integer.
def abs(a):
	if a < 0:
		return -a
	return a

