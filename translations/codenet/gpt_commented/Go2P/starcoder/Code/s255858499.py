# Initialize a new scanner to read input from standard input
sc = bufio.NewScanner(sys.stdin)

# Function to read the next line of input and return it as a string
def nextLine():
	sc.Scan() # Read the next line
	return sc.Text() # Return the text of the line

# Read the first integer from input and convert it to an integer
a = int(nextLine())
# Read the second integer from input and convert it to an integer
b = int(nextLine())

# Check if the product of a and b is odd
if a*b % 2!= 0:
	# If the product is odd, print "Odd"
	print("Odd")
else:
	# If the product is even, print "Even"
	print("Even")

# 