import sys
import math
import random

# ---------------------------------------------------------
# init function to set up logging and random seed
def init():
	log.SetFlags(log.Lshortfile) # Set log flags to show file name and line number
	random.seed(time.Now().UnixNano()) # Seed the random number generator

# ---------------------------------------------------------
# main function where the program execution starts
def main():
	# Read input as a string
	N = next.String()
	b = []byte(N) # Convert string to byte slice
	n = 0 # Initialize sum of digits

	# Calculate the sum of digits in the input number
	for i in range(len(b)):
		n += int(b[i] - '0') # Convert byte to int and accumulate

	# Convert the string input to an integer
	m, _ = int(N), None
	# Check if the number is divisible by the sum of its digits
	if m%n == 0:
		print("Yes") # Print "Yes" if divisible
	else:
		print("No") # Print "No" if not divisible

# ---------------------------------------------------------

# Pair struct to hold a pair of integers
class Pair:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Pairs is a slice of Pair structs
class Pairs(list):
	def __init__(self, l):
		list.__init__(self, l)
	def Len(self):
		return len(self)
	def Swap(self, i, j):
		self[i], self[j] = self[j], self[i]
	def Less(self, i, j):
		return self[i].b < self[j].b

# Utility functions for various operations

# Check if a value is within a range
def in(c, a, z):
	return c >= a and c < z

# Check if a value is outside a range
def out(c, a, z):
	return not in(c, a, z)

# Convert boolean to integer (1 for true, 0 for false)
def btoi(b):
	if b:
		return 1
	return 0

# Convert integer to boolean (non-zero to true, zero to false)
def itob(a):
	return a!= 0

# Return the maximum value from a list of integers
def max(a):
	r = a[0]
	for i in range(len(a)):
		if r < a[i]:
			r = a[i]
	return r

# Return the minimum value from a list of integers
def min(a):
	r = a[0]
	for i in range(len(a)):
		if r > a[i]:
			r = a[i]
	return r

# Calculate the sum of a slice of integers
def sum(a):
	r = 0
	for i in range(len(a)):
		r += a[i]
	return r

# Calculate the product of a slice of integers
def pro(a):
	r = a[0]
	for i in range(1, len(a)):
		r *= a[i]
	return r

# Fill a slice with a specified value
def fill(a, n):
	for i in range(len(a)):
		a[i] = n
	return a

# Return the minimum and maximum of two integers
def minmax(a, b):
	if a > b:
		return b, a
	return a, b

# Return the absolute value of an integer
def abs(a):
	if a < 0:
		return -a
	return a

# Calculate the ceiling of a division of two integers
def ceil(a, b):
	if a%b!= 0:
		return 1
	return 0

# Print a slice of strings with space separation
def printStrings(out):
	for i in range(len(out)):
		print(out[i], end=" ")
	print()

# Print a slice of integers with space separation
def printInts(out):
	for i in range(len(out)):
		print(out[i], end=" ")
	print()

# ---------- buffered reader -----------------------------------------

# buffered reader struct for buffered input reading
class bufferedReader:
	def __init__(self, rdr, bufsize):
		self.r = rdr
		self.buf = []
		self.p = 0
		self.bufsize = bufsize
	def next(self):
		self.pre() # Ensure the buffer is filled
		start = self.p # Mark the start of the token
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] =='': # Stop at space
				break
		result = string(self.buf[start:self.p]) # Extract the token
		self.p++ # Move past the space
		return result
	def Line(self):
		self.pre() # Ensure the buffer is filled
		start = self.p # Mark the start of the line
		self.p = len(self.buf) # Move to the end of the buffer
		return string(self.buf[start:]) # Return the line
	def String(self):
		return self.next() # Call next to get the next token
	def Int(self):
		v, err = int(self.next()), None # Convert the next token to an integer
		if err!= None:
			log.Fatal(err) # Log error if conversion fails
		return v # Return the integer
	def Ints(self, n):
		r = make([]int, n) # Create a slice to hold the integers
		for i in range(n):
			r[i] = self.Int() # Read each integer
		return r # Return the slice of integers
	def Int64(self):
		v, err = int(self.next()), None # Convert the next token to int64
		if err!= None:
			log.Fatal(err) # Log error if conversion fails
		return v # Return the int64
	def Uint64(self):
		v, err = int(self.next()), None # Convert the next token to uint64
		if err!= None:
			log.Fatal(err) # Log error if conversion fails
		return v # Return the uint64
	def Float64(self):
		v, err = float(self.next()), None # Convert the next token to float64
		if err!= None:
			log.Fatal(err) # Log error if conversion fails
		return v # Return the float64
	def pre(self):
		if self.p >= len(self.buf): # If current position is at the end of the buffer
			self.readLine() # Read a new line
			self.p = 0 # Reset position to the start of the new buffer
	def readLine(self):
		self.buf = make([]byte, 0) # Reset the buffer
		for {
			l, p, err = self.r.ReadLine() # Read a line
			if err!= None:
				log.Fatal(err) # Log error if reading fails
			self.buf = append(self.buf, l...) # Append line to buffer
			if not p: # If the line is complete
				break
		}

# ---------------------------------------------------------

# Create a new scanner instance
next = bufferedReader(sys.stdin, 10000)

# Call the main function
init()
main()

# 