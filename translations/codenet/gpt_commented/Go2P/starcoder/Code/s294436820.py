# IO helper functions

# nextToken and nextLine are function variables that will be initialized 
# by SetInput() and SetUnbufferedInput() for reading input tokens and lines.
nextToken = None
nextLine = None

# OutputBuffer holds a buffered writer for output. It must be initialized by SetOutput().
OutputBuffer = None

# OutputWriter holds an io.Writer for output. It must be initialized by SetOutput().
OutputWriter = None

# SetInteractive configures the IO functions for interactive input/output.
def SetInteractive(w, r):
	SetUnbufferedInput(r) # Set unbuffered input for reading
	OutputBuffer = None     # No output buffer for interactive mode
	OutputWriter = w       # Set the output writer

# Setup OutputBuffer and OutputWriter for buffered output.
def SetOutput(w):
	OutputBuffer = bufio.NewWriter(w) # Initialize the output buffer
	OutputWriter = OutputBuffer         # Set the output writer to the buffer

# Flushes OutputBuffer to ensure all buffered data is written out.
def Flush():
	if OutputBuffer!= None:
		OutputBuffer.Flush() # Flush the buffer if it is initialized

# IsSpace checks if a byte is a whitespace character.
def IsSpace(c):
	return c =='' or c == '\t' or c == '\r' or c == '\n' or ord(c) == 0x0B or ord(c) == 0x0C

# IsNewLine checks if a byte is a newline character.
def IsNewLine(c):
	return c == '\r' or c == '\n'

# SetInput initializes the nextToken function with an input buffer.
def SetInput(r):
	buf = new(bytes.Buffer) # Create a new bytes buffer
	var b []byte             # Buffer to hold input bytes

	var i int                # Index for reading from buffer
	# Function to read the next token from the input
	rest = lambda: (b[j:i], None) if i < len(b) else (None, io.EOF)
	# Function to initialize reading from the input
	initial = lambda: (b[j:i], None) if i < len(b) else (None, io.EOF)
	nextToken = initial # Initialize nextToken

	# Function to read the next line from the input
	restLn = lambda: (b[j:i], None) if i < len(b) else (None, io.EOF)

	# Function to initialize reading lines from the input
	initialLn = lambda: (b[j:i], None) if i < len(b) else (None, io.EOF)
	nextLine = initialLn # Initialize nextLine

# SetUnbufferedInput configures the nextToken function for unbuffered input.
def SetUnbufferedInput(r):
	buf = bufio.NewReader(r) # Create a new buffered reader
	var b []byte               # Buffer to hold input bytes

	var i int                  # Index for reading from buffer
	# Function to read the next token from the input
	nextToken = lambda: (b[j:i], None) if i < len(b) else (None, io.EOF)

# -----------------------------------------------------------------------------

# IO functions

# readb reads the next token and returns it as a byte slice.
def readb():
	b, err = nextToken() # Read the next token
	if err!= None:
		panic(err) # Panic if an error occurs
	return b[:len(b):len(b)] # Return the token

# reads reads the next token and returns it as a string.
def reads():
	return string(readb()) # Convert byte slice to string

# readbln reads the next line as a byte slice, excluding the trailing newline.
def readbln():
	b, err = nextLine() # Read the next line
	if err!= None:
		panic(err) # Panic if an error occurs
	return b[:len(b):len(b)] # Return the line

# readsln reads the next line and returns it as a string.
def readsln():
	return string(readbln()) # Convert byte slice to string

# readll reads the next token and returns it as an int64.
def readll():
	i, err = int(reads()), None # Parse the next token as int64
	if err!= None:
		panic(err.Error()) # Panic if parsing fails
	return i # Return the parsed int64

# readi reads the next token and returns it as an int.
def readi():
	return int(readll()) # Convert int64 to int

# readf reads the next token and returns it as a float64.
def readf():
	f, err = float(reads()), None # Parse the next token as float64
	if err!= None:
		panic(err.Error()) # Panic if parsing fails
	return f # Return the parsed float64

# printf writes formatted output to OutputWriter.
def printf(f, *args):
	return OutputWriter.write(f % args)

# println writes output to OutputWriter without formatting.
def println(*args):
	return OutputWriter.write(" ".join(map(str, args)) + "\n")

# eprintf writes formatted output to stderr.
def eprintf(f, *args):
	return sys.stderr.write(f % args)

# eprintln writes output to stderr without formatting.
def eprintln(*args):
	return sys.stderr.write(" ".join(map(str, args)) + "\n")

# debugf writes formatted debug output to stderr if DEBUG is enabled.
def debugf(f, *args):
	if DEBUG:
		return eprintf(f, *args)

# debug writes debug output to stderr if DEBUG is enabled.
def debug(*args):
	if DEBUG:
		return eprintln(*args)

# -----------------------------------------------------------------------------

# Utilities

# sumSlice calculates the sum of a slice of integers.
def sumSlice(a):
	res = 0
	for _, v in enumerate(a):
		res += v # Accumulate the sum
	return res # Return the total sum

