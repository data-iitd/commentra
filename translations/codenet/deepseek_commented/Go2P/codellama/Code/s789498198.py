
# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	"unsafe"
)

# Main function of the program
def main():
	# Read two integers A and B from standard input
	AB = sc.nextInts()
	A = AB[0]
	B = AB[1]

	# Check if the sum of A and B is even
	if (A+B)%2 == 0:
		# If even, print the average of A and B
		print((A + B) / 2)
		return
	# If not even, print "IMPOSSIBLE"
	print("IMPOSSIBLE")

# Initialize the scanner with default settings
sc = scanner()

# Scanner type for reading input efficiently
class scanner:
	def __init__(self):
		self.buf = []
		self.cur = 0
		self.r = bufio.Reader(sys.stdin)

	# Read a line of input and split it into tokens
	def readln(self):
		rbuf = []
		while True:
			line, prefix, err = self.r.readline()
			if err != None:
				raise err
			rbuf.extend(line)
			if prefix == False:
				break
		self.cur = 0
		self.buf = str(rbuf, "utf-8").split(" ")

	# Check if the current cursor position is beyond the buffer length
	def isFull(self):
		if self.cur == len(self.buf):
			return True
		return False

	# Reset the cursor position to the beginning of the buffer
	def resetCur(self):
		self.cur = 0

	# Get the next token from the buffer
	def next(self):
		if self.cur == 0:
			self.readln()
		res = self.buf[self.cur]
		self.cur += 1
		if self.isFull():
			self.resetCur()
		return res

	# Get all remaining tokens as a slice of strings
	def nexts(self):
		self.readln()
		self.resetCur()
		return self.buf

	# Get the next token as an integer
	def nextInt(self):
		if self.cur == 0:
			self.readln()
		res = int(self.buf[self.cur])
		self.cur += 1
		if self.isFull():
			self.resetCur()
		return res

	# Get all remaining tokens as a slice of integers
	def nextInts(self):
		self.readln()
		res = []
		for i in range(len(self.buf)):
			res.append(int(self.buf[i]))
		self.resetCur()
		return res

	# Get the next token as a float
	def nextFloat(self):
		if self.cur == 0:
			self.readln()
		res = float(self.buf[self.cur])
		self.cur += 1
		if self.isFull():
			self.resetCur()
		return res

	# Get all remaining tokens as a slice of floats
	def nextFloats(self):
		self.readln()
		res = []
		for i in range(len(self.buf)):
			res.append(float(self.buf[i]))
		self.resetCur()
		return res

	# Calculate the number of digits in an integer
	def digits(x):
		return len(str(x))

	# Calculate x raised to the power of p
	def powInt(x, p):
		result = 1
		for i in range(p):
			result *= x
		return result

	# Return the maximum of two integers
	def max(x, y):
		return max(x, y)

	# Return the minimum of two integers
	def min(x, y):
		return min(x, y)

	# Return the absolute value of an integer
	def abs(x):
		return abs(x)

	# Print the variable in a debug-friendly format
	def varDump(value):
		print(value)

	# Print "Yes" to standard output
	def yes():
		print("Yes")

	# Print "No" to standard output
	def no():
		print("No")

	# Pair struct to hold two integers
	class Pair:
		def __init__(self, first, second):
			self.first = first
			self.second = second

	# Queue struct to hold a slice of Pairs
	class Queue:
		def __init__(self):
			self.v = []

		# Push a Pair onto the queue
		def Push(self, v):
			self.v.append(v)

		# Pop a Pair from the front of the queue
		def Pop(self):
			r = self.v[0]
			self.v = self.v[1:]
			return r

		# Get the front Pair of the queue without removing it
		def Front(self):
			return self.v[0]

		# Check if the queue is empty
		def Empty(self):
			return len(self.v) == 0

# Go:
if __name__ == "__main__":
	main()

# 