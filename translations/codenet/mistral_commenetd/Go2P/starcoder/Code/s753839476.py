
import sys

# Initialize IO object and handle resources
def main():
	io, flash := NewIO()
	defer flash()

	# Read input values
	n, t, a = io.ScanInt(), io.ScanFloat64(), io.ScanFloat64()

	# Initialize variables for heights and minimum difference
	heights = io.ScanFloat64s(n)
	minDiff = AbsDiffFloat64(t-heights[0]*0.006, a)
	minIdx = 0

	# Iterate through the remaining heights and find the minimum difference
	for i, h in enumerate(heights[1:]):
		# Calculate the difference between the target and the height
		diff = AbsDiffFloat64(t-h*0.006, a)

		# Update minimum difference and index if the current difference is smaller
		if diff < minDiff:
			minDiff = diff
			minIdx = i + 1

	# Print the result
	print(minIdx + 1)

# Calculate absolute difference between two float64 numbers
def AbsDiffFloat64(n1, n2):
	return abs(n1 - n2)

# Initialize IO object with scanner and writer
class IO:
	def __init__(self):
		self.scanner = sys.stdin
		self.writer = sys.stdout

	# Read a single byte from the scanner
	def ScanBytes(self):
		return self.scanner.readline().rstrip()

	# Read a single string from the scanner
	def ScanString(self):
		return self.scanner.readline().rstrip()

	# Read multiple strings from the scanner
	def ScanStrings(self, n):
		strs = []
		for i in range(n):
			strs.append(self.ScanString())
		return strs

	# Read a 2D array of strings from the scanner
	def Scan2DStrings(self, y, x):
		strings = []
		for i in range(y):
			strings.append(self.ScanStrings(x))
		return strings

	# Read a 2D array of graphs from the scanner
	def Scan2DGraph(self, y):
		strs = []
		for i in range(y):
			strs.append(self.ScanString().split())
		return strs

	# Read a single integer from the scanner
	def ScanInt(self):
		return int(self.ScanInt64())

	# Read two integers from the scanner
	def ScanInt2(self):
		return int(self.ScanInt64()), int(self.ScanInt64())

	# Read three integers from the scanner
	def ScanInt3(self):
		return int(self.ScanInt64()), int(self.ScanInt64()), int(self.ScanInt64())

	# Read four integers from the scanner
	def ScanInt4(self):
		return int(self.ScanInt64()), int(self.ScanInt64()), int(self.ScanInt64()), int(self.ScanInt64())

	# Read a slice of integers from the scanner
	def ScanInts(self, n):
		ints = []
		for i in range(n):
			ints.append(self.ScanInt())
		return ints

	# Read a 2D slice of integers from the scanner
	def Scan2DInts(self, y, x):
		ints = []
		for i in range(y):
			ints.append(self.ScanInts(x))
		return ints

	# Read a single int64 from the scanner
	def ScanInt64(self):
		return int(self.ScanString())

	# Read a single float64 from the scanner
	def ScanFloat64(self):
		return float(self.ScanString())

	# Read a slice of float64 from the scanner
	def ScanFloat64s(self, n):
		floats = []
		for i in range(n):
			floats.append(self.ScanFloat64())
		return floats

	# Write a single line to the writer
	def Println(self, a):
		print(a, file=self.writer)

	# Flush the writer buffer
	def Flush(self):
		self.writer.flush()

# Function to handle resource deallocation
def flash():
	io.scanner.close()
	io.writer.flush()
	sys.stdin.close()
	sys.stdout.close()

# Function to calculate the absolute difference between two float64 numbers
def AbsDiffFloat64(n1, n2):
	return abs(n1 - n2)

# Create new IO object
def NewIO():
	io = IO()
	return io, flash

# 