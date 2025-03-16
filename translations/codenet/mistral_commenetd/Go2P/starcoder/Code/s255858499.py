
# Initialize a new scanner to read input from stdin
sc = bufio.NewScanner(sys.stdin)

# Function to read a single line from stdin and return it as a string
def nextLine():
	# Scan the next token as a word
	sc.Scan()
	# Return the text of the scanned token as a string
	return sc.Text()

# Main function
def main():
	# Set the scanner to split input on words
	sc.Split(bufio.ScanWords)
	
	# Read the first two integers from stdin and store them in variables a and b
	a = int(nextLine())
	b = int(nextLine())

	# Check if the product of a and b is odd or even
	if a*b%2!= 0:
		# If the product is odd, print "Odd" to stdout
		print("Odd")
	else:
		# If the product is even, print "Even" to stdout
		print("Even")

# 