

# Initialize a new scanner for reading input from stdin
sc = bufio.Scanner(sys.stdin)

# Function to read a single word as a string from the input
def next():
    sc.scan()
    # Comment: Scans the next token, storing it as a single word
    return sc.text()

# Function to read an integer from the input
def nextInt():
    sc.scan()
    # Comment: Scans the next token as a single word and converts it to an integer
    return int(sc.text())

# Function to read a float64 from the input
def nextFloat64():
    return float(next())

# Function to read n integers from the input and return as a slice
def nextInts(n):
    slice = [0] * n
    # Comment: Creates a slice of size n and initializes it with zero values
    for i in range(n):
        slice[i] = nextInt()
        # Comment: Reads the next integer from the input and assigns it to the current index of the slice
    return slice

# Main function
def main():
    # Comment: Sets the scanner to scan words instead of lines
    sc.word_chars = '.1234567890'
    sc.whitespace_chars = ''

    # Read the first three integers from the input
    a = nextInt()
    b = nextInt()
    c = nextInt()

    # Check if the condition is true
    if a + b >= c:
        # If true, print "Yes" to the output
        print("Yes")
    else:
        # If false, print "No" to the output
        print("No")

    # End of code