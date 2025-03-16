import sys

# get_scanner initializes a new scanner for reading from the provided file pointer.
def get_scanner(fp):
	scanner = fp.readline
	return lambda: scanner().strip()

# get_next_string retrieves the next string from the scanner.
def get_next_string(scanner):
	return scanner()

# get_next_int retrieves the next integer from the scanner.
def get_next_int(scanner):
	return int(scanner())

# get_next_int64 retrieves the next int64 from the scanner.
def get_next_int64(scanner):
	return int(scanner())

# get_next_uint64 retrieves the next uint64 from the scanner.
def get_next_uint64(scanner):
	return int(scanner())

# get_next_float64 retrieves the next float64 from the scanner.
def get_next_float64(scanner):
	return float(scanner())

def main():
	# Determine the input source: either standard input or a file specified as a command-line argument
	fp = sys.stdin
	if len(sys.argv) > 1:
		fp = open(sys.argv[1], "r") # Open the file if an argument is provided

	scanner = get_scanner(fp) # Initialize the scanner for the input source
	writer = sys.stdout # Create a buffered writer for output

	# Read the number of elements and operations
	n = get_next_int(scanner)
	m = get_next_int(scanner)

	# Initialize the Segment structure
	seg = Segment()
	seg.init(n) # Initialize the segment with size n

	# Populate the segment with initial values
	for i in range(n):
		seg.maximize(i, get_next_int(scanner)) # Maximize the segment with the input values

	# Perform m operations to maximize the segment
	for i in range(m):
		seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1) # Maximize using the top value and half of the last bucket's first element

	# Calculate the final answer by summing up the values in the first bucket
	ans = 0
	for i in range(n):
		ans += seg.bucket[0][i] # Accumulate the values

	# Output the final result
	print(ans)

# Segment structure to hold the segment data and operations
class Segment:
	def __init__(self):
		self.n = 0
		self.h = 0
		self.i = 0
		self.chunk = 0
		self.unit = []
		self.bucket = []

	# init initializes the segment structure with the given size n.
	def init(self, n):
		self.n = n
		self.unit = [1] # Initialize unit array
		self.bucket = [[0 for i in range(n)]] # Initialize bucket array

		chunk = 8 # Define the chunk size
		for i in range(0, n):
			n = (n-1)/chunk + 1 # Reduce n based on the chunk size
			self.bucket.append([0 for i in range(n)]) # Append a new bucket
			self.unit.append(self.unit[i]*chunk) # Update unit array
		self.h = len(self.unit) # Set the height of the segment
		self.chunk = chunk # Set the chunk size

	# maximize updates the segment at a given index with a new value.
	def maximize(self, index, value):
		self.bucket[0][index] = value # Set the value in the first bucket
		for self.i in range(0, self.h-1):
			s = index - index%self.chunk # Calculate the start of the current chunk
			t = s + self.chunk # Calculate the end of the current chunk
			if t > len(self.bucket[self.i]):
				t = len(self.bucket[self.i]) # Adjust end if it exceeds the bucket length
			parent = index / self.chunk # Determine the parent index
			max = 0 # Initialize max value
			for i in range(s, t):
				if max < self.bucket[self.i][i]:
					max = self.bucket[self.i][i] # Find the maximum value in the current chunk
			self.bucket[self.i+1][parent] = max # Update the parent bucket with the maximum value
			index /= self.chunk # Move to the parent index for the next iteration

	# top retrieves the index of the top value in the segment.
	def top(self):
		index = 0 # Start from the root index
		for self.i in range(self.h-2, -1, -1):
			s = index * self.chunk # Calculate the start of the current chunk
			t = s + self.chunk # Calculate the end of the current chunk
			if t > len(self.bucket[self.i]):
				t = len(self.bucket[self.i]) # Adjust end if it exceeds the bucket length
			for i in range(s, t):
				if self.bucket[self.i][i] == self.bucket[self.i+1][index]:
					index = i # Update index if the value matches the top value
					break
		return index # Return the index of the top value

