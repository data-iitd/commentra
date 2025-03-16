# Initialize a new scanner to read input from standard input
sc = bufio.NewScanner(sys.stdin)

# next reads the next line of input and returns it as a string
def next():
	sc.Scan() # Scan the next token
	return sc.Text() # Return the scanned text

# nextInt reads the next line of input, converts it to an integer, and returns it
def nextInt():
	sc.Scan() # Scan the next token
	i, _ = int(sc.Text()), _ # Convert the scanned text to an integer
	return i # Return the integer value

# nextFloat64 reads the next line of input, converts it to a float64, and returns it
def nextFloat64():
	sc.Scan() # Scan the next token
	f, _ = float(sc.Text()), _ # Convert the scanned text to a float64
	return f # Return the float64 value

# nextInts reads 'n' integers from input and returns them as a slice
def nextInts(n):
	slice = [0] * n # Create a slice to hold 'n' integers
	for i in range(n): # Loop 'n' times to read integers
		slice[i], _ = int(next()), _ # Read each integer and store it in the slice
	return slice # Return the slice of integers

if __name__ == "__main__":
	sc.Split(bufio.ScanWords) # Set the scanner to split input by words
	# Read two integers, sum them, and compare the result with a third integer
	if nextInt()+nextInt() >= nextInt():
		print("Yes") # Print "Yes" if the sum is greater than or equal to the third integer
	else:
		print("No") # Print "No" otherwise

