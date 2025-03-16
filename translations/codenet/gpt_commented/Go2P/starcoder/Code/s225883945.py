# Initialize a new scanner to read input from standard input
sc = bufio.NewScanner(sys.stdin)

# Function to read the next line of input as a string
def next():
	sc.Scan() # Scan the next token
	return sc.Text() # Return the scanned text

# Function to read the next line of input as an integer
def nextInt():
	sc.Scan() # Scan the next token
	i, _ = int(sc.Text()), _ # Convert the scanned text to an integer
	return i # Return the integer value

# Function to read the next line of input as a float64
def nextFloat64():
	sc.Scan() # Scan the next token
	f, _ = float(sc.Text()), _ # Convert the scanned text to a float64
	return f # Return the float64 value

# Function to read 'n' integers from input and return them as a slice
def nextInts(n):
	slice = [0] * n # Create a slice to hold 'n' integers
	for i in range(n):
		slice[i], _ = int(next()), _ # Fill the slice with integers from input
	return slice # Return the slice of integers

# Set the scanner to split input by whitespace
sc.Split(bufio.ScanWords)

# Read two integers from input: n (number of elements) and k (some parameter)
n, k = nextInt(), nextInt()

# Read 'n' integers into slice 'a'
a = nextInts(n)

# Avoid unused variable error by assigning a value to the first element of 'a'
a[0] = 0

# Initialize sum with the value of k and set ans to 1
sum = k
ans = 1

# Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
while sum < n:
	sum = sum - 1 + k # Update sum by subtracting 1 and adding k
	ans += 1 # Increment the answer counter

# Print the final answer
print(ans)

