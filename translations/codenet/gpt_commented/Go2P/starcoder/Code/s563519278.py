# Declare a variable N to hold the number of elements
N = int(input())

# Create a new scanner to read input from standard input
scanner = bufio.NewScanner(sys.stdin)
# Set the scanner to split input by whitespace
scanner.Split(bufio.ScanWords)

# Initialize a slice v of size N to hold counts of occurrences
v = [0] * N

# Loop through the range from 1 to N-1 to read N-1 integers
for i in range(1, N):
	# Scan the next word from input
	scanner.Scan()
	# Convert the scanned text to an integer
	a = int(scanner.Text())
	# Increment the count at the index corresponding to the value read (adjusted for 0-based index)
	v[a-1] += 1

# Create a buffered writer to output results to standard output
w = bufio.NewWriter(sys.stdout)
# Loop through the slice v to print the counts of occurrences
for e in v:
	# Write each count to the output
	print(e, file=w)
# Flush the buffered writer to ensure all output is written
w.Flush()

