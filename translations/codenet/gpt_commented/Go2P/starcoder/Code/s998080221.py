import sys

# bufReader class to handle buffered reading from standard input
class bufReader:
	def __init__(self):
		self.buf = ""
		self.i = 0

	def readLine(self):
		if self.i < len(self.buf):
			return # Return if there are still bytes to read
		self.buf = sys.stdin.readline() # Read a line
		self.i = 0 # Reset index

	def next(self):
		self.readLine() # Ensure the buffer is filled
		from_ = self.i # Store the starting index
		while self.i < len(self.buf) and self.buf[self.i]!='':
			self.i += 1 # Move index forward
		to = self.i # Store the ending index
		self.i += 1 # Move index forward
		return self.buf[from_:to] # Return the token

	def nextInt(self):
		return int(self.next()) # Convert the token to an integer

# Initialize a global bufReader instance for reading input
reader = bufReader()

# writer class to handle buffered writing to standard output
class writer:
	def __init__(self):
		self.buf = ""

	def write(self, s):
		self.buf += s

	def flush(self):
		sys.stdout.write(self.buf)
		self.buf = ""

# Initialize a global writer instance for writing output
writer = writer()

# next is a helper function to read the next token
def next():
	return reader.next()

# nextInt is a helper function to read the next token as an integer
def nextInt():
	return reader.nextInt()

# nextLine is a helper function to read the next line
def nextLine():
	reader.readLine()
	return reader.buf

# out is a helper function to write to the output
def out(a):
	writer.write(str(a) + "\n")

# max returns the maximum of two integers
def max(x, y):
	if x > y:
		return x
	return y

# min returns the minimum of two integers
def min(x, y):
	if x < y:
		return x
	return y

# abs returns the absolute value of an integer
def abs(x):
	if x < 0:
		return -x
	return x

# divUp returns the ceiling of the division of two integers
def divUp(x, y):
	return (x + y - 1) / y

# gcd computes the greatest common divisor of two integers
def gcd(x, y):
	if x < y:
		x, y = y, x # Ensure x is the larger value
	while y!= 0:
		x, y = y, x % y # Euclidean algorithm
	return x

# lcm computes the least common multiple of two integers
def lcm(x, y):
	return x * y / gcd(x, y)

# pow computes x raised to the power of y
def pow(x, y):
	return int(pow(float(x), float(y)))

# solve function to compute the maximum profit and count
def solve():
	N, _ = nextInt(), nextInt() # Read number of elements and ignore the second value
	A = [0] * N # Create a slice to hold the elements
	for i in range(N):
		A[i] = nextInt() # Read each element into the slice
	maxProfit = 0 # Initialize maximum profit
	maxCnt = 0    # Initialize count of maximum profit occurrences
	maxA = A[N-1] # Start with the last element as the maximum
	for i in range(N-2, -1, -1): # Iterate backwards through the slice
		profit = max(0, maxA-A[i]) # Calculate profit based on the current element
		if maxProfit < profit: # If we found a new maximum profit
			maxProfit = profit # Update maximum profit
			maxCnt = 1         # Reset count to 1
		elif maxProfit == profit: # If we found another occurrence of the maximum profit
			maxCnt += 1 # Increment the count
		maxA = max(maxA, A[i]) # Update the maximum element seen so far
	out(maxCnt) # Output the count of maximum profit occurrences

# main function to execute the program
if __name__ == "__main__":
	solve() # Call the solve function
	writer.flush() # Flush the writer to output results

