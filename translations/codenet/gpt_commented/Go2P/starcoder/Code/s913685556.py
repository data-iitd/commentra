import sys

def main():
	# Create a new scanner to read input
	sc = NewScanner()
	# Read two integers from input
	A, B = sc.NextInt(), sc.NextInt()

	# Calculate the maximum of A+B, A-B, and A*B
	mx = max(A+B, A-B)
	mx = max(mx, A*B)
	# Print the maximum value
	print(mx)

# Function to return the maximum of two integers
def max(a, b):
	if a < b:
		return b
	return a

# Scanner struct to handle input reading
class Scanner:
	def __init__(self):
		self.r = sys.stdin # Buffered reader for input
		self.buf = '' # Buffer to hold the input data
		self.p = 0 # Current position in the buffer

	# Next reads the next token from the input
	def Next(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start of the token
		# Iterate through the buffer to find the next space
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				break
		result = self.buf[start:self.p] # Extract the token from the buffer
		self.p += 1 # Move past the space
		return result # Return the token

	# NextLine reads the next line from the input
	def NextLine(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start of the line
		self.p = len(self.buf) # Move to the end of the buffer
		return self.buf[start:] # Return the line

	# NextInt reads the next integer from the input
	def NextInt(self):
		v, _ = int(self.Next()), None # Convert the next token to an integer
		return v # Return the integer

	# NextInt64 reads the next int64 from the input
	def NextInt64(self):
		v, _ = int(self.Next()), None # Convert the next token to int64
		return v # Return the int64 value

	# NextFloat reads the next float64 from the input
	def NextFloat(self):
		v, _ = float(self.Next()), None # Convert the next token to float64
		return v # Return the float64 value

	# NextIntArray reads a space-separated array of integers from the input
	def NextIntArray(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start of the array
		result = [] # Initialize an empty slice to hold the integers
		# Iterate through the buffer to read integers
		for self.p < len(self.buf)+1:
			if self.p == len(self.buf) or self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None # Parse the integer
				result.append(v) # Append the integer to the result slice
				start = self.p + 1 # Update the start position for the next integer
			self.p += 1
		return result # Return the slice of integers

	# NextInt64Array reads a space-separated array of int64 from the input
	def NextInt64Array(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start of the array
		result = [] # Initialize an empty slice to hold the int64 values
		# Iterate through the buffer to read int64 values
		for self.p < len(self.buf)+1:
			if self.p == len(self.buf) or self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None # Parse the int64
				result.append(v) # Append the int64 to the result slice
				start = self.p + 1 # Update the start position for the next int64
			self.p += 1
		return result # Return the slice of int64 values

	# NextMap reads a space-separated map of integers to booleans from the input
	def NextMap(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start of the map
		mp = {} # Initialize an empty map
		# Iterate through the buffer to read integers
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None # Parse the integer
				mp[v] = True # Set the map entry to true
				start = self.p + 1 # Update the start position for the next integer
			self.p += 1
		v, _ = int(self.buf[start:self.p]), None # Parse the last integer
		mp[v] = True # Set the last map entry to true

		return mp # Return the map

	# pre checks if more data needs to be read into the buffer
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine() # Read a new line if the current position is at the end of the buffer
			self.p = 0 # Reset the position to the start of the new buffer

	# readLine reads a full line from the input and stores it in the buffer
	def readLine(self):
		self.buf = '' # Initialize the buffer
		for l in self.r:
			self.buf += l # Append the line to the buffer
			if not l.endswith('\n'):
				break # Break if the line is complete

# Start the execution if it's the main script
if __name__ == "__main__":
	main()

