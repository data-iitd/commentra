# Global variables to store counts and the result
a = []
ans = 0

# Depth-first search function to calculate combinations
def dfs(left, i, res):
	# If no more characters left to choose, add the result to ans
	if left == 0:
		global ans
		ans += res
		return
	# Iterate through the slice starting from index i
	for j in range(i, len(a)):
		# Recursive call to dfs with one less character to choose
		dfs(left-1, j+1, res*a[j])

def main():
	# Initialize input reader
	io = newIo()
	# Read the number of characters
	n = io.nextInt()
	# Map to count occurrences of specific characters
	dic = {}

	# Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
	for _ in range(n):
		c = io.nextString()[0] # Read the first character of the string
		if c in ['M', 'A', 'R', 'C', 'H']:
			dic[c] = dic.get(c, 0) + 1 # Increment count for the character if it's one of the specified

	# Populate the slice a with the counts from the dictionary
	for _, v in dic.items():
		a.append(v)

	# Start the DFS to calculate the product of combinations of 3 characters
	dfs(3, 0, 1)
	# Print the final result
	print(ans)

# Struct to handle input operations
class io:
	def __init__(self):
		self.reader = bufio.NewReader(os.Stdin) # Initialize the buffered reader
		self.tokens = [] # Slice to hold split input tokens
		self.nextToken = 0 # Index for the next token to read

	# Method to read the next line of input
	def nextLine(self):
		buffer = []
		for {
			line, isPrefix, _ := self.reader.ReadLine() # Read a line from input
			buffer.append(line) # Append the line to the buffer
			if not isPrefix:
				break # Exit if the line is not a prefix
		}
		return ''.join(buffer) # Return the complete line as a string

	# Method to read the next string token from input
	def nextString(self):
		# Load more tokens if the current index exceeds the available tokens
		for self.nextToken >= len(self.tokens):
			line = self.nextLine() # Read the next line
			self.tokens = line.split() # Split the line into tokens
			self.nextToken = 0 # Reset the token index
		r = self.tokens[self.nextToken] # Get the next token
		self.nextToken += 1 # Move to the next token
		return r # Return the token

	# Method to read the next integer from input
	def nextInt(self):
		return int(self.nextString()) # Convert the next string token to an integer

# Function to create a new io instance
def newIo():
	return io() # Initialize the buffered reader

if __name__ == '__main__':
	main()

