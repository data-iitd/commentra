import sys

def main():
	# Create a new scanner to read input
	sc = NewScanner()
	
	# Read three integers from input: H, W, and N
	H, W, N = sc.NextInt(), sc.NextInt(), sc.NextInt()

	# Calculate the maximum of H and W
	A = max(H, W)

	# Calculate and print the number of full groups needed to accommodate N items
	print((N + A - 1) / A)

# Function to return the maximum of two integers
def max(a, b):
	if a < b:
		return b
	return a

# Scanner struct to facilitate reading input
class Scanner:
	def __init__(self):
		self.r = sys.stdin # Create a new buffered reader for input
		self.buf = '' # Initialize an empty buffer
		self.p = 0 # Initialize the current position in the buffer

	# Next reads the next token from the input
	def Next(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start of the token
		for self.p < len(self.buf):
			if self.buf[self.p] =='': # Stop at space character
				break
		result = self.buf[start:self.p] # Extract the token
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
		return v # Return the int64

	# NextFloat reads the next float64 from the input
	def NextFloat(self):
		v, _ = float(self.Next()), None # Convert the next token to float64
		return v # Return the float64

	# NextIntArray reads a slice of integers from the input
	def NextIntArray(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start of the array
		result = [] # Initialize an empty slice to hold the integers
		for self.p < len(self.buf)+1:
			if self.p == len(self.buf) or self.buf[self.p] =='': # Check for end of buffer or space
				v, _ = int(self.buf[start:self.p]), None # Parse the integer
				result.append(v) # Append to the result slice
				start = self.p + 1 # Update start for the next integer
			self.p += 1
		return result # Return the slice of integers

	# NextInt64Array reads a slice of int64 from the input
	def NextInt64Array(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start of the array
		result = [] # Initialize an empty slice to hold the int64 values
		for self.p < len(self.buf)+1:
			if self.p == len(self.buf) or self.buf[self.p] =='': # Check for end of buffer or space
				v, _ = int(self.buf[start:self.p]), None # Parse the int64
				result.append(v) # Append to the result slice
				start = self.p + 1 # Update start for the next int64
			self.p += 1
		return result # Return the slice of int64

	# NextMap reads a map of integers from the input
	def NextMap(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start of the map
		mp = {} # Initialize an empty map
		for self.p < len(self.buf):
			if self.buf[self.p] =='': # Check for space
				v, _ = int(self.buf[start:self.p]), None # Parse the integer
				mp[v] = True # Add to the map
				start = self.p + 1 # Update start for the next integer
			self.p += 1
		v, _ = int(self.buf[start:self.p]), None # Parse the last integer
		mp[v] = True # Add the last integer to the map

		return mp # Return the map

	# pre checks if there is data to read and reads a new line if necessary
	def pre(self):
		if self.p >= len(self.buf): # If current position is at the end of the buffer
			self.readLine() # Read a new line
			self.p = 0 # Reset position to the start of the new line

	# readLine reads a full line from the input and stores it in the buffer
	def readLine(self):
		self.buf = '' # Reset the buffer
		for l in self.r: # Read a line from the buffered reader
			self.buf += l # Append the line to the buffer
		self.buf += '\n' # Add a new line character to the end of the buffer

# Start the execution if it's the main script
if __name__ == "__main__":
	main()

