# Helper function to print output.
def out(*args, **kwargs):
	print(*args, **kwargs)

# Scanner to read input from standard input.
import sys

class MyScanner(object):
	def __init__(self):
		self.buf = ""
		self.pos = 0

	def scan(self):
		while True:
			if self.pos >= len(self.buf):
				self.buf = sys.stdin.readline()
				self.pos = 0
			if self.pos < len(self.buf):
				if self.buf[self.pos] == " ":
					self.pos += 1
				else:
					break
		if self.pos >= len(self.buf):
			return None
		i = self.pos
		while i < len(self.buf):
			if self.buf[i] == " ":
				break
			i += 1
		r = self.buf[self.pos:i]
		self.pos = i
		return r

	def split(self, sep=None, maxsplit=-1):
		r = self.scan()
		if r == None:
			return None
		return r.split(sep, maxsplit)

# Function to read an integer from input.
def getInt():
	return int(sc.scan())

# Function to read a string from input.
def getString():
	return sc.scan()

# Function to return the maximum of two integers.
def max(a, b):
	if a > b:
		return a
	return b

# Function to return the minimum of two integers.
def min(a, b):
	if a < b:
		return a
	return b

# Function to return the absolute difference between two integers.
def asub(a, b):
	if a > b:
		return a - b
	return b - a

# Function to return the absolute value of an integer.
def abs(a):
	if a >= 0:
		return a
	return -a

# Function to find the lower bound index of a value in a sorted array.
def lowerBound(a, x):
	idx = bisect.bisect_left(a, x)
	return idx

# Function to find the upper bound index of a value in a sorted array.
def upperBound(a, x):
	idx = bisect.bisect_right(a, x)
	return idx

# Struct to represent a shop with its price and stock.
class shop(object):
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Slice of shops to implement sorting.
class Datas(object):
	def __init__(self, a):
		self.a = a

	def __len__(self):
		return len(self.a)

	def __getitem__(self, i):
		return self.a[i]

	def __setitem__(self, i, v):
		self.a[i] = v

	def __delitem__(self, i):
		del self.a[i]

	def __iter__(self):
		return iter(self.a)

	def __reversed__(self):
		return reversed(self.a)

	def __contains__(self, x):
		return x in self.a

	def __add__(self, x):
		return self.a + x

	def __iadd__(self, x):
		self.a += x
		return self

	def __mul__(self, n):
		return self.a * n

	__rmul__ = __mul__

	def __imul__(self, n):
		self.a *= n
		return self

	def append(self, x):
		self.a.append(x)

	def insert(self, i, x):
		self.a.insert(i, x)

	def pop(self, i=-1):
		return self.a.pop(i)

	def remove(self, x):
		self.a.remove(x)

	def count(self, x):
		return self.a.count(x)

	def index(self, x, i=0, j=None):
		return self.a.index(x, i, j)

	def reverse(self):
		self.a.reverse()

	def sort(self, cmp=None, key=None, reverse=False):
		self.a.sort(cmp, key, reverse)

	def __repr__(self):
		return repr(self.a)

	def __str__(self):
		return str(self.a)

	def __lt__(self, x):
		return self.a < x

	def __le__(self, x):
		return self.a <= x

	def __eq__(self, x):
		return self.a == x

	def __ne__(self, x):
		return self.a!= x

	def __gt__(self, x):
		return self.a > x

	def __ge__(self, x):
		return self.a >= x

# Main function to execute the program logic.
def main():
	# Read the number of shops and the amount of items to buy.
	N, M = getInt(), getInt()

	# Create a slice of shops and read each shop's price and stock.
	s = Datas([shop(0, 0) for i in range(N)])
	for i in range(N):
		a, b = getInt(), getInt()
		s[i] = shop(a, b)

	# Sort the shops by price.
	s.sort(key=lambda e: e.a)

	# Calculate the total cost of buying the required number of items.
	total = 0
	for e in s:
		# Determine the number of items to buy from the current shop.
		n = min(e.b, M)
		# Update the total cost and the remaining items to buy.
		total += n * e.a
		M -= n
		# Break if all items are bought.
		if M == 0:
			break

	# Print the total cost.
	out(total)

# Entry point of program.
if __name__ == "__main__":
	# Create a scanner to read input.
	sc = MyScanner()
	# Call the main function.
	main()

