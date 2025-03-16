# Initialize logger to include short file names
import logging
logging.basicConfig(format='%(filename)s:%(lineno)d %(message)s', level=logging.DEBUG)

# Create a new scanner to read input
def newScanner():
	return bufio.Scanner(sys.stdin)

# Function to return the maximum of two integers
def max(a, b):
	if a > b:
		return a
	return b

# Custom scanner struct to read input
class scanner:
	def __init__(self):
		self.s = bufio.Scanner(sys.stdin)
	def next(self):
		self.s.next()
		return self.s.token()
	def nextInt(self):
		return int(self.next())
	def nextLine(self):
		return self.s.nextLine()

# Function to create a new scanner
def newScanner():
	return scanner()

# Function to read the next word
def next(s):
	s.next()
	return s.token()

# Function to read the next line
def nextLine(s):
	return s.nextLine()

# Function to read the next integer
def nextInt(s):
	return int(s.next())

# Function to preprocess the buffer
def pre(s):
	if s.s.p >= len(s.s.buf):
		s.readLine()
		s.s.p = 0

# Function to read a line from the input
def readLine(s):
	s.s.buf = []
	for s.s.p < len(s.s.buf):
		l, p, e = s.s.r.ReadLine()
		if e!= None:
			raise e
		s.s.buf.append(l)
		if not p:
			break

# Define an array containing three slices, each representing a group of months with the same number of days
a = [ [1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2] ]

# Iterate over the array to determine which group each of the integers belongs to
for i, t in enumerate(a):
	for n in t:
		# logging.debug(n) # Uncomment to log each number in the array
		if x == n:
			xt = i
		if y == n:
			yt = i

# Compare the groups of x and y to determine if they belong to the same group
if xt == yt:
	print("Yes")
else:
	print("No")

# 