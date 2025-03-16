
# Create a new scanner to read input from standard input (stdin)
scanner = bufio.NewScanner(sys.stdin)

# Initialize a slice to hold four integers
ns = [0, 0, 0, 0]

# Read a line of input and parse it into the slice
scanner.Scan()
fmt.Sscanf(scanner.Text(), "%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3])

# Sort the slice of integers in ascending order
ns.sort()

# Check if the sorted integers match the specific sequence [1, 4, 7, 9]
if ns[0] == 1 and ns[1] == 4 and ns[2] == 7 and ns[3] == 9:
	# If they match, print "YES"
	print("YES")
else:
	# If they do not match, print "NO"
	print("NO")

# 