# Define a large constant for infinity
inf = 1e14

# ---------------------------------------------------------
def main():
	# Set log flags to show the file name and line number
	log.setflags(log.lshortfile)

	# Initialize a new scanner for input
	next = newScanner()

	# Read the number of elements and the value of x
	n = next.int()
	x = next.int()

	# Create a slice to hold the input integers
	a = make([]int, n)

	# Read n integers into the slice a
	for i in range(n):
		a[i] = next.int()

	# Create a copy of the slice a for manipulation
	v = make([]int, n)
	copy(v, a)

	# Initialize the answer to infinity
	ans = inf

	# Iterate over each possible k value
	for k in range(n):
		kans = 0 # Initialize the current answer for this k

		# Calculate the minimum values for the current k
		for i in range(n):
			if i-k < 0:
				# If i-k is out of bounds, use the wrapped index
				v[i] = min(v[i], a[n+i-k])
			else:
				# Otherwise, use the normal index
				v[i] = min(v[i], a[i-k])
			# Accumulate the current answer
			kans += v[i]
		# Update the overall answer with the minimum found so far
		ans = min(ans, kans+k*x)
	# Print the final answer
	print(ans)

# ---------------------------------------------------------

# Pair represents a pair of integers
class Pair:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Pairs is a slice of Pair structs that can be sorted
class Pairs(list):
	# Implement the sort.Interface for Pairs
	def __init__(self, l):
		list.__init__(self, l)
	def Len(self):
		return len(self)
	def Swap(self, i, j):
		self[i], self[j] = self[j], self[i]
	def Less(self, i, j):
		# Define sorting criteria based on the first and second elements of the pairs
		if self[i].a < self[j].a:
			return True
		elif self[i].a == self[j].a:
			return self[i].b < self[j].b
		return False

# -------------------------------

# in checks if c is within the range [a, z)
def in(c, a, z):
	return c >= a and c < z

# btoi converts a boolean to an integer (1 for true, 0 for false)
def btoi(b):
	if b:
		return 1
	return 0

# itob converts an integer to a boolean (false for 0, true for non-zero)
def itob(a):
	if a == 0:
		return False
	return True

# max returns the maximum value from a list of integers
def max(a):
	r = a[0]
	for i in range(len(a)):
		if r < a[i]:
			r = a[i]
	return r

# min returns the minimum value from a list of integers
def min(a):
	r = a[0]
	for i in range(len(a)):
		if r > a[i]:
			r = a[i]
	return r

# minmax returns the minimum and maximum of two integers
def minmax(a, b):
	if a > b:
		return b, a
	return a, b

# abs returns the absolute value of an integer
def abs(a):
	if a < 0:
		return -a
	return a

# sum returns the sum of a list of integers
def sum(a):
	r = a[0]
	if len(a) > 1:
		for i in range(1, len(a)):
			r += a[i]
	return r

# ---------- buffered scanner -----------------------------------------

# scanner is a custom buffered scanner for reading input
class scanner:
	def __init__(self):
		self.r = bufio.NewReaderSize(os.stdin, 10000)
		self.buf = []
		self.p = 0
	def next(self):
		self.pre() # Ensure the buffer is filled
		start = self.p
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] =='':
				break
		result = string(self.buf[start:self.p])
		self.p++ # Move past the space
		return result
	def Line(self):
		self.pre() # Ensure the buffer is filled
		start = self.p
		self.p = len(self.buf) # Move to the end of the buffer
		return string(self.buf[start:])
	def Int(self):
		v, _ = strconv.Atoi(self.next())
		return v
	def Int64(self):
		v, _ = strconv.ParseInt(self.next(), 10, 64)
		return v
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine() # Read a new line into the buffer
			self.p = 0     # Reset the position to the start of the buffer
	def readLine(self):
		self.buf = make([]byte, 0) # Clear the buffer
		for {
			l, p, e := self.r.ReadLine() # Read a line
			if e!= nil:
				panic(e) # Handle any read errors
			self.buf = append(self.buf, l...) # Append the line to the buffer
			if!p:
				break # Exit if the line is complete
		}

