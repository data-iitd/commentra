# by syu
import sys

# Initialize a new Scanner to read from standard input
in = NewScanner(sys.stdin, 0)

def main():
	# Read two integers n and k from input
	n, k = in.Int(), in.Int()
	
	# Check if n is divisible by k
	if n%k == 0:
		# If divisible, print 0
		Pln(0)
	else:
		# If not divisible, print 1
		Pln(1)

# Scanner struct wraps bufio.Scanner for custom functionality
class Scanner:
	def __init__(self, r, max):
		self.s = bufio.NewScanner(r) # Create a new bufio.Scanner
		self.s.Split(scanWords) # Set the split function to scanWords
		if max <= 0:
			max = 1048576 # Default buffer size if max is not specified
		self.s.Buffer([], max) # Set the buffer size for the scanner

	# Int reads the next token from the input and converts it to an integer
	def Int(self):
		self.s.Scan() # Scan the next token
		i, e = int(s.Text()), None # Parse the token as an integer
		if e!= None:
			raise e # Panic if there is an error during parsing
		return i # Return the parsed integer

# isSpace checks if a byte is a whitespace character
def isSpace(b):
	return b =='' or b == '\n' or b == '\r' or b == '\t' # Return true for whitespace

# scanWords is a split function for bufio.Scanner that splits input into words
def scanWords(data, atEOF):
	start = 0
	# Skip leading whitespace
	for start < len(data) and isSpace(data[start]):
		start++
	# Find the end of the next word
	for i := start; i < len(data); i++:
		if isSpace(data[i]):
			return i + 1, data[start:i], None # Return the word and advance position
	# If at EOF and there is data left, return the last word
	if atEOF and len(data) > start:
		return len(data), data[start:], None
	# Return the current position if no word is found
	return start, None, None

# Pln is a helper function to print a line with a newline
def Pln(s):
	print(s) # Print the provided arguments

if __name__ == "__main__":
	main()

