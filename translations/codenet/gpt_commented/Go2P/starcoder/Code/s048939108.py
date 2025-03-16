import sys

# Create a new scanner to read input
sc = newScanner()

# Read a string from the input
S = sc.next()

# Check if the string starts with "YAKI" and print the corresponding response
if S.startswith("YAKI"):
	print("Yes")
else:
	print("No")

# min returns the smaller of two integers
def min(a, b):
	if a > b:
		return b
	return a

# max returns the larger of two integers
def max(a, b):
	if a > b:
		return a
	return b

# scanner struct to handle buffered input reading
class scanner:
	def __init__(self):
		self.r = sys.stdin # Buffered reader
		self.buf = [] # Buffer to hold the input data
		self.p = 0 # Current position in the buffer

	# next reads the next word from the input
	def next(self):
		self.pre() # Ensure the buffer is filled
		start = self.p # Mark the start of the word
		# Iterate through the buffer until a space is found
		for ; self.p < len(self.buf); self.p += 1:
			if self.buf[self.p] =='':
				break
		result = self.buf[start:self.p] # Extract the word
		self.p += 1 # Move past the space
		return result # Return the word

	# nextLine reads the next line from the input
	def nextLine(self):
		self.pre() # Ensure the buffer is filled
		start = self.p # Mark the start of the line
		self.p = len(self.buf) # Move to the end of the buffer
		return self.buf[start:] # Return the line

	# nextInt reads the next integer from the input
	def nextInt(self):
		v, _ = int(self.next()), None # Convert the next word to an integer
		return v # Return the integer

	# nextIntArray reads a space-separated array of integers from the input
	def nextIntArray(self):
		self.pre() # Ensure the buffer is filled
		start = self.p # Mark the start of the array
		result = [] # Initialize an empty slice for the results
		# Iterate through the buffer to extract integers
		for ; self.p < len(self.buf)+1; self.p += 1:
			if self.p == len(self.buf) or self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None # Parse the integer
				result.append(v) # Append the integer to the result slice
				start = self.p + 1 # Update the start position for the next integer
		return result # Return the slice of integers

	# pre checks if the buffer needs to be filled
	def pre(self):
		if self.p >= len(self.buf): # If the current position is at or beyond the buffer length
			self.readLine() # Read a new line into the buffer
			self.p = 0 # Reset the position to the start of the buffer

	# readLine reads a line from the input and fills the buffer
	def readLine(self):
		self.buf = [] # Reset the buffer
		for l in self.r: # Read a line from the buffered reader
			self.buf.append(l) # Append the line to the buffer
			if not l: # If the line is complete
				break # Exit the loop

