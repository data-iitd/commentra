
# FastScanner class for reading input efficiently
class FastScanner:
	def __init__(self):
		# Initialize a new bufio.Reader with a buffer size of 1024 bytes
		self.r = bufio.NewReaderSize(sys.stdin.buffer, 1024)
		# Initialize a new string for storing the current line
		self.line = ""

	def Next(self):
		# Read the next line into the internal buffer if it is empty
		if self.line == "":
			self.line = self.r.readline().decode()

		# Find the start index of the next token
		start = self.line.find(" ")
		# Find the end index of the next token (space or newline character)
		end = self.line.find(" ", start + 1)

		# If the end index is -1, set it to the length of the line
		if end == -1:
			end = len(self.line)

		# Extract the token from the internal buffer
		token = self.line[start:end]
		# Remove the token from the internal buffer
		self.line = self.line[end + 1:]

		# Return the token
		return token

	def NextLine(self):
		# Read the next line into the internal buffer if it is empty
		if self.line == "":
			self.line = self.r.readline().decode()

		# Return the internal buffer
		return self.line

	def NextInt(self):
		# Read the next token as an integer
		token = self.Next()
		# Convert the token to an integer and return it
		return int(token)

# main function is the entry point of our program
def main():
	# Initialize a new FastScanner object called fsc
	fsc = FastScanner()

	# Read the first three integers A, B, and C from the standard input
	A, B, C = fsc.NextInt(), fsc.NextInt(), fsc.NextInt()

	# Check if the difference between B and A is equal to the difference between C and B
	if B-A == C-B:
		# If it is, print "YES"
		print("YES")
	else:
		# Otherwise, print "NO"
		print("NO")

# Call the main function
if __name__ == "__main__":
	main()

# 