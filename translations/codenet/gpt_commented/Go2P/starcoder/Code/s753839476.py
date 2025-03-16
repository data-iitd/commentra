import sys

def main():
	# Initialize input/output handling
	io, flash = NewIO()
	# Ensure the writer is flushed before exiting
	defer flash()

	# Read the number of heights, target temperature, and actual temperature
	n, t, a = io.ScanInt(), io.ScanFloat64(), io.ScanFloat64()
	# Read the heights as a slice of float64
	heights = io.ScanFloat64s(n)

	# Initialize minimum difference and index for tracking the closest height
	minDiff = abs(t-heights[0]*0.006 - a)
	minIdx = 0

	# Iterate through the heights to find the one with the minimum temperature difference
	for i, h in enumerate(heights[1:]):
		diff = abs(t-h*0.006 - a)
		if diff < minDiff:
			minDiff = diff
			minIdx = i + 1 # Update the index of the closest height

	# Output the 1-based index of the closest height
	io.Println(minIdx + 1)

# AbsDiffFloat64 calculates the absolute difference between two float64 numbers
def abs(n1, n2):
	return abs(n1 - n2)

# IO struct for handling input and output operations
class IO:
	def __init__(self):
		self.scanner = self.newScanner()
		self.writer = self.newWriter()

	# newScanner creates and configures a new bufio.Scanner
	def newScanner(self):
		s = bufio.NewScanner(sys.stdin)
		s.Buffer(make([]byte, 10000000), 10000000) # Set buffer size for the scanner
		s.Split(bufio.ScanWords) # Split input by words
		return s

	# newWriter creates a new bufio.Writer for output
	def newWriter(self):
		return bufio.NewWriter(sys.stdout) # Write output to standard output

	# ScanBytes scans and returns a byte slice from input
	def ScanBytes(self):
		if not self.scanner.Scan():
			raise Exception("scan bytes failed") # Panic if scanning fails
		return self.scanner.Bytes() # Return scanned bytes

	# ScanString scans and returns a string from input
	def ScanString(self):
		if not self.scanner.Scan():
			raise Exception("scan string failed") # Panic if scanning fails
		return self.scanner.Text() # Return scanned string

	# ScanStrings scans and returns a slice of strings from input
	def ScanStrings(self, n):
		strs = [None] * n
		for i in range(n):
			strs[i] = self.ScanString() # Scan each string
		return strs # Return the slice of strings

	# Scan2DStrings scans and returns a 2D slice of strings from input
	def Scan2DStrings(self, y, x):
		strings = [None] * y
		for i in range(y):
			strings[i] = self.ScanStrings(x) # Scan each row of strings
		return strings # Return the 2D slice of strings

	# Scan2DGraph scans and returns a 2D slice of strings representing a graph
	def Scan2DGraph(self, y):
		strs = [None] * y
		for i in range(y):
			strs[i] = self.ScanString().split("") # Split each line into characters
		return strs # Return the 2D slice of characters

	# ScanInt scans and returns an integer from input
	def ScanInt(self):
		return int(self.ScanInt64()) # Convert scanned int64 to int

	# ScanInt2 scans and returns two integers from input
	def ScanInt2(self):
		return int(self.ScanInt64()), int(self.ScanInt64()) # Return two integers

	# ScanInt3 scans and returns three integers from input
	def ScanInt3(self):
		return int(self.ScanInt64()), int(self.ScanInt64()), int(self.ScanInt64()) # Return three integers

	# ScanInt4 scans and returns four integers from input
	def ScanInt4(self):
		return int(self.ScanInt64()), int(self.ScanInt64()), int(self.ScanInt64()), int(self.ScanInt64()) # Return four integers

	# ScanInts scans and returns a slice of integers from input
	def ScanInts(self, n):
		ints = [None] * n
		for i in range(n):
			ints[i] = self.ScanInt() # Scan each integer
		return ints # Return the slice of integers

	# Scan2DInts scans and returns a 2D slice of integers from input
	def Scan2DInts(self, y, x):
		ints = [None] * y
		for i in range(y):
			ints[i] = self.ScanInts(x) # Scan each row of integers
		return ints # Return the 2D slice of integers

	# ScanInt64 scans and returns an int64 from input
	def ScanInt64(self):
		i, err = int(self.ScanString()), None # Parse scanned string to int64
		if err!= None:
			raise Exception(err) # Panic if parsing fails
		return i # Return the int64 value

	# ScanFloat64 scans and returns a float64 from input
	def ScanFloat64(self):
		i, _ = float(self.ScanString()), None # Parse scanned string to float64
		return i # Return the float64 value

	# ScanFloat64s scans and returns a slice of float64 from input
	def ScanFloat64s(self, n):
		floats = [None] * n
		for i in range(n):
			floats[i] = self.ScanFloat64() # Scan each float64
		return floats # Return the slice of float64

	# Println writes a line to the output
	def Println(self, a):
		print(*a, file=self.writer) # Print the provided arguments to the writer

# NewIO initializes a new IO instance with a scanner and writer
def NewIO():
	return IO(), lambda: None # Return a function to flush the writer

if __name__ == "__main__":
	main()

