import sys

# get_scanner initializes a new Scanner to read from a file pointer.
# It sets the split function to ScanWords and buffers to 500001 bytes.
def get_scanner(fp):
	scanner = bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000)
	return scanner

# get_next_string reads the next token from the Scanner and returns it as a string.
def get_next_string(scanner):
	scanner.Scan()
	return scanner.Text()

# get_next_int reads the next token as a string, converts it to an integer, and returns it.
def get_next_int(scanner):
	i, _ = int(get_next_string(scanner)), 10
	return i

# get_next_int64 reads the next token as a string, converts it to an int64, and returns it.
def get_next_int64(scanner):
	i, _ = int(get_next_string(scanner), 10), 10
	return i

# get_next_uint64 reads the next token as a string, converts it to a uint64, and returns it.
def get_next_uint64(scanner):
	i, _ = int(get_next_string(scanner), 10), 10
	return i

# get_next_float64 reads the next token as a string, converts it to a float64, and returns it.
def get_next_float64(scanner):
	i, _ = float(get_next_string(scanner)), 10
	return i

# main function handles file input/output based on command-line arguments.
# It reads integers from the specified file or standard input, sorts them,
# and calculates the number of valid triplets (i, j, m) where i < j < m and ll[m] < ll[i] + ll[j].
def main():
	fp = sys.stdin
	wfp = sys.stdout

	# Check if file paths are provided as command-line arguments.
	if len(sys.argv) > 1:
		fp = open(sys.argv[1], "r")
		if len(sys.argv) > 2:
			wfp = open(sys.argv[2], "w")

	scanner = get_scanner(fp)
	writer = bufio.NewWriter(wfp)

	# Read the number of elements.
	n = get_next_int(scanner)
	ll = make([]int, n)

	# Read n integers into the slice ll.
	for i in range(n):
		ll[i] = get_next_int(scanner)

	# Sort the slice ll.
	ll.sort()

	# Initialize the answer variable.
	ans = 0

	# Iterate through possible triplets (i, j, m) where i < j < m.
	for i in range(n-2):
		for j in range(i+1, n-1):
			l = j + 1
			r = n
			for l < r:
				m = (l + r) >> 1
				if ll[m] < ll[i]+ll[j]:
					l = m + 1
					continue
				r = m
			# Add the number of valid m's to the answer.
			ans += l - (j + 1)
	# Print the final answer to the standard output.
	print(ans)

	# Flush the writer to ensure all data is written to the file or standard output.
	writer.Flush()

# 