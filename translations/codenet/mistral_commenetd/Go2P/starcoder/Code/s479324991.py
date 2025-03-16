import sys

# Initialize a new scanner object
def main():
	sc = NewScanner()

	# Read the number of elements in the array from the standard input
	n = sc.NextInt()

	# Allocate memory for the array of size n
	arr = make([]float64, n)

	# Read n integers from the standard input and store them in the array
	for i in range(n):
		arr[i] = float64(sc.NextInt())

	# Sort the array in ascending order
	sort.Float64s(arr)

	# Initialize a variable prev to store the previous element in the sorted array
	prev = arr[0]

	# Iterate through the sorted array from the second element to the last
	for i in range(1, len(arr)):
		# Calculate the average of the previous and current elements
		prev = (prev + arr[i]) / 2

	# Print the result to the standard output
	print(prev)

# Initialize a new scanner object
class Scanner:
	def __init__(self):
		self.r = bufio.NewReaderSize(sys.stdin, 1000)
		self.buf = []
		self.p = 0

	# Read a single token from the standard input
	def Next(self):
		self.pre()
		start = self.p
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] =='':
				break
		result = string(self.buf[start:self.p])
		self.p++
		return result

	# Read a line from the standard input
	def NextLine(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		return string(self.buf[start:])

	# Read an integer from the standard input
	def NextInt(self):
		v, _ = int(self.Next())
		return v

	# Read an array of integers from the standard input
	def NextIntArray(self):
		self.pre()
		start = self.p
		result = []
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] =='':
				v, _ = int(string(self.buf[start:self.p]))
				result = append(result, v)
				start = self.p + 1
		v, _ = int(string(self.buf[start:self.p]))
		result = append(result, v)

		return result

	# Read a map from the standard input
	def NextMap(self):
		self.pre()
		start = self.p
		mp = map[int]bool{}
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] =='':
				v, _ = int(string(self.buf[start:self.p]))
				mp[v] = true
				start = self.p + 1
		v, _ = int(string(self.buf[start:self.p]))
		mp[v] = true

		return mp

	# Prepare the scanner for the next read operation
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine()
			self.p = 0

	# Read a line from the standard input
	def readLine(self):
		self.buf = make([]byte, 0)
		for {
			l, p, e := self.r.ReadLine()
			if e!= nil:
				panic(e)
			self.buf = append(self.buf, l...)
			if!p:
				break
		}

# Create a new scanner object
def NewScanner():
	return Scanner()

# 