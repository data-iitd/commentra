# <START-OF-CODE>

# Create a new scanner to read input from standard input (stdin)
scanner = bufio.NewScanner(sys.stdin)
# Set the scanner to split input by words
scanner.Split(bufio.ScanWords)

# Initialize a 3x3 integer array to hold the input values
c = [[0 for x in range(3)] for y in range(3)]
# Initialize arrays to hold differences for calculations
a = [0 for x in range(3)]
b = [0 for x in range(3)]

# Read 3x3 integers from input and populate the array 'c'
for i in range(3):
	for j in range(3):
		scanner.Scan() # Read the next word from input
		c[i][j] = int(scanner.Text()) # Convert the word to an integer and store it in 'c'

# Calculate the first differences based on the first row of 'c'
b[0] = c[0][0] - a[0]
b[1] = c[0][1] - a[0]
b[2] = c[0][2] - a[0]

# Calculate the differences for the second and third rows based on the first row
a[1] = c[1][0] - c[0][0]
a[2] = c[2][0] - c[0][0]

# Check if the calculated differences are consistent across the matrix
if a[1] == c[1][1]-c[0][1] and a[1] == c[1][2]-c[0][2] and
	a[2] == c[2][1]-c[0][1] and a[2] == c[2][2]-c[0][2]:
	# If the conditions are met, print "Yes"
	print("Yes")
else:
	# If the conditions are not met, print "No"
	print("No")

# 