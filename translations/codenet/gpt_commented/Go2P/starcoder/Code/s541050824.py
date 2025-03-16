import sys

# bufReader class to handle buffered reading from standard input
class bufReader:
	def __init__(self):
		self.buf = []
		self.i = 0
		self.r = sys.stdin

	def readLine(self):
		# If the current index is less than the buffer length, return (buffer already filled)
		if self.i < len(self.buf):
			return
		self.buf = []
		self.i = 0
		for line in self.r:
			self.buf.append(line.rstrip('\n'))
			if not line.endswith('\n'):
				break

	def next(self):
		self.readLine()
		from_ = self.i
		# Iterate through the buffer until a space is found
		for ; self.i < len(self.buf); self.i++:
			if self.buf[self.i] =='':
				break
		s = self.buf[from_:self.i]
		self.i += 1
		return s

	def nextLine(self):
		self.readLine()
		s = self.buf[self.i:]
		self.i = len(self.buf)
		return s

# Initialize a global bufReader instance for reading input
reader = bufReader()

# Initialize a global buffered writer for output
writer = sys.stdout

# next is a wrapper to get the next token as a string
def next():
	return reader.next()

# nextInt retrieves the next token and converts it to an int64
def nextInt():
	return int(next())

# nextLine is a wrapper to get the next line as a string
def nextLine():
	return reader.nextLine()

# out prints the output to the buffered writer
def out(a):
	print(a, file=writer)

# max returns the maximum of two int64 values
def max(x, y):
	if x > y:
		return x
	return y

# min returns the minimum of two int64 values
def min(x, y):
	if x < y:
		return x
	return y

# joinInts converts a slice of int64 to a string with a separator
def joinInts(a, sep):
	b = []
	for v in a:
		b.append(str(v))
	return sep.join(b)

# divUp performs ceiling division of x by y
def divUp(x, y):
	return (x + y - 1) // y

# main function where the program execution starts
def main():
	solve() # Call the solve function to execute the main logic

# solve contains the main logic for processing input and producing output
def solve():
	N = nextInt() # Read the number of pairs
	T, A = [], [] # Initialize slices for T and A
	# Read pairs of integers into T and A
	for i in range(int(N)):
		T.append(nextInt())
		A.append(nextInt())
	t, a = T[0], A[0] # Initialize t and a with the first pair
	# Iterate through the remaining pairs to compute the required values
	for i in range(1, int(N)):
		r = max(divUp(t, T[i]), divUp(a, A[i])) # Calculate the required multiplier
		t, a = T[i]*r, A[i]*r # Update t and a based on the multiplier
	out(t + a) # Output the final result

if __name__ == '__main__':
	main()

