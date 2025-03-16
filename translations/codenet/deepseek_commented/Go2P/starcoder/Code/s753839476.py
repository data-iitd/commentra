import math

# Main function: Reads input values, calculates the minimum difference, and prints the index.
def main():
	io, flush = newIO() # Initialize IO and defer flushing the writer.
	defer flush()

	n, t, a = io.scanInt(), io.scanFloat(), io.scanFloat() # Read values for n, t, and a.
	heights = io.scanFloats(n) # Read a list of heights.

	minDiff = absDiffFloat(t-heights[0]*0.006, a) # Calculate the initial minimum difference.
	minIdx = 0 # Initialize the index of the minimum difference.
	for i, h in enumerate(heights[1:]): # Iterate through the heights starting from the second element.
		diff = absDiffFloat(t-h*0.006, a) # Calculate the difference for the current height.
		if diff < minDiff: # Update the minimum difference and index if a smaller difference is found.
			minDiff = diff
			minIdx = i + 1
	io.print(minIdx + 1) # Print the index (plus one for 1-based indexing).

# AbsDiffFloat computes the absolute difference between two float numbers.
def absDiffFloat(n1, n2):
	return abs(n1 - n2)

# IO struct for input/output operations.
class IO:
	def __init__(self):
		self.scanner = newScanner()
		self.writer = newWriter()

	# newScanner initializes a new scanner for reading input.
	def newScanner(self):
		s = bufio.NewScanner(sys.stdin)
		s.Buffer(make([]byte, 10000000), 10000000)
		s.Split(bufio.ScanWords)
		return s

	# newWriter initializes a new writer for output.
	def newWriter(self):
		return bufio.NewWriter(sys.stdout)

	# ScanBytes reads and returns the next byte slice from the scanner.
	def scanBytes(self):
		if not self.scanner.Scan():
			raise RuntimeError("ScanBytes failed")
		return self.scanner.Bytes()

	# ScanString reads and returns the next string from the scanner.
	def scanString(self):
		if not self.scanner.Scan():
			raise RuntimeError("ScanString failed")
		return self.scanner.Text()

	# ScanStrings reads and returns n strings from the scanner.
	def scanStrings(self, n):
		strs = [None] * n
		for i in range(n):
			strs[i] = self.scanString()
		return strs

	# Scan2DStrings reads and returns a 2D slice of strings.
	def scan2DStrings(self, y, x):
		strs = [None] * y
		for i in range(y):
			strs[i] = self.scanStrings(x)
		return strs

	# Scan2DGraph reads and returns a 2D slice of strings representing a graph.
	def scan2DGraph(self, y):
		strs = [None] * y
		for i in range(y):
			strs[i] = self.scanString().split()
		return strs

	# ScanInt reads and returns the next integer from the scanner.
	def scanInt(self):
		return int(self.scanInt64())

	# ScanInt2 reads and returns two integers from the scanner.
	def scanInt2(self):
		return int(self.scanInt64()), int(self.scanInt64())

	# ScanInt3 reads and returns three integers from the scanner.
	def scanInt3(self):
		return int(self.scanInt64()), int(self.scanInt64()), int(self.scanInt64())

	# ScanInt4 reads and returns four integers from the scanner.
	def scanInt4(self):
		return int(self.scanInt64()), int(self.scanInt64()), int(self.scanInt64()), int(self.scanInt64())

	# ScanInts reads and returns n integers from the scanner.
	def scanInts(self, n):
		ints = [None] * n
		for i in range(n):
			ints[i] = self.scanInt()
		return ints

	# Scan2DInts reads and returns a 2D slice of integers.
	def scan2DInts(self, y, x):
		ints = [None] * y
		for i in range(y):
			ints[i] = self.scanInts(x)
		return ints

	# ScanInt64 reads and returns the next 64-bit integer from the scanner.
	def scanInt64(self):
		i, err = strconv.ParseInt(self.scanString(), 10, 64)
		if err!= nil:
			raise RuntimeError(err)
		return i

	# ScanFloat64 reads and returns the next float64 from the scanner.
	def scanFloat64(self):
		i, err = strconv.ParseFloat(self.scanString(), 64)
		if err!= nil:
			raise RuntimeError(err)
		return i

	# ScanFloat64s reads and returns n float64 values from the scanner.
	def scanFloat64s(self, n):
		floats = [None] * n
		for i in range(n):
			floats[i] = self.scanFloat64()
		return floats

	# Println prints the arguments to the writer.
	def print(self, a):
		print(a, file=self.writer)
		self.writer.flush()

# Utility functions

# Flush flushes the writer.
def flush():
	sys.stdout.flush()

# newIO initializes an IO instance and returns it along with a function to flush the writer.
def newIO():
	io = IO()
	return io, io.flush

