
# Initialize a new scanner for reading input from stdin
sc = bufio.NewScanner(sys.stdin)

# Function to read a single word as a string from the input
def next():
	sc.Scan()
	# Comment: Scans the next token, storing it as a single word
	return sc.Text()

# Function to read an integer from the input
def nextInt():
	sc.Scan()
	# Comment: Scans the next token as a single word and converts it to an integer
	i, _ = int(sc.Text())
	return i

# Function to read a float64 from the input
def nextFloat64():
	f, _ = float(next())
	# Comment: Parses the next token as a float64 value
	return f

# Function to read n integers from the input and return as a slice
def nextInts(n):
	slice = []int(n)
	# Comment: Creates a slice of size n and initializes it with zero values
	for i in range(n):
		slice[i] = nextInt()
		# Comment: Reads the next integer from the input and assigns it to the current index of the slice
	return slice

# Main function
def main():
	# Comment: Sets the scanner to scan words instead of lines
	sc.Split(bufio.ScanWords)

	# Read the first three integers from the input
	a = nextInt()
	b = nextInt()
	c = nextInt()

	# Check if the condition is true
	if a+b >= c:
		# If true, print "Yes" to the output
		print("Yes")
	else:
		# If false, print "No" to the output
		print("No")

# End of code

