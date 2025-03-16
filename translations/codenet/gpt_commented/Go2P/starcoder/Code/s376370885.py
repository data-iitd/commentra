# by syu
import sys

# Initialize a new Scanner for reading input from standard input (sys.stdin)
in = NewScanner(sys.stdin, 0)

def main():
	# Read two integers n and k from the input
	n, k = in.Int(), in.Int()
	
	# Check if n is divisible by k
	if n%k == 0:
		# If n is divisible by k, print 0
		print(0)
	else:
		# If n is not divisible by k, print 1
		print(1)

# Scanner struct wraps bufio.Scanner for custom input handling
class Scanner:
	def __init__(self, r, max):
		self.s = bufio.NewScanner(r) # Create a new Scanner
		self.s.Split(self.scanWords) # Set the split function to scan words
		if max <= 0:
			max = 1048576 # Default buffer size if max is not specified
		self.s.Buffer([], max) # Set the buffer size for the scanner

	# Int reads the next token from the input and converts it to an integer
	def Int(self):
		self.s.Scan() # Scan the next token
		i, e = int(s.Text()), None # Parse the token as an integer
		if e!= None:
			raise e # Panic if there is an error during parsing
		return i

	# isSpace checks if a byte is a whitespace character
	def isSpace(self, b):
		return b =='' or b == '\n' or b == '\r' or b == '\t'

	# scanWords is a custom split function for the Scanner to tokenize input
	def scanWords(self, data, atEOF):
		start = 0
		# Skip leading whitespace
		for start < len(data) and self.isSpace(data[start]):
			start++
		# Find the end of the next word
		for i := start; i < len(data); i++:
			if self.isSpace(data[i]):
				return i + 1, data[start:i], None # Return the word found
		# If at EOF and there is data left, return the last word
		if atEOF and len(data) > start:
			return len(data), data[start:], None
		return start, None, None # Return the current position if no word is found

# Pln is a convenience function to print a line to standard output
def Pln(s):
	print(s) # Print the provided arguments

if __name__ == "__main__":
	main()

