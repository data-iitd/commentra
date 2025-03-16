# Importing necessary packages
import sys
import math

# Constants and variables declaration
inf = 1e14

# Function to read input from standard input using buffered reader
class reader:
	def __init__(self):
		self.r = sys.stdin

	def __iter__(self):
		return self

	def __next__(self):
		if self.r is None:
			raise StopIteration
		line = self.r.readline()
		if not line:
			self.r = None
			raise StopIteration
		return line.strip()

# Function to read input from standard input using buffered reader
def new_reader():
	return reader()

# Function to read next token from input
def next(s):
	return s.__next__()

# Function to read a complete line from input
def line(s):
	return s.__next__()

# Function to read an integer from input
def int_(s):
	return int(s.__next__())

# Function to read an integer64 from input
def int64(s):
	return int(s.__next__())

# Function to set the position of the reader to the beginning of the buffer
def pre(s):
	pass

# Function to read a complete line from input and store it in the buffer
def read_line(s):
	pass

# Main function
def main():
	# Setting up logging
	log.set_flags(log.Lshortfile)

	# Creating a new scanner object
	next = new_reader()

	# Reading input
	n = int_(next(next))
	x = int_(next(next))

	# Initializing arrays
	a = [0] * n
	v = [0] * n
	copy(v, a)

	# Initializing answer variable
	ans = inf

	# Iterating through all possible subarrays
	for k in range(n):
		# Initializing variable to store sum of subarray elements
		kans = 0

		# Iterating through all elements of the subarray
		for i in range(n):
			# Checking if current index is out of bounds for subarray
			if i-k < 0:
				# Updating current element in subarray with minimum of itself and corresponding element from the main array
				v[i] = min(v[i], a[n+i-k])
			else:
				# Updating current element in subarray with minimum of itself and previous element in subarray
				v[i] = min(v[i], a[i-k])

			# Adding current element to the sum of subarray
			kans += v[i]
		# Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
		ans = min(ans, kans+k*x)
	# Printing the answer
	print(ans)

# Helper functions
def min(a, b):
	if a < b:
		return a
	return b

# -------------------------------
# Function to check if a given number is inside a given range
def in(c, a, z):
	return c >= a and c < z

# Function to convert boolean value to integer
def btoi(b):
	if b:
		return 1
	return 0

# Function to convert integer value to boolean
def itob(a):
	if a == 0:
		return False
	return True

# 