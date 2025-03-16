import sys

# Initialize scanner and read the first line
def init():
	sc = scanner{
		buf: make([]string, 0, 0),
		cur: 0,
		r:   bufio.NewReader(os.Stdin),
	}
	sc.readln() # Read the first line

# Main function
def main():
	# Read the first two integers from the input
	AB = sc.nextInts()
	A = AB[0]
	B = AB[1]

	# Check if the sum of A and B is even
	if (A+B)%2 == 0:
		# If it is, print the result (the average)
		print((A + B) / 2)
		return
	# If the sum is odd, print "IMPOSSIBLE"
	print("IMPOSSIBLE")

# scanner type definition
class scanner:
	def __init__(self):
		self.buf = []
		self.cur = 0
		self.r = bufio.NewReader(os.Stdin)

	# Function to read a line
	def readln(self):
		rbuf = make([]byte, 0, 0)
		for {
			line, prefix, err := self.r.ReadLine()
			if err!= nil:
				panic(err)
			}
			rbuf = append(rbuf, line...)
			if prefix == False:
				break
		}
		self.cur = 0
		self.buf = strings.Split(*(*string)(unsafe.Pointer(&rbuf)), " ")

	# Function to check if the scanner is full
	def isFull(self):
		if self.cur == len(self.buf):
			return True
		return False

	# Function to reset the current index
	def resetCur(self):
		self.cur = 0

	# Function to read next string
	def next(self):
		if self.cur == 0:
			self.readln()
		res = self.buf[self.cur]
		self.cur += 1
		if self.isFull():
			self.resetCur()
		return res

	# Function to read next integers
	def nextInts(self):
		self.readln()
		res = make([]int, len(self.buf))
		for i in range(len(self.buf)):
			res[i], _ = strconv.Atoi(self.buf[i])
		self.resetCur()
		return res

# Function to calculate the number of digits in an integer
def digits(x):
	return len(str(x))

# Function to calculate the power of a number
def powInt(x, p):
	result = 1
	for i in range(p):
		result *= x
	return result

# Function to find the maximum of two integers
def max(x, y):
	return max(x, y)

# Function to find the minimum of two integers
def min(x, y):
	return min(x, y)

# Function to calculate the absolute value of an integer
def abs(x):
	return abs(x)

# Function to print the values of variables
def varDump(value):
	for v in value:
		print(v)

# Function to print "Yes"
def yes():
	print("Yes")

# Function to print "No"
def no():
	print("No")

# Pair type definition
class Pair:
	def __init__(self, first, second):
		self.first = first
		self.second = second

# Queue type definition
class Queue:
	def __init__(self):
		self.v = []

	# Function to push a pair into the queue
	def Push(self, v):
		self.v.append(v)

	# Function to pop a pair from the queue
	def Pop(self):
		r = self.v[0]
		self.v = self.v[1:]
		return r

	# Function to get the front pair from the queue
	def Front(self):
		return self.v[0]

	# Function to check if the queue is empty
	def Empty(self):
		return len(self.v) == 0

