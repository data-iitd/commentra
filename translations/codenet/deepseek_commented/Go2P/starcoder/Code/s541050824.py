import sys

# bufReader class definition
# This class is designed to efficiently read lines from standard input.
# It uses a buffer to minimize the number of system calls.
class bufReader:
	def __init__(self):
		self.buf = ""
		self.i = 0

	def readLine(self):
		if self.i < len(self.buf):
			return
		self.buf = ""
		self.i = 0
		for line in sys.stdin:
			self.buf += line
			if line[-1] == '\n':
				break

	def next(self):
		self.readLine()
		from_i = self.i
		while self.i < len(self.buf) and self.buf[self.i]!='':
			self.i += 1
		to_i = self.i
		self.i += 1
		return self.buf[from_i:to_i]

	def nextLine(self):
		self.readLine()
		from_i = self.i
		self.i = len(self.buf)
		return self.buf[from_i:]

# bufReader initialization
reader = bufReader()

# next wraps the reader.next() function.
def next():
	return reader.next()

# nextInt reads the next token as an integer.
def nextInt():
	return int(next())

# nextLine wraps the reader.nextLine() function.
def nextLine():
	return reader.nextLine()

# out prints the arguments to the output with a newline.
def out(a):
	print(a)

# max returns the maximum of two integers.
def max(x, y):
	if x > y:
		return x
	return y

# min returns the minimum of two integers.
def min(x, y):
	if x < y:
		return x
	return y

# joinInts joins an array of integers into a string with a separator.
def joinInts(a, sep):
	b = []
	for v in a:
		b.append(str(v))
	return sep.join(b)

# divUp returns the ceiling of the division of x by y.
def divUp(x, y):
	return (x + y - 1) // y

# Main function
def main():
	solve()

# Solve function
# Reads the number of elements N.
# Reads N pairs of integers T and A.
# Iteratively adjusts t and a to ensure the ratios are maintained.
# Outputs the sum of t and a after all adjustments.
def solve():
	N = nextInt()
	T, A = [], []
	for i in range(N):
		T.append(nextInt())
		A.append(nextInt())
	t, a = T[0], A[0]
	for i in range(1, N):
		r = max(divUp(t, T[i]), divUp(a, A[i]))
		t, a = T[i]*r, A[i]*r
	out(t + a)

# 