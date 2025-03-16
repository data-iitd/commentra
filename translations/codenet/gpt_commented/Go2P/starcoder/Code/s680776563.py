import sys

def main():
	# Initialize a new FastScanner to read input
	fsc = NewFastScanner()
	# Read three integers A, B, and C from input
	A, B, C = fsc.NextInt(), fsc.NextInt(), fsc.NextInt()
	# Check if the difference between B and A is equal to the difference between C and B
	if B-A == C-B:
		# If the differences are equal, print "YES"
		print("YES")
	else:
		# Otherwise, print "NO"
		print("NO")

# FastScanner is a structure for efficient input reading
class FastScanner:
	def __init__(self):
		# Create a new buffered reader with a specified size
		self.r = bufio.NewReaderSize(sys.stdin, 1024)
		self.buf = ""
		self.p = 0

	# Next reads the next token from the input
	def Next(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
		# Iterate through the buffer until a space is found
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] =='':
				break
		result = self.buf[start:self.p] # Extract the token
		self.p++ # Move past the space
		return result # Return the token

	# NextLine reads the next line from the input
	def NextLine(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
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

	# pre checks if the buffer needs to be filled with new data
	def pre(self):
		if self.p >= len(self.buf): # If the current position is at or beyond the buffer length
			self.readLine() # Read a new line into the buffer
			self.p = 0 # Reset the position to the start of the buffer

	# readLine reads a line from the input and fills the buffer
	def readLine(self):
		self.buf = "" # Reset the buffer
		for {
			l, p, e = self.r.ReadLine() # Read a line from the buffered reader
			if e!= None:
				raise e # Panic if there is an error
			self.buf += l # Append the line to the buffer
			if not p: # If the line is not partial
				break # Exit the loop
		}

# IntMax returns the maximum of two integers
def IntMax(a, b):
	if a < b:
		return b # Return b if it is greater
	return a # Otherwise, return a

# Int64Max returns the maximum of two int64 values
def Int64Max(a, b):
	if a < b:
		return b # Return b if it is greater
	return a # Otherwise, return a

# Float64Max returns the maximum of two float64 values
def Float64Max(a, b):
	if a < b:
		return b # Return b if it is greater
	return a # Otherwise, return a

# IntMin returns the minimum of two integers
def IntMin(a, b):
	if a > b:
		return b # Return b if it is smaller
	return a # Otherwise, return a

# Int64Min returns the minimum of two int64 values
def Int64Min(a, b):
	if a > b:
		return b # Return b if it is smaller
	return a # Otherwise, return a

# Float64Min returns the minimum of two float64 values
def Float64Min(a, b):
	if a > b:
		return b # Return b if it is smaller
	return a # Otherwise, return a

# IntGcd computes the greatest common divisor of two integers
def IntGcd(a, b):
	if a < b:
		b, a = a, b # Ensure a is the larger number
	if b == 0:
		return a # If b is zero, return a
	return IntGcd(b, a%b) # Recursive call to find GCD

# Int64Gcd computes the greatest common divisor of two int64 values
def Int64Gcd(a, b):
	if a < b:
		b, a = a, b # Ensure a is the larger number
	if b == 0:
		return a # If b is zero, return a
	return Int64Gcd(b, a%b) # Recursive call to find GCD

# IntAbs returns the absolute value of an integer
def IntAbs(a):
	if a < 0:
		a *= -1 # Negate if a is negative
	return a # Return the absolute value

# Int64Abs returns the absolute value of an int64
def Int64Abs(a):
	if a < 0:
		a *= -1 # Negate if a is negative
	return a # Return the absolute value

# NewFastScanner initializes and returns a new FastScanner
def NewFastScanner():
	return FastScanner()

if __name__ == "__main__":
	main()

