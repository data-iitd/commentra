
import sys

# get_next_string reads and returns the next word as a string from the scanner
def get_next_string(scanner):
	scanner.readline()
	return scanner.readline().strip()

# get_next_int reads and converts the next integer from the scanner to an int
def get_next_int(scanner):
	return int(get_next_string(scanner))

# get_next_int64 reads and converts the next integer from the scanner to an int64
def get_next_int64(scanner):
	return int(get_next_string(scanner))

# get_next_uint64 reads and converts the next unsigned integer from the scanner to a uint64
def get_next_uint64(scanner):
	return int(get_next_string(scanner))

# get_next_float64 reads and converts the next floating-point number from the scanner to a float64
def get_next_float64(scanner):
	return float(get_next_string(scanner))

# main function is the entry point of the program
def main():
	# open standard input as default file if no arguments are provided
	fp = sys.stdin
	# open output file if provided as an argument
	wfp = sys.stdout
	if len(sys.argv) > 1:
		fp = open(sys.argv[1], "r")
		# create output file if provided as an argument
		if len(sys.argv) > 2:
			wfp = open(sys.argv[2], "w")

	# initialize scanner and writer
	scanner = fp.readline()
	writer = wfp

	# read the first integer from the input
	n = get_next_int(scanner)

	# initialize answer variable
	ans = "second"
	# iterate through the input integers
	for i in range(n):
		# read the next integer from the input
		a = get_next_int(scanner)
		# check if the current integer is odd
		if a%2 == 1:
			# update the answer if an odd integer is found
			ans = "first"
			# exit the loop if only one odd integer is found
			break
	# write the answer to the output
	print(ans, file=writer)

# entry point of the program
if __name__ == "__main__":
	main()

