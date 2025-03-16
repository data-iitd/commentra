# Package main is the entry point of the program
import (
	"bufio" # Import bufio package for reading input
	"fmt"   # Import fmt package for printing output
	"log"   # Import log package for error handling
	"math"  # Import math package for mathematical operations
	"math/rand" # Import math/rand package for random number generation
	"os"    # Import os package for interacting with the operating system
	"strconv" # Import strconv package for converting strings to numbers
	"time"   # Import time package for time-related functions
)

# Constants and variables declaration
# const inf = math.MaxInt64 # Unused constant, can be removed

# var mod = 1000000007 # Unused constant, can be removed

dx = [0, 1, 1, 1, 0, -1, -1, -1, 0] # 8 directions for movement
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

# Global variables declaration
next = Scanner() # Global scanner for reading input

# ---------------------------------------------------------

# init function initializes the program
def init():
	log.SetFlags(log.Lshortfile) # Set log flags for short file names
	rand.seed(time.time()) # Seed random number generator with current time

# main function is the entry point of the program
def main():
	# Read input N as a string
	N = next.String()
	# Convert N to an integer
	b = []byte(N)
	n = 0
	# Iterate through each digit in the number N
	for i in range(len(b)):
		n += int(b[i] - '0') # Convert each digit to an integer and add to the sum
	# Read input m as an integer
	m = int(N)
	# Check if m is divisible by n
	if m%n == 0:
		print("Yes") # Print "Yes" if m is divisible by n
	else:
		print("No") # Print "No" if m is not divisible by n

# ---------------------------------------------------------

# Pair type definition for storing two integers
class Pair:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Pairs type definition for storing a slice of Pair
class Pairs(list):
	def __init__(self, l):
		list.__init__(self, l)
	def Len(self):
		return len(self)
	def Swap(self, i, j):
		self[i], self[j] = self[j], self[i]
	def Less(self, i, j):
		return self[i].b < self[i].b # Sort based on the second element

# ------int methods-------------------------
def in(c, a, z):
	return c >= a and c < z # Check if c is within the range [a, z)
def out(c, a, z):
	return not in(c, a, z) # Check if c is outside the range [a, z)
def btoi(b):
	if b:
		return 1 # Convert boolean to integer: 1 for true, 0 for false
	return 0
def itob(a):
	return a!= 0 # Convert integer to boolean: true for non-zero, false for zero
def max(a, b):
	if a > b:
		return a # Return the maximum integer among the given integers
	return b
def min(a, b):
	if a < b:
		return a # Return the minimum integer among the given integers
	return b
def sum(a):
	r = 0
	for i in range(len(a)):
		r += a[i] # Calculate the sum of all integers in the given slice
	return r
def pro(a):
	r = a[0]
	for i in range(1, len(a)):
		r *= a[i] # Calculate the product of all integers in the given slice
	return r

def fill(a, n):
	for i in range(len(a)):
		a[i] = n # Fill the given slice with the given integer value
	return a
def minmax(a, b):
	if a > b:
		return b, a # Return the minimum and maximum integers among the given integers
	return a, b

def abs(a):
	if a < 0:
		return -a # Calculate the absolute value of an integer
	return a

# ---------- buffered scanner -----------------------------------------
class Scanner:
	def __init__(self):
		self.r = bufio.NewReaderSize(os.Stdin, 10000) # Initialize a new bufio.Reader with a buffer size of 10000
	def next(self):
		self.pre()
		start = self.p
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] =='':
				break # Find the position of the next whitespace character
		result = string(self.buf[start:self.p]) # Extract the substring from the buffer
		self.p++ # Increment the position in the buffer
		return result
	def Line(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		result = string(self.buf[start:]) # Extract the rest of the line as a string
		return result
	def String(self):
		return self.next() # Call next() method to read the next token as a string
	def Int(self):
		v, err = strconv.Atoi(self.next()) # Convert the next token to an integer
		if err!= nil:
			log.Fatal(err) # Log an error and exit the program if the conversion fails
		return v
	def Ints(self, n):
		r = make([]int, n) # Initialize an empty slice of integers with the given size
		for i in range(n):
			r[i] = self.Int() # Read and store n integers in the slice
		return r
	def Int64(self):
		v, err = strconv.ParseInt(self.next(), 10, 64)
		if err!= nil:
			log.Fatal(err)
		return v
	def Uint64(self):
		v, err = strconv.ParseUint(self.next(), 10, 64)
		if err!= nil:
			log.Fatal(err)
		return v
	def Float64(self):
		v, err = strconv.ParseFloat(self.next(), 64)
		if err!= nil:
			log.Fatal(err)
		return v
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine() # Read a new line if the buffer is empty
			self.p = 0
	def readLine(self):
		self.buf = make([]byte, 0) # Clear the buffer
		for {
			l, p, err = self.r.ReadLine()
			if err!= nil:
				log.Fatal(err) # Log an error and exit the program if an error occurs during reading
			self.buf = append(self.buf, l...) # Append the read line to the buffer
			if not p:
				break # Exit the loop if the end of the input is reached
		}

