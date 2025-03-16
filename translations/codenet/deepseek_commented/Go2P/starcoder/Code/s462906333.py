import sys

# const abcd = "abcdefghijklnmopqrstuvwxyz"
# const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# var dy = [...]int{1, 1, 0, -1, -1, -1, 0, 1}
# var dx = [...]int{0, 1, 1, 1, 0, -1, -1, -1}

# var dx = [...]int{0, 1, 0, -1}
# var dy = [...]int{1, 0, -1, 0}

# var inf int = 1e14 # Define a large value to represent infinity for cost comparisons

# # var mod = 1000000007

# ---------------------------------------------------------
def main():
	# log.SetFlags(log.Lshortfile) # Set logging to include file names in error messages
	next := newScanner()         # Create a new scanner for input
	n = next.Int()              # Read the number of elements
	x = next.Int()              # Read some parameter x
	a = make([]int, n)          # Initialize the array a with size n
	for i in range(n):
		a[i] = next.Int() # Fill the array a with integers from input
	v = make([]int, n)          # Create a copy of array a named v
	copy(v, a)                  # Copy the contents of a to v
	ans = inf                   # Initialize the answer with a large value
	for k in range(n):     # Iterate over possible values of k
		kans = 0                 # Initialize the temporary answer for the current k
		for i in range(n):  # Iterate over each element in the array
			if i-k < 0:          # If the index is out of bounds, wrap around
				v[i] = min(v[i], a[n+i-k]) # Update the value in v
			else:
				v[i] = min(v[i], a[i-k]) # Update the value in v
			kans += v[i] # Add the updated value to the temporary answer
		ans = min(ans, kans+k*x) # Update the final answer with the minimum cost
	print(ans) # Print the minimum cost found

# ---------------------------------------------------------

# Pair is liked C++ pair
class Pair:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Pairs is sorted by []Pair struct
class Pairs(list):
	def __init__(self, a):
		list.__init__(self, a)
	def __lt__(self, other):
		return self.a < other.a or (self.a == other.a and self.b < other.b)

# -------------------------------
def in(c, a, z):
	return c >= a and c < z

def btoi(b):
	if b:
		return 1
	return 0

def itob(a):
	if a == 0:
		return False
	return True

def max(a, b):
	if a > b:
		return b
	return a

def min(a, b):
	if a < b:
		return b
	return a

def minmax(a, b):
	if a > b:
		return b, a
	return a, b

def abs(a):
	if a < 0:
		return -a
	return a

def sum(a, b):
	return a + b

# ---------- buffered scanner -----------------------------------------
class scanner:
	def __init__(self):
		self.r = bufio.NewReaderSize(os.Stdin, 10000)
		self.buf = ""
		self.p = 0
	def next(self):
		self.pre()
		start = self.p
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] =='':
				break
		result = self.buf[start:self.p]
		self.p += 1
		return result
	def Line(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		return self.buf[start:]
	def Int(self):
		v, _ = strconv.Atoi(self.next())
		return v
	def Int64(self):
		v, _ = strconv.ParseInt(self.next(), 10, 64)
		return v
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine()
			self.p = 0
	def readLine(self):
		self.buf = ""
		for {
			l, p, e := self.r.ReadLine()
			if e!= nil:
				panic(e)
			self.buf += string(l)
			if not p:
				break
		}

# 