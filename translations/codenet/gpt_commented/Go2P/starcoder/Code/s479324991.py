import sys

def main():
	# Initialize a new scanner to read input
	sc = NewScanner()

	# Read the number of elements
	n = sc.NextInt()
	# Create a slice to hold the float64 values
	arr = []

	# Read n integers from input and convert them to float64
	for i in range(n):
		arr.append(float(sc.NextInt()))

	# Sort the array of float64 values
	arr.sort()

	# Initialize 'prev' with the first element of the sorted array
	prev = arr[0]

	# Calculate the average of the elements iteratively
	for i in range(1, len(arr)):
		prev = (prev + arr[i]) / 2

	# Print the final computed average
	print(prev)

# Scanner struct to handle input reading
class Scanner:
	def __init__(self):
		self.r = sys.stdin # Buffered reader for input
		self.buf = '' # Buffer to hold the input line
		self.p = 0 # Current position in the buffer

	# Next reads the next token from the input
	def Next(self):
		self.pre() # Ensure the buffer is filled
		start = self.p # Mark the start of the token
		# Iterate through the buffer to find the next space
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				break
		result = self.buf[start:self.p] # Extract the token
		self.p += 1 # Move past the space
		return result # Return the token

	# NextLine reads the next line from the input
	def NextLine(self):
		self.pre() # Ensure the buffer is filled
		start = self.p # Mark the start of the line
		self.p = len(self.buf) # Move to the end of the buffer
		return self.buf[start:] # Return the line

	# NextInt reads the next integer from the input
	def NextInt(self):
		return int(self.Next()) # Convert the next token to an integer

	# NextIntArray reads a space-separated array of integers from the input
	def NextIntArray(self):
		self.pre() # Ensure the buffer is filled
		start = self.p # Mark the start of the first integer
		result = [] # Initialize an empty slice for the integers
		# Iterate through the buffer to find space-separated integers
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				result.append(int(self.buf[start:self.p])) # Append the integer to the result slice
				start = self.p + 1 # Update the start position for the next integer
			self.p += 1
		result.append(int(self.buf[start:self.p])) # Append the last integer to the result slice

		return result # Return the slice of integers

	# NextMap reads a space-separated map of integers to booleans from the input
	def NextMap(self):
		self.pre() # Ensure the buffer is filled
		start = self.p # Mark the start of the first integer
		mp = {} # Initialize an empty map
		# Iterate through the buffer to find space-separated integers
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				mp[int(self.buf[start:self.p])] = True # Set the integer as a key in the map with a value of true
				start = self.p + 1 # Update the start position for the next integer
			self.p += 1
		mp[int(self.buf[start:self.p])] = True # Set the last integer as a key in the map

		return mp # Return the map of integers

	# pre checks if the buffer needs to be filled
	def pre(self):
		if self.p >= len(self.buf): # If the current position is at or beyond the buffer length
			self.readLine() # Read a new line into the buffer
			self.p = 0 # Reset the position to the start of the buffer

	# readLine reads a full line from the input into the buffer
	def readLine(self):
		self.buf = '' # Reset the buffer
		for l in self.r: # Read a line from the buffered reader
			self.buf += l # Append the line to the buffer
			if not l.endswith('\n'): # If the line is not a continuation
				break # Exit the loop

if __name__ == '__main__':
	main()

