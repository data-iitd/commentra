# Package main is the entry point of the program

import (
	# bufio package is used for reading and writing lines from/to I/O streams
	"bufio"
	# fmt package is used for formatted I/O
	"fmt"
	# math package is used for mathematical operations
	"math"
	# os package is used for interacting with the operating system
	"os"
	# re package is used for regular expression matching
	"re"
	# strconv package is used for converting between string and numeric types
	"strconv"
	# strings package is used for string manipulation
	"strings"
)

# bufReader type is a custom reader that reads lines from os.Stdin
class bufReader:
	# bufio.Reader instance
	r = None
	# buffer for storing read lines
	buf = None
	# index for the current position in the buffer
	i = 0

	# Constructor for the bufReader class
	def __init__(self):
		# Initialize bufio.Reader
		self.r = bufio.NewReader(os.Stdin)
		# Initialize empty buffer
		self.buf = ""
		# Initialize index to 0
		self.i = 0

	# Function readLine reads a line from os.Stdin and stores it in the buffer
	def readLine(self):
		# If the index is less than the length of the buffer, it means that there is still some data left in the buffer
		if self.i < len(self.buf):
			return
		# Clear the buffer and set the index to 0
		self.buf = ""
		self.i = 0
		# Read a line from os.Stdin and store it in the buffer
		for {
			line, isPrefix, err := self.r.ReadLine()
			# If an error occurs during reading, panic with the error message
			if err!= None:
				panic(err)
			# If the line is not a prefix (i.e., it is a complete line), break the loop
			if not isPrefix:
				break
			# Append the line to the buffer
			self.buf += line
		}

	# Function next returns the next token (i.e., a word or a number) from the buffer
	def next(self):
		# Read a line from the buffer
		self.readLine()
		# Find the index of the first whitespace character in the line
		from = self.i
		# Iterate through the line until a whitespace character is found
		for ; self.i < len(self.buf); self.i++:
			# If the current character is a whitespace character, break the loop
			if self.buf[self.i] =='':
				break
		# Return the substring from the start index to the current index
		s = self.buf[from:self.i]
		# Increment the index
		self.i++
		# Return the token
		return s

	# Function nextLine returns the next line from the buffer
	def nextLine(self):
		# Read a line from the buffer
		self.readLine()
		# Return the substring from the current index to the end of the buffer
		s = self.buf[self.i:]
		# Set the index to the end of the buffer
		self.i = len(self.buf)
		# Return the line
		return s

# bufio.NewWriter is used for writing lines to os.Stdout
writer = bufio.NewWriter(os.Stdout)

# Function next returns the next token (i.e., a word or a number) from the custom reader
def next():
	# Call the next function of the custom reader and return the result
	return reader.next()

# Function nextInt64 parses an integer from the custom reader and returns it as an int64 type
def nextInt64():
	# Parse an integer from the custom reader and return it as an int64 type
	i, err = strconv.ParseInt(reader.next(), 10, 64)
	# If an error occurs during parsing, panic with the error message
	if err!= None:
		panic(err)
	# Return the integer
	return i

# Function nextInt parses an integer from the custom reader and returns it as an int type
def nextInt():
	# Parse an integer from the custom reader and return it as an int type
	return int(nextInt64())

# Function nextLine reads a line from the custom reader and returns it as a string
def nextLine():
	# Read a line from the custom reader and return it as a string
	return reader.nextLine()

# Function out is used for printing output to the console
def out(a):
	# Write the formatted output to the bufio.Writer
	fmt.Fprintln(writer, a)

# Function max64 returns the maximum of two int64 values
def max64(x, y):
	# If x is greater than y, return x; otherwise, return y
	if x > y:
		return x
	return y

# Function max returns the maximum of two int values
def max(x, y):
	# Return the maximum of x and y as an int value
	return int(max64(x, y))

# Function min64 returns the minimum of two int64 values
def min64(x, y):
	# If x is less than y, return x; otherwise, return y
	if x < y:
		return x
	return y

