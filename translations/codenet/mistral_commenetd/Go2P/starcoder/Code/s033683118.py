import sys

# Function to create a new scanner from a file pointer
def getScanner(fp):
	return bufio.Scanner(fp)

# Function to read the next string from the scanner
def getNextString(scanner):
	scanner.scan()
	return scanner.text()

# Function to read the next integer from the scanner
def getNextInt(scanner):
	return int(getNextString(scanner))

# Function to read the next integer64 from the scanner
def getNextInt64(scanner):
	return int(getNextString(scanner))

# Function to read the next uint64 from the scanner
def getNextUint64(scanner):
	return int(getNextString(scanner))

# Function to read the next float64 from the scanner
def getNextFloat64(scanner):
	return float(getNextString(scanner))

# Main function
def main():
	# Open the standard input and output files
	fp = sys.stdin
	wfp = sys.stdout

	# Set the file pointers for reading and writing
	if os.getenv("MASPY") == "ますピ":
		fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"), "r")
		cnt = 2 # Number of test cases to be read
	if os.getenv("MASPYPY") == "ますピッピ":
		wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")
		cnt = 1 # Number of test cases to be written

	# Initialize the scanner and writer
	scanner = getScanner(fp)
	writer = bufio.Writer(wfp)

	# Solve the problem for the given test cases
	solve(scanner, writer)
	for i in range(cnt):
		print("-----------------------------------", file=writer) # Print a separator for each test case
		solve(scanner, writer)

	# Flush the writer to write the output to the file
	writer.flush()

# Function to solve the problem for a single test case
def solve(scanner, writer):
	# Read the input values
	k = getNextInt(scanner)
	x = getNextInt(scanner)

	# Initialize the answer
	ans = "No"

	# Check if the condition is satisfied
	if k*500 >= x:
		ans = "Yes"

	# Print the answer
	print(ans, file=writer)

# 