# sumSlicell calculates the sum of a slice of int64.
def sumSlicell(a):
	res = 0
	for _, v in enumerate(a):
		res += v # Accumulate the sum
	return res # Return the total sum

# readInts reads N integers from input and returns the count and the slice.
def readInts(N):
	if N == 0:
		N = readi() # Read N if it is zero
	a = make([]int, N) # Create a slice of integers
	for i in range(N):
		a[i] = readi() # Read each integer
	return N, a # Return the count and the slice

# readIntsll reads N int64 values from input and returns the count and the slice.
def readIntsll(N):
	if N == 0:
		N = readi() # Read N if it is zero
	a = make([]int64, N) # Create a slice of int64
	for i in range(N):
		a[i] = readll() # Read each int64 value
	return N, a # Return the count and the slice

# -----------------------------------------------------------------------------

# Simple math functions

INF  = 1000000007
INF2 = 1000000009
INF3 = 998244353

# min returns the smaller of two integers.
def min(a, b):
	if a < b:
		return a # Return a if it is smaller
	return b # Otherwise return b

# minll returns the smaller of two int64 values.
def minll(a, b):
	if a < b:
		return a # Return a if it is smaller
	return b # Otherwise return b

# minf returns the smaller of two float64 values.
def minf(a, b):
	if a < b:
		return a # Return a if it is smaller
	return b # Otherwise return b

# max returns the larger of two integers.
def max(a, b):
	if a < b:
		return b # Return b if it is larger
	return a # Otherwise return a

# maxll returns the larger of two int64 values.
def maxll(a, b):
	if a < b:
		return b # Return b if it is larger
	return a # Otherwise return a

# maxf returns the larger of two float64 values.
def maxf(a, b):
	if a < b:
		return b # Return b if it is larger
	return a # Otherwise return a

# abs returns the absolute value of an integer.
def abs(a):
	if a < 0:
		return -a # Return negative if a is less than zero
	return a # Otherwise return a

# absll returns the absolute value of an int64.
def absll(a):
	if a < 0:
		return -a # Return negative if a is less than zero
	return a # Otherwise return a

# absf returns the absolute value of a float64.
def absf(a):
	if a < 0:
		return -a # Return negative if a is less than zero
	return a # Otherwise return a

# egcd computes the extended GCD of a and b, returning d, x, y.
def egcd(a, b):
	if b == 0:
		return a, 1, 0 # Base case: return a, x=1, y=0
	d, x, y = egcd(b, a%b) # Recursive call
	return d, y, x - a/b*y # Return GCD and coefficients

# egcdll computes the extended GCD of a and b for int64 values.
def egcdll(a, b):
	if b == 0:
		return a, 1, 0 # Base case: return a, x=1, y=0
	d, x, y = egcdll(b, a%b) # Recursive call
	return d, y, x - a/b*y # Return GCD and coefficients

# gcd computes the GCD of a and b.
def gcd(a, b):
	d, _, _ = egcd(a, b) # Get GCD using extended GCD
	return d # Return the GCD

# gcdll computes the GCD of a and b for int64 values.
def gcdll(a, b):
	d, _, _ = egcdll(a, b) # Get GCD using extended GCD
	return d # Return the GCD

# set up IO functions
def init():
	# Initialize input and output for non-interactive mode
	SetInput(sys.stdin)
	SetOutput(sys.stdout)

	# Uncomment below to enable interactive mode
	# SetInteractive(sys.stdout, sys.stdin)

# main function to execute the program logic
def main():
	defer Flush() # Ensure output is flushed at the end
	h, w, k = readi(), readi(), readi() # Read height, width, and target count
	m = make([][], h) # Create a 2D slice for the grid
	for i in range(h):
		m[i] = make([]int, w) # Initialize each row
		s = reads() # Read the row as a string
		for j in range(w):
			m[i][j] = int(s[j]) # Convert each character to int and store
	answer = solve(h, w, k, m) # Solve the problem and get the answer
	println(answer) # Print the answer

# countBlack counts the number of black cells in the grid.
def countBlack(h, w, m):
	count = 0 # Initialize count
	debug("new table") # Debug output for new table
	for i in range(h):
		for j in range(w):
			if m[i][j] == Black:
				count++ # Increment count if the cell is black
		debug(m[i]) # Debug output for the current row
	debug("result : ", count) # Debug output for the result
	return count # Return the count of black cells

# solve calculates the number of ways to paint the grid to achieve the target count of black cells.
def solve(h, w, a, m):
	result = 0 # Initialize result
	for i in range(1<<h): # Iterate over all possible row paint combinations
		for k in range(1<<w): # Iterate over all possible column paint combinations
			tmp = make([][], h) # Create a temporary grid to simulate painting
			for j in range(h):
				tmp[j] = make([]int, w) # Initialize each row of the temporary grid
				copy(tmp[j], m[j]) # Copy original grid to temporary grid
			# Paint rows based on the current combination
			for j in range(h):
				hPainted = (1 << j & i) # Check if the current row is painted
				if hPainted > 0:
					debug("painted ", j, 1<<j, i, hPainted) # Debug output for painted row
					for l in range(w):
						tmp[j][l] = 1