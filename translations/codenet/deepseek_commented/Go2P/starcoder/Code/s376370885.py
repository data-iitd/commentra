
# by syu
import sys

# Initialize a global Scanner instance to read from standard input
in = NewScanner(sys.stdin, 0)

def main():
	# Read two integers, n and k, from standard input
	n, k = in.Int(), in.Int()
	
	# Check if n is divisible by k
	if n%k == 0:
		# If n is divisible by k, print 0
		Pln(0)
	else:
		# If n is not divisible by k, print 1
		Pln(1)

# Define a custom Scanner type to read input efficiently
class Scanner:
	def __init__(self, r, max):
		self.r = r
		self.max = max
		self.buf = []
		self.pos = 0
		self.tok = None
		self.eof = False
	
	# Read and return an integer from the input
	def Int(self):
		self.Scan()
		i, e = int(self.tok), None
		if e!= None:
			raise e
		return i
	
	# Helper function to check if a byte is a space character
	def isSpace(self, b):
		return b =='' or b == '\n' or b == '\r' or b == '\t'
	
	# Custom split function for bufio.Scanner to split input by words
	def scanWords(self, data, atEOF):
		start = 0
		for start < len(data) and self.isSpace(data[start]):
			start++
		for i := start; i < len(data); i++:
			if self.isSpace(data[i]):
				return i + 1, data[start:i], None
		if atEOF and len(data) > start:
			return len(data), data[start:], None
		return start, None, None
	
	# Helper function to print a line of output
	def Pln(self, s):
		print(s)
	
	# Read and return a token from the input
	def Scan(self):
		if self.tok!= None:
			self.pos, self.tok = 0, None
		if self.pos >= len(self.buf):
			if self.eof:
				return
			self.buf, self.eof = [], False
			for line in self.r:
				self.buf = self.buf + line.split()
			self.pos, self.tok, self.err = self.scanWords(self.buf, self.eof)
		if self.err!= None:
			raise self.err
		return self.tok

# Create a new Scanner instance with a specified buffer size
def NewScanner(r, max):
	return Scanner(r, max)

# Translate the above Go code to Python and end with comment "