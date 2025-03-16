
# Create a new scanner to read input from standard input (stdin)
scanner = bufio.Scanner(sys.stdin)

# Initialize a list to hold four integers
ns = []

# Read a line of input and parse it into the list
scanner.scan()
ns = list(map(int, scanner.text().split()))

# Sort the list of integers in ascending order
ns.sort()

# Check if the sorted integers match the specific sequence [1, 4, 7, 9]
if ns[0] == 1 and ns[1] == 4 and ns[2] == 7 and ns[3] == 9:
    # If they match, print "YES"
    print("YES")
else:
    # If they do not match, print "NO"
    print("NO")

