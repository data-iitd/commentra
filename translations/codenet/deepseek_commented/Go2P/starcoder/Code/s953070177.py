import sys

# get_scanner initializes a new bufio.Scanner to read from a file.
# It sets the split function to bufio.ScanWords to read words,
# and it also sets a buffer size.
def get_scanner(fp):
	scanner = bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(bytearray(500001), 500000)
	return scanner

# get_next_string reads the next word from the scanner and returns it as a string.
def get_next_string(scanner):
	scanner.Scan()
	return scanner.Text()

# get_next_int reads the next word from the scanner, converts it to an integer,
# and returns it.
def get_next_int(scanner):
	i, _ = int(get_next_string(scanner)), None
	return i

# get_next_int64 reads the next word from the scanner, converts it to an int64,
# and returns it.
def get_next_int64(scanner):
	i, _ = int(get_next_string(scanner)), None
	return i

# main is the entry point of the program.
# It first checks if a file name is provided as an argument,
# and if so, it opens that file for reading.
# It then initializes a scanner and a writer.
def main():
	fp = sys.stdin
	if len(sys.argv) > 1:
		fp = open(sys.argv[1], "r")

	scanner = get_scanner(fp)

	# Read the number of elements.
	n = get_next_int(scanner)

	# Initialize a slice to store the elements and a sum variable.
	aa = [0] * (n+2)
	sum = 0

	# Read the elements into the slice and calculate the sum of absolute differences.
	for i in range(n):
		aa[i+1] = get_next_int(scanner)
		sum += abs(aa[i+1] - aa[i])
	sum += abs(aa[n+1] - aa[n])

	# Calculate and print the differences for each element.
	for i in range(1, n+1):
		ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1])
		print(ans)

# abs returns the absolute value of an integer.
def abs(a):
	if a < 0:
		return -a
	return a

