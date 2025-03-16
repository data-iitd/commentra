import sys

# Main function where the execution starts
def main():
	# Create a new scanner to read input
	sc = NewScanner()

	# Read the number of integers to process
	n = sc.NextInt()
	ans = 0.0

	# Loop through each integer, calculate the reciprocal, and accumulate the sum
	for i in range(n):
		tmp = 1 / float(sc.NextInt())
		ans += tmp

	# Print the harmonic mean of the input integers
	print(1/ans)

# Scanner struct to handle input reading efficiently
class Scanner:
	def __init__(self):
		self.r = sys.stdin # Buffered reader for input
		self.buf = '' # Buffer to hold the input line
		self.p = 0 # Current position in the buffer

	# Next reads the next token from the input
	def Next(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
		# Iterate through the buffer to find the next space
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				break # Stop at the first space
		result = self.buf[start:self.p] # Extract the token
		self.p += 1 # Move past the space
		return result # Return the token

	# NextLine reads the next full line from the input
	def NextLine(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
		self.p = len(self.buf) # Move to the end of the buffer
		return self.buf[start:] # Return the line

	# NextInt reads the next integer from the input
	def NextInt(self):
		v, _ = int(self.Next()), None # Convert the next token to an integer
		return v # Return the integer

	# NextIntArray reads a space-separated array of integers from the input
	def NextIntArray(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
		result = [] # Initialize an empty slice for the results
		# Iterate through the buffer to find integers separated by spaces
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None # Convert the token to an integer
				result.append(v) # Append the integer to the result slice
				start = self.p + 1 # Update the start position
		v, _ = int(self.buf[start:self.p]), None # Convert the last token to an integer
		result.append(v) # Append the last integer to the result slice

		return result # Return the slice of integers

	# NextMap reads a space-separated list of integers into a map
	def NextMap(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
		mp = {} # Initialize an empty map
		# Iterate through the buffer to find integers separated by spaces
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None # Convert the token to an integer
				mp[v] = True # Add the integer to the map
				start = self.p + 1 # Update the start position
		v, _ = int(self.buf[start:self.p]), None # Convert the last token to an integer
		mp[v] = True # Add the last integer to the map

		return mp # Return the map of integers

	# pre checks if there is data to read and reads a new line if necessary
	def pre(self):
		if self.p >= len(self.buf): # If the current position is at the end of the buffer
			self.readLine() # Read a new line
			self.p = 0 # Reset the position to the start of the new line

	# readLine reads a full line from the input and stores it in the buffer
	def readLine(self):
		self.buf = '' # Reset the buffer
		for l in self.r: # Read a line from the buffered reader
			self.buf += l # Append the line to the buffer
			if not l.endswith('\n'): # If the line is not a continuation
				break # Exit the loop

# Start the execution if it's the main script
if __name__ == "__main__":
	main()

