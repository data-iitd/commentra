
# Initializing scanner for reading input from stdin
sc = bufio.NewScanner(sys.stdin)

# Function to split input into words
def sc.Split(split):
	sc.Scan()
	sc.Text() # Read the whole line
	data = sc.Text().split() # Split the line into words
	split(data)

# Function to read next integer from input
def nextInt():
	# Reading next token as a string
	sc.Scan()
	# Converting the string to integer
	i, _ = int(sc.Text()), 10
	return i

# Main function
def main():
	# Initializing scanner for reading input from stdin
	sc.Split(bufio.ScanWords)

	# Reading the number of elements in the array
	n = nextInt()

	# Allocating memory for the array
	ar = [0] * (3*n)

	# Reading elements of the array
	for i in range(0, 3*n):
		# Reading next integer and storing it in the array
		ar[i] = nextInt()

	# Sorting the array in ascending order
	ar.sort()

	# Calculating the sum of elements at index 3n-2i-1 in the sorted array
	sum = 0
	for i in range(0, n):
		# Adding the element at index 3n-2i-1 to the sum
		sum += ar[3*n-(i+1)*2]

	# Printing the result
	print(sum)

# 