# Function min returns the minimum of two int values
def min(x, y):
	# Return the minimum of x and y as an int value
	return int(min64(x, y))

# Function abs64 returns the absolute value of an int64 value
def abs64(x):
	# If x is negative, return the negative of x; otherwise, return x
	if x < 0:
		return -x
	return x

# Function abs returns the absolute value of an int value
def abs(x):
	# Return the absolute value of x as an int value
	return int(abs64(x))

# Function joinInt64s joins an array of int64 values with a given separator and returns the resulting string
def joinInt64s(a, sep):
	# Create a slice of strings by converting each int64 value to a string
	b = []
	for v in a:
		b.append(str(v))
	# Join the strings in the slice with the given separator and return the resulting string
	return sep.join(b)

# Function joinInts joins an array of int values with a given separator and returns the resulting string
def joinInts(a, sep):
	# Create a slice of strings by converting each int value to a string
	b = []
	for v in a:
		b.append(str(v))
	# Join the strings in the slice with the given separator and return the resulting string
	return sep.join(b)

# Function divUp64 returns the smallest integer n such that n*divisor >= dividend
def divUp64(x, y):
	# Return the smallest integer n such that n*divisor >= dividend
	return (x + y - 1) / y

# Function divUp returns the smallest integer n such that n*divisor >= dividend
def divUp(x, y):
	# Return the smallest integer n such that n*divisor >= dividend
	return int(divUp64(x, y))

# Function gcd64 returns the greatest common divisor of two int64 values
def gcd64(x, y):
	# If x is greater than y, swap x and y
	if x < y:
		x, y = y, x
	# Iterate through the range of possible divisors
	for y!= 0:
		# Calculate the remainder of x/y
		x, y = y, x % y
	# Return x as the greatest common divisor
	return x

# Function gcd returns the greatest common divisor of two int values
def gcd(x, y):
	# Return the greatest common divisor of x and y as an int value
	return int(gcd64(x, y))

# Function lcm64 returns the least common multiple of two int64 values
def lcm64(x, y):
	# Calculate the greatest common divisor of x and y
	gcd = gcd64(x, y)
	# Return the product of x and y divided by their greatest common divisor
	return x*y / gcd

# Function lcm returns the least common multiple of two int values
def lcm(x, y):
	# Return the least common multiple of x and y as an int value
	return int(lcm64(x, y))

# Function pow64 returns x raised to the power of y as an int64 value
def pow64(x, y):
	# Return x raised to the power of y as an int64 value using the math.Pow function
	return int64(math.Pow(float64(x), float64(y)))

# Function pow returns x raised to the power of y as an int value
def pow(x, y):
	# Return x raised to the power of y as an int value
	return int(pow64(x, y))

# Function main is the entry point of the program
def main():
	# Call the solve function to solve the problem
	solve()
	# Flush the bufio.Writer to write the output to the console
	writer.Flush()

# Function solve reads input from the custom reader, processes it, and writes the output to the bufio.Writer
def solve():
	# Read two integers N and K from the custom reader
	N, K = nextInt(), nextInt()
	# Initialize an array A of size N
	A = [0] * N
	# Read N integers from the custom reader and store them in the array A
	for i in range(N):
		A[i] = nextInt()
	# Initialize variables maxProfit, maxCnt, and maxA
	maxProfit = 0
	maxCnt = 0
	maxA = A[N-1]
	# Iterate through the array A from the last index to the first index
	for i in range(N-2, -1, -1):
		# Calculate the profit of the current transaction
		profit = max(0, maxA-A[i])
		# If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
		if maxProfit < profit:
			maxProfit = profit
			maxCnt = 1
		elif maxProfit == profit:
			maxCnt += 1
		# Update maxA with the maximum of the current element and maxA
		maxA = max(maxA, A[i])
	# Write the output to the console
	out(maxCnt)

