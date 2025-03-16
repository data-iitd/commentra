import sys

# get_scanner initializes a new scanner to read input from a file.
# It sets the split function to scan words and buffers the input to a specified size.
def get_scanner(fp):
	scanner = fp.split()
	scanner = iter(scanner)
	return scanner

# get_next_string reads the next token from the scanner and returns it as a string.
def get_next_string(scanner):
	return next(scanner)

# get_next_int reads the next token, converts it to an integer, and returns it.
def get_next_int(scanner):
	return int(get_next_string(scanner))

# get_next_int64 reads the next token, converts it to an int64, and returns it.
def get_next_int64(scanner):
	return int(get_next_string(scanner))

# get_next_uint64 reads the next token, converts it to a uint64, and returns it.
def get_next_uint64(scanner):
	return int(get_next_string(scanner))

# get_next_float64 reads the next token, converts it to a float64, and returns it.
def get_next_float64(scanner):
	return float(get_next_string(scanner))

# main function handles the program's flow.
# It sets up the input and output files based on environment variables,
# calls the solve function, and prints separators if necessary.
def main():
	fp = sys.stdin
	wfp = sys.stdout
	cnt = 0

	if os.getenv("MASPY") == "ますピ":
		fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
		cnt = 2
	if os.getenv("MASPYPY") == "ますピッピ":
		wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

	scanner = get_scanner(fp)
	writer = wfp
	solve(scanner, writer)
	for i in range(cnt):
		print("-----------------------------------", file=writer)
		solve(scanner, writer)

# solve function reads two integers k and x, and determines if k * 500 is greater than or equal to x.
# It writes "Yes" or "No" based on this condition.
def solve(scanner, writer):
	k = get_next_int(scanner)
	x = get_next_int(scanner)

	ans = "No"
	if k*500 >= x:
		ans = "Yes"
	print(ans, file=writer)

# 